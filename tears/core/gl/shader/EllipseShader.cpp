//
//  EllipseShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/01.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
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
       << "attribute vec4 aColor;"
       << "varying vec4 vColor;"
       << "void main() {"
       << "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
       << "    vColor = aColor;"
       << "}";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform vec2 uCenter;"
       << "uniform float uSemiAxisX;"
       << "uniform float uSemiAxisY;"
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
       << "        gl_FragColor = vec4(vColor.rgb, vColor.a * alpha);"
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
    Point vertices[],
    Color colors[],
    int count) const {
    bindAttributeColors("aColor", colors);
    bindUniformPoint("uCenter", center);
    bindUniformValue("uSemiAxisX", semiAxisX);
    bindUniformValue("uSemiAxisY", semiAxisY);

    GLController* gl = GLController::getInstance();
    gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
}

}    // namespace tears
