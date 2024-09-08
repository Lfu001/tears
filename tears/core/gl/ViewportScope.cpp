//
//  ViewportScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/05.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "utils/DebugUtil.hpp"
#include "ViewportScope.hpp"

namespace tears {

// constructor
ViewportScope::ViewportScope(int width, int height) {
    GLController* gl = GLController::getInstance();
    viewportSizeBackup = gl->viewportSize;
    viewportMatrixBackup = gl->viewportMatrix;
    gl->setViewport(width, height);
}

// destructor
ViewportScope::~ViewportScope() {
    try {
        GLController* gl = GLController::getInstance();
        gl->viewportMatrix = viewportMatrixBackup;
        gl->setViewport(viewportSizeBackup.width, viewportSizeBackup.height);
    } catch (...) {
        tears_assert(false);
    }
}

}    // namespace tears
