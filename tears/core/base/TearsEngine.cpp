//
//  TearsEngine.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "TearsEngine.hpp"

#include "gl/GLController.hpp"

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
void TearsEngine::runOneLoop() const {
    glController->draw();
}

// set a size of the view
void TearsEngine::setViewSize(int x, int y) const {
    glController->setViewSize(x, y);
}

}    // namespace tears
