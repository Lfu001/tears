//
//  Rectangle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/24.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/shader/BasicShader.hpp"
#include "Rectangle.hpp"

namespace tears {

// default constructor
Rectangle::Rectangle() {}

// destructor
Rectangle::~Rectangle() {}

// main drawing process
void Rectangle::drawMain() {
    Shape::drawMain();

    GLController* gl = GLController::getInstance();
    vector<Point> vertices = getVertices();
    gl->drawArrays(PrimitiveTriangleStrip, vertices.data(), backgroundColor, 4);
}

}    // namespace tears
