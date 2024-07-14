//
//  ShaderController.cpp
//  tears
//
//  Created by Lfu001 on 2024/04/28.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/shader/BasicShader.hpp"
#include "gl/shader/BlurShader.hpp"
#include "gl/shader/CircleShader.hpp"
#include "gl/shader/CopyShader.hpp"
#include "gl/shader/EllipseShader.hpp"
#include "gl/shader/RectangleShader.hpp"
#include "gl/shader/RoundedRectangleShader.hpp"
#include "utils/DebugUtil.hpp"
#include "ShaderController.hpp"

namespace tears {
using namespace std;

// singleton instance
unique_ptr<ShaderController> ShaderController::controller = nullptr;

// default constructor
ShaderController::ShaderController() {
    Shader* shader = createShader(ShaderBasic);
    pushShader(shader);
}

// destructor
ShaderController::~ShaderController() {}

// get singleton instance
ShaderController* ShaderController::getInstance() {
    if (!controller) {    /// if singleton instance is not created yet
        controller.reset(new ShaderController());
    }
    return controller.get();
}

// create shader
Shader* ShaderController::createShader(ShaderObjectType shaderObjectType) {
    if (shaderMap.contains(shaderObjectType)) {    /// if requested shader is already created
        return shaderMap[shaderObjectType].get();
    }

    unique_ptr<Shader> shader;
    switch (shaderObjectType) {
        case ShaderBasic:
            shader = make_unique<BasicShader>();
            break;
        case ShaderCopy:
            shader = make_unique<CopyShader>();
            break;
        case ShaderCircle:
            shader = make_unique<CircleShader>();
            break;
        case ShaderEllipse:
            shader = make_unique<EllipseShader>();
            break;
        case ShaderRectangle:
            shader = make_unique<RectangleShader>();
            break;
        case ShaderRoundedRectangle:
            shader = make_unique<RoundedRectangleShader>();
            break;
        case ShaderBlur:
            shader = make_unique<BlurShader>();
            break;
        default:
            tears_assert(false);
            break;
    }
    if (!shader) {
        /// create shader in the above switch block
        tears_assert(false);
        return nullptr;
    }
    shader->loadShader();
    shaderMap[shaderObjectType] = std::move(shader);
    return shaderMap[shaderObjectType].get();
}

// get current shader
const Shader* ShaderController::getCurrentShader() const {
    if (shaderStack.empty()) {
        return nullptr;
    }
    return shaderStack.back();
}

// push shader to stack
void ShaderController::pushShader(const Shader* shader) {
    if (!shader) {
        tears_assert(false);
        return;
    }
    shaderStack.push_back(shader);
    useShader(shader);
}

// pop shader from stack
void ShaderController::popShader() {
    if (!shaderStack.empty()) {
        shaderStack.pop_back();
    }
    if (!shaderStack.empty()) {
        const Shader* shader = shaderStack.back();
        useShader(shader);
    }
}

// use shader
void ShaderController::useShader(const Shader* shader) const {
    if (!shader) {
        tears_assert(false);
        return;
    }
    GLController* gl = GLController::getInstance();
    gl->useProgram(shader->getProgramObject());
}

}    // namespace tears
