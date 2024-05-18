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
#include "BlurShader.hpp"

namespace tears {
using namespace std;

// kernel size
constexpr int KERNEL_SIZE = 201;
static_assert(KERNEL_SIZE > 0, "kernel size should be positive.");
static_assert(KERNEL_SIZE % 2 == 1, "kernel size should be odd.");
// default sigma
constexpr float DEFAULT_SIGMA = 0.3f * (((float)KERNEL_SIZE - 1.f) * 0.5f - 1.f) + 0.8f;

// default constructor
BlurShader::BlurShader() {}

// destructor
BlurShader::~BlurShader() {}

// load shader
void BlurShader::loadShader() {
    int kHalf = (KERNEL_SIZE - 1) / 2;

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
       << "uniform float uKernelWeights[" << kHalf + 1 << "];"
       << "varying vec2 vTexCoordSrc;"
       << "void main() {"
       << "    vec4 sum = vec4(0.0, 0.0, 0.0, 0.0);"
       << "    for (int i = " << -kHalf << "; i <= " << kHalf << "; i++) {"
       << "        float weight = uKernelWeights[(i >= 0) ? i : -i];"
       << "        vec2 texCoord;"
       << "        if (uIsVertical == 0) {"
       << "            texCoord = vTexCoordSrc.xy + vec2(float(i) / uBboxSizeSrc.x, 0.0);"
       << "        } else {"
       << "            texCoord = vTexCoordSrc.xy + vec2(0.0, float(i) / uBboxSizeSrc.y);"
       << "        }"
       << "        vec4 srcColor = texture2D(uTextureSrc, texCoord);"
       << "        sum += srcColor * weight;"
       << "    }"
       << "    gl_FragColor = sum;"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw blurred texture
void BlurShader::drawBlur(
    int strength,
    Texture* textureSrc,
    const Point texCoordSrc[],
    Size bboxSizeSrc,
    const Point vertices[],
    int count) const {
    vector<float> kernelWeights = calculateKernelWeights(strength);

    auto vertBlurTex = make_unique<Texture>(bboxSizeSrc.width, bboxSizeSrc.height);

    // original → vertical blur
    GLController* gl = GLController::getInstance();
    bindUniformSize("uBboxSizeSrc", bboxSizeSrc, false);
    bindUniformFloatArray("uKernelWeights", (int)kernelWeights.size(), kernelWeights.data());
    {
        FramebufferScope fbs(vertBlurTex.get());
        MatrixStackScope mss;
        mss.getTopMatrix()->setIdentity();
        TextureScope ts(textureSrc, TextureParameterLinear, TextureParameterClampToEdge);
        bindAttributePoints("aTexCoordSrc", texCoordSrc);
        bindUniformTexture("uTextureSrc", ts.getCurrentTextureUnit());
        bindUniformInteger("uIsVertical", 1);

        BlendScope bs(BlendEquationAdd, BlendOne, BlendZero);
        gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
    }
    // vertical blur → vertical + horizontal blur
    {
        TextureScope ts(vertBlurTex.get(), TextureParameterLinear, TextureParameterClampToEdge);
        bindAttributePoints("aTexCoordSrc", Texture::DEFAULT_TEXTURE_COORD);
        bindUniformTexture("uTextureSrc", ts.getCurrentTextureUnit());
        bindUniformInteger("uIsVertical", 0);

        gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
    }
}

// calculate kernel weights of the gaussian blur
vector<float> BlurShader::calculateKernelWeights(int strength) const {
    float minSigma = 1.f;
    float maxSigma = DEFAULT_SIGMA * 2.f;
    float sigma = minSigma + (maxSigma - minSigma) * ((float)strength / 100.f);

    int length = KERNEL_SIZE / 2 + 1;
    vector<float> kernel(length);
    float sum = 0.f;
    for (int i = 0; i < length; i++) {
        float val = expf(-i * i / (2 * sigma * sigma));
        kernel[i] = val;
        sum += (i == 0) ? val : val * 2.f;
    }

    float scale = 1.f / sum;
    for (int i = 0; i < length; i++) {
        kernel[i] *= scale;
    }

    return kernel;
}

}    // namespace tears
