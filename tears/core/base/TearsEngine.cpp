//
//  TearsEngine.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "scene/Scene.hpp"
#include "TearsEngine.hpp"

namespace tears {

// default constructor
TearsEngine::TearsEngine() {
    initialize();
}

// copy constructor
TearsEngine::TearsEngine(const TearsEngine& engine) {
    glController = engine.glController;
    currentScene = engine.currentScene;
    isDirty = engine.isDirty;
}

// destructor
TearsEngine::~TearsEngine() {}

// initializer
void TearsEngine::initialize() {
    glController = GLController::getInstance();
    currentScene = make_shared<Scene>();
}

// run one event loop
void TearsEngine::runOneLoop() {
    if (isDirty) {
        glController->draw();
        currentScene->render();
        setIsDirty(false);
    }
}

// set a size of the view
void TearsEngine::setViewSize(int x, int y) {
    glController->setViewSize(x, y);
    currentScene->setSize(x, y);
    setIsDirty(true);
}

// set screen scale
void TearsEngine::setScreenScale(float scale) const {
    glController->setScreenScale(scale);
}

}    // namespace tears
