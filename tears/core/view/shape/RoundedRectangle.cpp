//
//  RoundedRectangle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/shader/RoundedRectangleShader.hpp"
#include "gl/shader/ShaderController.hpp"
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

// main drawing process
void RoundedRectangle::drawMain() {
    Shape::drawMain();

    GLController* gl = GLController::getInstance();
    Point center(position.x + size.width / 2.f, position.y + size.height / 2.f);
    float radius = cornerRadius * gl->getScreenScale();
    Size halfSize(size.width / 2.f, size.height / 2.f);
    vector<Point> vertices = getVertices();

    ShaderController* sc = ShaderController::getInstance();
    RoundedRectangleShader* shader =
        (RoundedRectangleShader*)sc->createShader(ShaderRoundedRectangle);
    shader->drawRoundedRectangle(center, radius, halfSize, vertices.data(), backgroundColor, 4);
}

}    // namespace tears
