//
//  GLController.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "GLController.hpp"

namespace tears {

using namespace std;

// singleton instance
unique_ptr<GLController> GLController::glController = nullptr;

// constructor
GLController::GLController() {}

// get singleton instance
GLController* GLController::getInstance() {
    if (!glController) {    /// if singleton instance is not constructed yet
        glController.reset(new GLController());
    }
    return glController.get();
}

}    // namespace tears
