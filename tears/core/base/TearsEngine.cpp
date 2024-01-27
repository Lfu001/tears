//
//  TearsEngine.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "TearsEngine.hpp"

namespace tears {

// default constructor
TearsEngine::TearsEngine() {
    initialize();
}

// destructor
TearsEngine::~TearsEngine() {}

// initializer
void TearsEngine::initialize() {
    glController = GLController::getInstance();
}

// run one event loop
void TearsEngine::runOneLoop() {
    if (isDirty) {
        glController->draw();
        setIsDirty(false);
    }
}

// set a size of the view
void TearsEngine::setViewSize(int x, int y) {
    glController->setViewSize(x, y);
    setIsDirty(true);
}

}    // namespace tears
