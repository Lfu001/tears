//
//  Texture.cpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "utils/DebugUtil.hpp"
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

// get texture parameter
TextureParameterType Texture::getTextureParameter(TextureParameterNameType name) const {
    switch (name) {
        case TextureParameterNameMinFilter:
            return minFilter;
        case TextureParameterNameMagFilter:
            return magFilter;
        case TextureParameterNameWrapS:
            return wrapS;
        case TextureParameterNameWrapT:
            return wrapT;
        default:
            tears_assert(false);
            break;
    }
}

// set texture parameter
void Texture::setTextureParameter(TextureParameterNameType name, TextureParameterType param) {
    GLController* gl = GLController::getInstance();
    gl->setTextureParameter(name, param);
    switch (name) {
        case TextureParameterNameMinFilter:
            minFilter = param;
            break;
        case TextureParameterNameMagFilter:
            magFilter = param;
            break;
        case TextureParameterNameWrapS:
            wrapS = param;
            break;
        case TextureParameterNameWrapT:
            wrapT = param;
            break;
        default:
            tears_assert(false);
            break;
    }
}

}    // namespace tears
