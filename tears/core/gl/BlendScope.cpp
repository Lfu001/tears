//
//  BlendScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/06.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "utils/DebugUtil.hpp"
#include "BlendScope.hpp"

namespace tears {

// constructor
BlendScope::BlendScope(BlendEquationType equation, BlendType factorSrc, BlendType factorDst) {
    GLController* gl = GLController::getInstance();
    blendBackup = gl->getBlendSettings();
    gl->setBlendSettings(equation, factorSrc, factorDst);
}

// destructor
BlendScope::~BlendScope() {
    try {
        GLController* gl = GLController::getInstance();
        gl->setBlendSettings(blendBackup.equation, blendBackup.factorSrc, blendBackup.factorDst);
    } catch (...) {
        tears_assert(false);
    }
}

}    // namespace tears
