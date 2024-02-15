//
//  TearsEngine.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "MainScene.hpp"
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
    setCurrentScene(make_unique<MainScene>(this), false);
}

// run one event loop
void TearsEngine::runOneLoop() {
    if (callback) {
        callback();
        callback = nullptr;
    }
    if (isDirty) {
        glController->preprocess();
        currentScene->render();
        setIsDirty(false);
    }
}

// set current scene
void TearsEngine::setCurrentScene(unique_ptr<Scene> scene, bool lazy /* = true */) {
    if (lazy) {    /// if the scene is to be set on next event loop
        nextScene = std::move(scene);
        setNextLoopCallback([this]() {
            currentScene.reset(nextScene.release());
            currentScene->setSize(size);
        });
    } else {
        currentScene = std::move(scene);
        currentScene->setSize(size);
    }
}

// set a size of the view
void TearsEngine::setViewSize(int x, int y) {
    size = Size(x, y);
    glController->setViewSize(x, y);
    currentScene->setSize(x, y);
    setIsDirty(true);
}

// set screen scale
void TearsEngine::setScreenScale(float scale) const {
    glController->setScreenScale(scale);
}

}    // namespace tears
