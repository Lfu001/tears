//
//  Circle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "gl/shader/CircleShader.hpp"
#include "gl/shader/ShaderController.hpp"
#include "gl/shader/ShaderScope.hpp"
#include "Circle.hpp"

namespace tears {

using namespace std;

// default constructor
Circle::Circle() {}

// destructor
Circle::~Circle() {}

// main drawing process
void Circle::drawMain() {
    Shape::drawMain();

    GLController* gl = GLController::getInstance();
    Point center(position.x + size.width / 2.f, position.y + size.height / 2.f);
    float radius = fminf(size.width, size.height) / 2.f * gl->getScreenScale();
    vector<Point> vertices = getVertices();

    ShaderController* sc = ShaderController::getInstance();
    CircleShader* shader = (CircleShader*)sc->createShader(ShaderCircle);
    if (needBlurring()) {    // if blurring background view
        Texture* blurredTex = prepareBlurredTexture();
        ShaderScope ss(shader);
        shader->drawCircle(
            center,
            radius,
            vertices.data(),
            blurredTex,
            Texture::DEFAULT_TEXTURE_COORD,
            backgroundColor,
            4);
    } else {
        ShaderScope ss(shader);
        shader->drawCircle(center, radius, vertices.data(), nullptr, nullptr, backgroundColor, 4);
    }
}

}    // namespace tears
