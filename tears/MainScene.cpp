//
//  MainScene.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/12.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "view/container/HStack.hpp"
#include "view/container/VStack.hpp"
#include "view/container/ZStack.hpp"
#include "view/shape/Capsule.hpp"
#include "view/shape/Circle.hpp"
#include "view/shape/Ellipse.hpp"
#include "view/shape/Rectangle.hpp"
#include "view/shape/RoundedRectangle.hpp"
#include "MainScene.hpp"

namespace tears {

using namespace std;

// constructor
MainScene::MainScene(TearsEngine* aEngine, Size screenSize): Scene(aEngine, screenSize) {
    auto roundedRect = make_unique<RoundedRectangle>(24.f);
    roundedRect->fill(Color(100, 200, 248, 200));
    auto circle = make_unique<Circle>();
    circle->fill(Color(145, 255, 248, 200)).setPadding(EdgeAll, 15.f).setOffsetX(50.f);
    auto zstack = make_unique<ZStack>(std::move(roundedRect), std::move(circle));
    zstack->setWidth(300.f).setPadding(EdgeBottom, 20.f);

    auto capsule = make_unique<Capsule>();
    capsule->fill(Color(233, 255, 138, 200)).setHeight(40.f);
    auto hstack = make_unique<HStack>(std::move(zstack), std::move(capsule));
    hstack->setHeight(200.f);

    auto ellipse = make_unique<Ellipse>();
    ellipse->fill(Color(255, 148, 148, 200)).setSize(300.f, 100.f).setPadding(EdgeBottom, 10.f);
    auto rectangle = make_unique<Rectangle>();
    rectangle->fill(Color(255, 174, 0, 200)).setSize(200.f, 100.f);

    auto vstack = make_unique<VStack>(std::move(hstack), std::move(ellipse), std::move(rectangle));
    vstack->setHeight(700.f).setPadding(EdgeHorizontal, 10.f);

    addChild(std::move(vstack));
}

// destructor
MainScene::~MainScene() {}

}    // namespace tears
