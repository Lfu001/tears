//
//  RectangleShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/07/14.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/BlendScope.hpp"
#include "gl/Texture.hpp"
#include "RectangleShader.hpp"

namespace tears {

// default constructor
RectangleShader::RectangleShader() {}

// destructor
RectangleShader::~RectangleShader() {}

// load shader
void RectangleShader::loadShader() {
    stringstream vs;
    vs << "uniform mat3 uMatrixMVP;"
       << "uniform mat3 uMatrixU;"
       << "attribute vec2 aPosition;"
       << "attribute vec2 aTexCoord;"
       << "attribute vec4 aColor;"
       << "varying vec2 vTexCoord;"
       << "varying vec4 vColor;"

       << "void main() {"
       << "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
       << "    vTexCoord = aTexCoord;"
       << "    vColor = aColor;"
       << "}";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform sampler2D uTexture;"
       << "uniform int uUseTexture;"
       << "varying vec2 vTexCoord;"
       << "varying vec4 vColor;"

       << "void main() {"
       << "    if (uUseTexture == 0) {"
       << "        gl_FragColor = vColor;"
       << "    } else {"
       << "        vec4 texColor = texture2D(uTexture, vTexCoord);"
       << "        float outA = mix(texColor.a, 1.0, vColor.a);"
       << "        vec3 outRGB = mix(texColor.rgb * texColor.a, vColor.rgb, vColor.a) / outA;"
       << "        gl_FragColor = vec4(outRGB, outA);"
       << "    }"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw rectangle
void RectangleShader::drawRectangle(
    Texture* textureSrc,
    const Point texCoordSrc[],
    Point vertices[],
    Color colors[],
    int count) const {
    unique_ptr<Texture> dummyTex;
    if (textureSrc) {    // if texture is specified
        bindUniformInteger("uUseTexture", 1);
        bindAttributePoints("aTexCoord", texCoordSrc);
    } else {
        bindUniformInteger("uUseTexture", 0);
        bindAttributePoints("aTexCoord", Texture::DEFAULT_TEXTURE_COORD);
        dummyTex = make_unique<Texture>(1, 1);
    }
    Texture* tex = (dummyTex) ? dummyTex.get() : textureSrc;
    TextureScope ts(tex, TextureParameterLinear, TextureParameterClampToEdge);
    bindUniformTexture("uTexture", ts.getCurrentTextureUnit());

    GLController* gl = GLController::getInstance();
    if (textureSrc) {    // if texture is specified
        // clear the shape area of the dst texture
        Color bt[] = {Color::WHITE, Color::WHITE, Color::WHITE, Color::WHITE};
        bindAttributeColors("aColor", bt);
        BlendScope bs(BlendEquationReverseSubtract, BlendOne, BlendOne);
        gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
    }
    bindAttributeColors("aColor", colors);

    gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
}

}    // namespace tears
