//
//  MainScene.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/12.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "view/shape/Circle.hpp"
#include "view/shape/RoundedRectangle.hpp"
#include "MainScene.hpp"

namespace tears {

using namespace std;

// constructor
MainScene::MainScene(TearsEngine* aEngine, Size screenSize): Scene(aEngine, screenSize) {
    auto c = make_unique<Circle>();
    c->fill(Color(145, 255, 248, 200)).Modifier::setSize(200.f, 200.f);
    auto r = make_unique<RoundedRectangle>(24.f);
    r->fill(Color(100, 200, 248, 200)).Modifier::setSize(300.f, 300.f);
    addChild(std::move(c));
    addChild(std::move(r));
}

// destructor
MainScene::~MainScene() {}

}    // namespace tears
