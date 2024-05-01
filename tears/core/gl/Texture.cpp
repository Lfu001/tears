//
//  Texture.cpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "Texture.hpp"

namespace tears {

// default texture coordinates
const Point Texture::DEFAULT_TEXTURE_COORD[4] = {
    Point(0.f, 1.f),
    Point(0.f, 0.f),
    Point(1.f, 1.f),
    Point(1.f, 0.f),
};

// constructor (from size)
Texture::Texture(int width, int height) {
    size = Size(width, height);
    GLController* gl = GLController::getInstance();
    gl->createTexture(width, height, &name);
}

// destructor
Texture::~Texture() {
    try {
        GLController* gl = GLController::getInstance();
        gl->deleteTexture(&name);
    } catch (...) {}
}

}    // namespace tears
