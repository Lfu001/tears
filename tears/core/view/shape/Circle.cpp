//
//  Circle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "Circle.hpp"

namespace tears {

using namespace std;

// default constructor
Circle::Circle() {}

// destructor
Circle::~Circle() {}

// main drawing process. call GLController::drawArrays() from this method.
void Circle::drawMain() {
    Shape::drawMain();

    const char* centerVarName = "uCenter";
    const char* radiusVarName = "uRadius";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform vec2 " << centerVarName << ";"
       << "uniform float " << radiusVarName << ";"
       << "void main() {"
       << "    float d = distance(gl_FragCoord.xy, uCenter);"
       << "    if (d <= uRadius) {"
       << "        gl_FragColor = " << fillColor.toNormalizedString() << ";"
       << "    } else {"
       << "        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);"
       << "    }"
       << "}";

    GLController* gl = GLController::getInstance();
    const char* vs = gl->getDefaultVertexShaderSource();
    gl->prepareProgram(vs, fs.str().c_str());

    Point center(position.x + size.width / 2.f, position.y + size.height / 2.f);
    float radius = fminf(size.width, size.height) / 2.f * gl->getScreenScale();
    gl->bindUniformPoint(centerVarName, center);
    gl->bindUniformFloat(radiusVarName, radius);

    unique_ptr<Point[]> vertices = getVertices();
    gl->drawArrays(PrimitiveTriangleStrip, vertices.get(), 4);
}

}    // namespace tears
