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
    GLController* gl = GLController::getInstance();
    if (gl->matrixStack.empty()) {
        Matrix id = Matrix::getIdentity();
        gl->matrixStack.push_back(*(AffineTransform*)(&id));
    } else {
        AffineTransform top = gl->matrixStack.back();
        gl->matrixStack.push_back(top);
    }
}

// destructor
MatrixStackScope::~MatrixStackScope() {
    try {
        GLController* gl = GLController::getInstance();
        if (gl->matrixStack.empty()) {
            tears_assert(false);
            return;
        }
        gl->matrixStack.pop_back();
    } catch (...) {}
}

// get the top matrix of the matrix stack
AffineTransform* MatrixStackScope::getTopMatrix() const {
    GLController* gl = GLController::getInstance();
    return &gl->matrixStack.back();
}

}    // namespace tears
