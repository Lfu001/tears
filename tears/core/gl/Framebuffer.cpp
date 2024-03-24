//
//  Framebuffer.cpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "Framebuffer.hpp"

namespace tears {

// default constructor
Framebuffer::Framebuffer() {
    initialize();
}

// constructor (from texture)
Framebuffer::Framebuffer(const Texture& aTexture) {
    initialize();
    attachTexture(aTexture);
}

// destructor
Framebuffer::~Framebuffer() {
    try {
        GLController* gl = GLController::getInstance();
        gl->deleteFramebuffer(&name);
    } catch (...) {}
}

// initializer
void Framebuffer::initialize() {
    GLController* gl = GLController::getInstance();
    gl->createFramebuffer(&name);
}

// attach texture
void Framebuffer::attachTexture(const Texture& texture) const {
    GLController* gl = GLController::getInstance();
    bind();
    gl->attachTexture(texture.getName());
    unbind();
}

// bind framebuffer
void Framebuffer::bind() const {
    GLController* gl = GLController::getInstance();
    gl->bindFramebuffer(this);
}

// unbind framebuffer. equivalent to binding default framebuffer.
void Framebuffer::unbind() const {
    GLController* gl = GLController::getInstance();
    gl->bindFramebuffer(nullptr);
}

}    // namespace tears
