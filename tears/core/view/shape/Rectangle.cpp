//
//  Rectangle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/24.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "Rectangle.hpp"

namespace tears {

// default constructor
Rectangle::Rectangle() {}

// destructor
Rectangle::~Rectangle() {}

// main drawing process
void Rectangle::drawMain() {
    Shape::drawMain();

    stringstream fs;
    fs << "precision highp float;"
       << "varying vec4 vColor;"
       << "void main() {"
       << "    gl_FragColor = vColor;"
       << "}";

    GLController* gl = GLController::getInstance();
    const char* vs = getVertexShaderSource();
    gl->prepareProgram(vs, fs.str().c_str());

    unique_ptr<float[]> v = gl->bindAttributeColors("aColor", backgroundColor, 4);
    vector<Point> vertices = getVertices();
    gl->drawArrays(PrimitiveTriangleStrip, vertices.data(), (int)vertices.size());
}

}    // namespace tears
