//
//  ShaderScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/shader/ShaderController.hpp"
#include "utils/DebugUtil.hpp"
#include "ShaderScope.hpp"

namespace tears {

// constructor
ShaderScope::ShaderScope(const Shader* shader) {
    if (!shader) {
        tears_assert(false);
        return;
    }
    ShaderController* sc = ShaderController::getInstance();
    sc->pushShader(shader);
}

// destructor
ShaderScope::~ShaderScope() {
    try {
        ShaderController* sc = ShaderController::getInstance();
        sc->popShader();
    } catch (...) {
        tears_assert(false);
    }
}

}    // namespace tears
