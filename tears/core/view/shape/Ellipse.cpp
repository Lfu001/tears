//
//  Ellipse.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "Ellipse.hpp"

namespace tears {

// default constructor
Ellipse::Ellipse() {}

// destructor
Ellipse::~Ellipse() {}

// main drawing process
void Ellipse::drawMain() {
    Shape::drawMain();

    const char* centerVarName = "uCenter";
    const char* semiAxisXVarName = "uSemiAxisX";
    const char* semiAxisYVarName = "uSemiAxisY";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform vec2 " << centerVarName << ";"
       << "uniform float " << semiAxisXVarName << ";"
       << "uniform float " << semiAxisYVarName << ";"
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

    GLController* gl = GLController::getInstance();
    const char* vs = getVertexShaderSource();
    gl->prepareProgram(vs, fs.str().c_str());

    unique_ptr<float[]> v = gl->bindAttributeColors("aColor", backgroundColor, 4);
    Point center(position.x + size.width / 2.f, position.y + size.height / 2.f);
    float screenScale = gl->getScreenScale();
    gl->bindUniformPoint(centerVarName, center);
    gl->bindUniformFloat(semiAxisXVarName, size.width / 2.f * screenScale);
    gl->bindUniformFloat(semiAxisYVarName, size.height / 2.f * screenScale);

    vector<Point> vertices = getVertices();
    gl->drawArrays(PrimitiveTriangleStrip, vertices.data(), (int)vertices.size());
}

}    // namespace tears
