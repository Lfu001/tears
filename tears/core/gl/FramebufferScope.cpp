//
//  FramebufferScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/Framebuffer.hpp"
#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "FramebufferScope.hpp"

namespace tears {

// constructor (from texture)
FramebufferScope::FramebufferScope(const Texture* texture):
    viewportScope(texture->getWidth(), texture->getHeight()) {
    framebuffer = make_unique<Framebuffer>(texture);
    framebuffer->bind();
    GLController* gl = GLController::getInstance();
    gl->framebufferStack.push_back(framebuffer.get());
}

// destructor
FramebufferScope::~FramebufferScope() {
    try {
        framebuffer->unbind();
        GLController* gl = GLController::getInstance();
        gl->framebufferStack.pop_back();
        if (!gl->framebufferStack.empty()) {    /// if we have to restore previous framebuffer
            gl->framebufferStack.back()->bind();
        }
    } catch (...) {}
}

}    // namespace tears
