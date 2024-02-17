//
//  MainScene.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/12.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "view/shape/Circle.hpp"
#include "MainScene.hpp"

namespace tears {

using namespace std;

// constructor
MainScene::MainScene(TearsEngine* aEngine, Size screenSize): Scene(aEngine, screenSize) {
    auto c1 = make_unique<Circle>();
    c1->fill(Color(145, 255, 248, 200)).Modifier::setSize(200.f, 200.f);
    auto c2 = make_unique<Circle>();
    c2->fill(Color(100, 200, 248, 200)).Modifier::setSize(300.f, 300.f);
    addChild(std::move(c1));
    addChild(std::move(c2));
}

// destructor
MainScene::~MainScene() {}

}    // namespace tears
