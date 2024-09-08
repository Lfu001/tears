//
//  EllipseShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/01.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/BlendScope.hpp"
#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "EllipseShader.hpp"

namespace tears {

// default constructor
EllipseShader::EllipseShader() {}

// destructor
EllipseShader::~EllipseShader() {}

// load shader
void EllipseShader::loadShader() {
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
       << "uniform vec2 uCenter;"
       << "uniform float uSemiAxisX;"
       << "uniform float uSemiAxisY;"
       << "uniform sampler2D uTexture;"
       << "uniform int uUseTexture;"
       << "varying vec2 vTexCoord;"
       << "varying vec4 vColor;"

       << "float computeSignedDistance(vec2 p, float a, float b) {"
       << "    return length(vec2(p.x / a * 100.0, p.y / b * 100.0)) - 100.0;"
       << "}"

       << "void main() {"
       << "    vec2 p = gl_FragCoord.xy - uCenter;"
       << "    float sd = computeSignedDistance(p, uSemiAxisX, uSemiAxisY);"
       << "    float smoothWidth = 1.0;"
       << "    float alpha = 1.0 - smoothstep(-smoothWidth, 0.0, sd);"
       << "    if (sd <= 0.0) {"
       << "        vec4 bgColor = vec4(vColor.rgb, vColor.a * alpha);"
       << "        if (uUseTexture == 0) {"
       << "            gl_FragColor = bgColor;"
       << "        } else {"
       << "            vec4 texColor = texture2D(uTexture, vTexCoord);"
       << "            float outA = mix(texColor.a, 1.0, bgColor.a);"
       << "            vec3 outRGB = mix(texColor.rgb * texColor.a, bgColor.rgb, bgColor.a) / outA;"
       << "            gl_FragColor = vec4(outRGB, outA);"
       << "        }"
       << "    } else {"
       << "        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);"
       << "    }"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw ellipse
void EllipseShader::drawEllipse(
    Point center,
    float semiAxisX,
    float semiAxisY,
    Texture* textureSrc,
    const Point texCoordSrc[],
    Point vertices[],
    Color colors[],
    int count) const {
    bindUniformPoint("uCenter", center);
    bindUniformFloat("uSemiAxisX", semiAxisX);
    bindUniformFloat("uSemiAxisY", semiAxisY);

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
