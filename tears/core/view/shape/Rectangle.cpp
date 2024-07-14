//
//  Rectangle.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/24.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "gl/shader/RectangleShader.hpp"
#include "gl/shader/ShaderController.hpp"
#include "gl/shader/ShaderScope.hpp"
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

    if (needBlurring()) {    // if blurring background view
        unique_ptr<Texture> blurredTex = prepareBlurredTexture();
        ShaderController* sc = ShaderController::getInstance();
        RectangleShader* shader = (RectangleShader*)sc->createShader(ShaderRectangle);
        ShaderScope ss(shader);
        shader->drawRectangle(
            blurredTex.get(),
            Texture::DEFAULT_TEXTURE_COORD,
            vertices.data(),
            backgroundColor,
            4);
    } else {
        gl->drawArrays(PrimitiveTriangleStrip, vertices.data(), backgroundColor, 4);
    }
}

}    // namespace tears
