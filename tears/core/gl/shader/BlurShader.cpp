//
//  BlurShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/BlendScope.hpp"
#include "gl/FramebufferScope.hpp"
#include "gl/GLController.hpp"
#include "gl/MatrixStackScope.hpp"
#include "gl/Texture.hpp"
#include "math/Interval.hpp"
#include "utils/DebugUtil.hpp"
#include "BlurShader.hpp"

namespace tears {
using namespace std;

// a minimum value of the kernel size
constexpr int MIN_KERNEL_SIZE = 1;

// default constructor
BlurShader::BlurShader() {}

// destructor
BlurShader::~BlurShader() {}

// load shader
void BlurShader::loadShader() {
    stringstream vs;
    vs << "uniform mat3 uMatrixMVP;"
       << "uniform mat3 uMatrixU;"
       << "attribute vec2 aPosition;"
       << "attribute vec2 aTexCoordSrc;"
       << "varying vec2 vTexCoordSrc;"

       << "void main() {"
       << "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
       << "    vTexCoordSrc = aTexCoordSrc;"
       << "}";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform sampler2D uTextureSrc;"
       << "uniform vec2 uBboxSizeSrc;"
       << "uniform int uIsVertical;"
       << "uniform int uKernelLeft;"
       << "uniform int uKernelRight;"
       << "varying vec2 vTexCoordSrc;"

       << "void main() {"
       << "    vec3 sum = vec3(0.0, 0.0, 0.0);"
       << "    for (int i = uKernelLeft; i <= uKernelRight; i++) {"
       << "        vec2 texCoord;"
       << "        if (uIsVertical == 0) {"
       << "            texCoord = vTexCoordSrc.xy + vec2(float(i) / uBboxSizeSrc.x, 0.0);"
       << "        } else {"
       << "            texCoord = vTexCoordSrc.xy + vec2(0.0, float(i) / uBboxSizeSrc.y);"
       << "        }"
       << "        vec4 texColor = texture2D(uTextureSrc, texCoord);"
       << "        sum += texColor.rgb;"
       << "    }"
       << "    gl_FragColor.rgb = sum / float(uKernelRight - uKernelLeft + 1);"
       << "    gl_FragColor.a = 1.0;"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw blurred texture
void BlurShader::drawBlur(
    float sigma,
    Texture* textureSrc,
    const Point texCoordSrc[],
    Size bboxSizeSrc,
    Texture* textureDst,
    const Point vertices[],
    int count) {
    int kernelSize = calculateKernelSize(sigma);
    if (kernelSize < MIN_KERNEL_SIZE) {    // if kernel size too small
        tears_assert(false);
        return;
    }
    Interval kernelIntervalStrategy[3];
    if (kernelSize % 2 == 0) {    // if kernel size is even
        int half = kernelSize / 2;
        kernelIntervalStrategy[0] = Interval(-half, half - 1);
        kernelIntervalStrategy[1] = Interval(-half - 1, half);
        kernelIntervalStrategy[2] = Interval(-half, half);
    } else {
        int half = (kernelSize - 1) / 2;
        kernelIntervalStrategy[0] = Interval(-half, half);
        kernelIntervalStrategy[1] = Interval(-half, half);
        kernelIntervalStrategy[2] = Interval(-half, half);
    }
    Point intermediateVertices[4] = {
        Point(0.f, 0.f),
        Point(0.f, bboxSizeSrc.height),
        Point(bboxSizeSrc.width, 0.f),
        Point(bboxSizeSrc.width, bboxSizeSrc.height)};
    auto texTmp = make_unique<Texture>(bboxSizeSrc.width, bboxSizeSrc.height);
    float dstWidth = textureDst->getWidth();
    float dstHeight = textureDst->getHeight();
    Point texCoordDst[4] = {
        Point(vertices[0].x / dstWidth, 1.f - vertices[0].y / dstHeight),
        Point(vertices[1].x / dstWidth, 1.f - vertices[1].y / dstHeight),
        Point(vertices[2].x / dstWidth, 1.f - vertices[2].y / dstHeight),
        Point(vertices[3].x / dstWidth, 1.f - vertices[3].y / dstHeight)};

    bindUniformSize("uBboxSizeSrc", bboxSizeSrc, false);

    // 1D blur along X axis
    // src → tmp
    boxBlur1D(
        false,
        kernelIntervalStrategy[0],
        true,
        textureSrc,
        texCoordSrc,
        texTmp.get(),
        intermediateVertices,
        count);
    // tmp → dst
    boxBlur1D(
        false,
        kernelIntervalStrategy[1],
        true,
        texTmp.get(),
        Texture::DEFAULT_TEXTURE_COORD,
        textureDst,
        vertices,
        count);
    // dst → tmp
    boxBlur1D(
        false,
        kernelIntervalStrategy[2],
        true,
        textureDst,
        texCoordDst,
        texTmp.get(),
        intermediateVertices,
        count);

    // 1D blur along Y axis
    // tmp → dst
    boxBlur1D(
        true,
        kernelIntervalStrategy[0],
        true,
        texTmp.get(),
        Texture::DEFAULT_TEXTURE_COORD,
        textureDst,
        vertices,
        count);
    // dst → tmp
    boxBlur1D(
        true,
        kernelIntervalStrategy[1],
        true,
        textureDst,
        texCoordDst,
        texTmp.get(),
        intermediateVertices,
        count);
    // tmp → dst
    boxBlur1D(
        true,
        kernelIntervalStrategy[2],
        false,
        texTmp.get(),
        Texture::DEFAULT_TEXTURE_COORD,
        textureDst,
        vertices,
        count);
}

// calculate kernel size [px]
int BlurShader::calculateKernelSize(float sigma) const {
    float size = floorf(sigma * 3.f * sqrtf(2.f * (float)M_PI) / 4.f + 0.5f);
    return max(1, (int)size);
}

// 1D box blur
void BlurShader::boxBlur1D(
    bool isVertical,
    Interval kernelInterval,
    bool overwriteDst,
    Texture* textureSrc,
    const Point texCoordSrc[],
    Texture* textureDst,
    const Point vertices[],
    int count) {
    FramebufferScope fbs(textureDst);
    MatrixStackScope mss;
    mss.getTopMatrix()->setIdentity();
    TextureScope ts(textureSrc, TextureParameterLinear, TextureParameterClampToEdge);
    bindAttributePoints("aTexCoordSrc", texCoordSrc);
    bindUniformTexture("uTextureSrc", ts.getCurrentTextureUnit());
    bindUniformInteger("uIsVertical", (isVertical) ? 1 : 0);
    bindUniformInteger("uKernelLeft", kernelInterval.left);
    bindUniformInteger("uKernelRight", kernelInterval.right);

    GLController* gl = GLController::getInstance();
    if (overwriteDst) {
        BlendScope bs(BlendEquationAdd, BlendOne, BlendZero);
        gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
    } else {
        gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
    }
}

}    // namespace tears
