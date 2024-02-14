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
Scene::Scene(TearsEngine* aEngine) {
    engine = aEngine;
}

// destructor
Scene::~Scene() {}

// render the scene
void Scene::render() {
    for (auto& c: children) {
        c->draw();
    }
}

}    // namespace tears
