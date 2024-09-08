//
//  TearsEngine.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/FramebufferScope.hpp"
#include "gl/GLController.hpp"
#include "MainScene.hpp"
#include "TearsEngine.hpp"

namespace tears {

// default constructor
TearsEngine::TearsEngine(int screenWidth, int screenHeight) {
    initialize(Size(screenWidth, screenHeight));
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
void TearsEngine::initialize(Size screenSize) {
    glController = GLController::getInstance();
    setCurrentScene(make_unique<MainScene>(this, screenSize), false);
}

// run one event loop
void TearsEngine::runOneLoop() {
    if (callback) {
        callback();
        callback = nullptr;
    }
    if (isDirty) {
        {
            FramebufferScope fbs(glController->screenTexture.get());
            glController->preprocess();
            currentScene->render();
        }
        glController->preprocess();
        glController->finalize();
        setIsDirty(false);
    }
}

// set current scene
void TearsEngine::setCurrentScene(unique_ptr<Scene> scene, bool lazy /* = true */) {
    if (lazy) {    /// if the scene is to be set on next event loop
        nextScene = std::move(scene);
        setNextLoopCallback([this]() {
            currentScene.reset(nextScene.release());
            currentScene->setSceneSize(size);
        });
    } else {
        currentScene = std::move(scene);
        currentScene->setSceneSize(size);
    }
}

// set a size of the view
void TearsEngine::setViewSize(int width, int height) {
    if (width == size.width
        && height == size.height) {    /// if the given size is not changed from previous one
        return;
    }
    size = Size(width, height);
    glController->setScreenSize(width, height);
    float scale = glController->getScreenScale();
    if (currentScene) {
        currentScene->setSceneSize(width / scale, height / scale);
    }
    setIsDirty(true);
}

// set screen scale
void TearsEngine::setScreenScale(float scale) const {
    glController->setScreenScale(scale);
}

}    // namespace tears
