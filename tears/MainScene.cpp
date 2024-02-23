//
//  MainScene.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/12.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "view/shape/Capsule.hpp"
#include "view/shape/Circle.hpp"
#include "view/shape/RoundedRectangle.hpp"
#include "MainScene.hpp"

namespace tears {

using namespace std;

// constructor
MainScene::MainScene(TearsEngine* aEngine, Size screenSize): Scene(aEngine, screenSize) {
    auto circle = make_unique<Circle>();
    circle->fill(Color(145, 255, 248, 200)).Modifier::setSize(200.f, 200.f);
    auto roundedRect = make_unique<RoundedRectangle>(24.f);
    roundedRect->fill(Color(100, 200, 248, 200)).Modifier::setSize(300.f, 300.f);
    auto capsule = make_unique<Capsule>();
    capsule->fill(Color(233, 255, 138, 200)).Modifier::setSize(180.f, 40.f);
    addChild(std::move(circle));
    addChild(std::move(roundedRect));
    addChild(std::move(capsule));
}

// destructor
MainScene::~MainScene() {}

}    // namespace tears
