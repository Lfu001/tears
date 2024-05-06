//
//  CircleShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "gl/shader/ShaderScope.hpp"
#include "CircleShader.hpp"

namespace tears {
using namespace std;

// default constructor
CircleShader::CircleShader() {}

// destructor
CircleShader::~CircleShader() {}

// load shader
void CircleShader::loadShader() {
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
       << "uniform float uRadius;"
       << "varying vec4 vColor;"
       << "void main() {"
       << "    float d = distance(gl_FragCoord.xy, uCenter);"
       << "    float smoothWidth = 1.0;"
       << "    float alpha = 1.0 - smoothstep(uRadius - smoothWidth, uRadius + smoothWidth, d);"
       << "    if (d <= uRadius) {"
       << "        gl_FragColor = vec4(vColor.rgb, vColor.a * alpha);"
       << "    } else {"
       << "        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);"
       << "    }"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw circle
void CircleShader::drawCircle(
    Point center,
    float radius,
    Point vertices[],
    Color colors[],
    int count) const {
    bindAttributeColors("aColor", colors);
    bindUniformPoint("uCenter", center);
    bindUniformValue("uRadius", radius);

    GLController* gl = GLController::getInstance();
    gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
}

}    // namespace tears
