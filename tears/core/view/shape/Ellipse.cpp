//
//  Ellipse.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "gl/shader/EllipseShader.hpp"
#include "gl/shader/ShaderController.hpp"
#include "gl/shader/ShaderScope.hpp"
#include "Ellipse.hpp"

namespace tears {

// default constructor
Ellipse::Ellipse() {}

// destructor
Ellipse::~Ellipse() {}

// main drawing process
void Ellipse::drawMain() {
    Shape::drawMain();

    GLController* gl = GLController::getInstance();
    Point center(position.x + size.width / 2.f, position.y + size.height / 2.f);
    float screenScale = gl->getScreenScale();
    float semiAxisX = size.width / 2.f * screenScale;
    float semiAxisY = size.height / 2.f * screenScale;
    vector<Point> vertices = getVertices();

    ShaderController* sc = ShaderController::getInstance();
    EllipseShader* shader = (EllipseShader*)sc->createShader(ShaderEllipse);
    if (needBlurring()) {    // if blurring background view
        unique_ptr<Texture> blurredTex = prepareBlurredTexture();
        ShaderScope ss(shader);
        shader->drawEllipse(
            center,
            semiAxisX,
            semiAxisY,
            blurredTex.get(),
            Texture::DEFAULT_TEXTURE_COORD,
            vertices.data(),
            backgroundColor,
            4);
    } else {
        ShaderScope ss(shader);
        shader->drawEllipse(
            center,
            semiAxisX,
            semiAxisY,
            nullptr,
            nullptr,
            vertices.data(),
            backgroundColor,
            4);
    }
}

}    // namespace tears
