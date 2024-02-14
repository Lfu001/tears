//
//  MatrixStackScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/14.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "utils/DebugUtil.hpp"
#include "MatrixStackScope.hpp"

namespace tears {

// default constructor
MatrixStackScope::MatrixStackScope() {
    try {
        GLController* gl = GLController::getInstance();
        Matrix top = gl->matrixStack.back();
        gl->matrixStack.push_back(top);
    } catch (...) {}
}

// destructor
MatrixStackScope::~MatrixStackScope() {
    GLController* gl = GLController::getInstance();
    if (gl->matrixStack.empty()) {
        tears_assert(false);
        return;
    }
    gl->matrixStack.pop_back();
}

// get the top matrix of the matrix stack
Matrix* MatrixStackScope::getTopMatrix() const {
    GLController* gl = GLController::getInstance();
    return &gl->matrixStack.back();
}

}    // namespace tears
