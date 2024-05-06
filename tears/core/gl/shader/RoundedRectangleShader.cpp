//
//  RoundedRectangleShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/01.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "RoundedRectangleShader.hpp"

namespace tears {

// default constructor
RoundedRectangleShader::RoundedRectangleShader() {}

// destructor
RoundedRectangleShader::~RoundedRectangleShader() {}

// load shader
void RoundedRectangleShader::loadShader() {
    stringstream vs;
    vs << "uniform mat3 uMatrixMVP;"
       << "uniform mat3 uMatrixU;"
       << "attribute vec2 aPosition;"
       << "attribute vec4 aColor;"
       << "varying vec4 vColor;"
       << "void main() {"
       << "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
       << "    vColor = aColor;"
       << "}";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform vec2 uCenter;"
       << "uniform vec2 uHalfSize;"
       << "uniform float uRadius;"
       << "varying vec4 vColor;"
       << "float computeSignedDistance(vec2 p, vec2 b, float r) {"
       << "    vec2 q = abs(p) - b + vec2(r, r);"
       << "    return min(max(q.x, q.y), 0.0) + length(max(q, vec2(0.0, 0.0))) - r;"
       << "}"
       << "void main() {"
       << "    float sd = computeSignedDistance(gl_FragCoord.xy - uCenter, uHalfSize, uRadius);"
       << "    float smoothWidth = 1.0;"
       << "    float alpha = 1.0 - smoothstep(-smoothWidth, 0.0, sd);"
       << "    if (sd <= 0.0) {"
       << "        gl_FragColor = vec4(vColor.rgb, vColor.a * alpha);"
       << "    } else {"
       << "        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);"
       << "    }"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw rounded rectangle
void RoundedRectangleShader::drawRoundedRectangle(
    Point center,
    float cornerRadius,
    Size halfSize,
    Point vertices[],
    Color colors[],
    int count) const {
    bindAttributeColors("aColor", colors);
    bindUniformPoint("uCenter", center);
    bindUniformFloat("uRadius", cornerRadius);
    bindUniformSize("uHalfSize", halfSize);

    GLController* gl = GLController::getInstance();
    gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
}

}    // namespace tears
