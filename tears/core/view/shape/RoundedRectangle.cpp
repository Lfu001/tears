//
//  RoundedRectangle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "RoundedRectangle.hpp"

namespace tears {

// default constructor
RoundedRectangle::RoundedRectangle() {}

// constructor from corner radius
RoundedRectangle::RoundedRectangle(float radius) {
    cornerRadius = radius;
}

// destructor
RoundedRectangle::~RoundedRectangle() {}

// main drawing process. call GLController::drawArrays() from this method.
void RoundedRectangle::drawMain() {
    Shape::drawMain();

    const char* centerVarName = "uCenter";
    const char* halfSizeVarName = "uHalfSize";
    const char* radiusVarName = "uRadius";
    float r = fillColor.red / 255.f;
    float g = fillColor.green / 255.f;
    float b = fillColor.blue / 255.f;
    float a = fillColor.alpha / 255.f;

    stringstream fs;
    fs << "precision highp float;"
       << "uniform vec2 " << centerVarName << ";"
       << "uniform vec2 " << halfSizeVarName << ";"
       << "uniform float " << radiusVarName << ";"

       << "float computeSignedDistance(vec2 p, vec2 b, float r) {"
       << "    vec2 q = abs(p) - b + vec2(r, r);"
       << "    return min(max(q.x, q.y), 0.0) + length(max(q, vec2(0.0, 0.0))) - r;"
       << "}"

       << "void main() {"
       << "    float sd = computeSignedDistance(gl_FragCoord.xy - uCenter, uHalfSize, uRadius);"
       << "    float smoothWidth = 1.0;"
       << "    float alpha = 1.0 - smoothstep(-smoothWidth, 0.0, sd);"
       << "    if (sd <= 0.0) {"
       << "        gl_FragColor = vec4(" << r << ", " << g << ", " << b << ", " << a << " * alpha);"
       << "    } else {"
       << "        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);"
       << "    }"
       << "}";

    GLController* gl = GLController::getInstance();
    const char* vs = gl->getDefaultVertexShaderSource();
    gl->prepareProgram(vs, fs.str().c_str());

    Point center(position.x + size.width / 2.f, position.y + size.height / 2.f);
    Size halfSize(size.width / 2.f, size.height / 2.f);
    gl->bindUniformPoint(centerVarName, center);
    gl->bindUniformSize(halfSizeVarName, halfSize);
    gl->bindUniformFloat(radiusVarName, cornerRadius * gl->getScreenScale());

    vector<Point> vertices = getVertices();
    gl->drawArrays(PrimitiveTriangleStrip, vertices.data(), (int)vertices.size());
}

}    // namespace tears
