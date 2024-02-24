//
//  Rectangle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/24.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "Rectangle.hpp"

namespace tears {

// default constructor
Rectangle::Rectangle() {}

// destructor
Rectangle::~Rectangle() {}

// main drawing process. call GLController::drawArrays() from this method.
void Rectangle::drawMain() {
    Shape::drawMain();

    vector<Point> vertices = getVertices();
    GLController* gl = GLController::getInstance();
    gl->drawArrays(PrimitiveTriangleStrip, vertices.data(), (int)vertices.size(), fillColor);
}

}    // namespace tears
