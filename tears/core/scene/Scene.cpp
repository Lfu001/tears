//
//  Scene.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/03.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "Scene.hpp"

namespace tears {

// constructor
Scene::Scene(TearsEngine* aEngine, Size screenSize) {
    engine = aEngine;
    size.width = screenSize.width;
    size.height = screenSize.height;
}

// destructor
Scene::~Scene() {}

// render the scene
void Scene::render() {
    draw();
}

// set scene size
void Scene::setSceneSize(float x, float y) {
    setSceneSize(Size(x, y));
}

// set scene size by Vector2D
void Scene::setSceneSize(Size aSize) {
    size = aSize;
    setIsDirtyLayout(true);
}

}    // namespace tears
