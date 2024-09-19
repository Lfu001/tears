//
//  MainScene.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/12.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <random>
#include "math/Interval.hpp"
#include "view/container/HStack.hpp"
#include "view/container/VStack.hpp"
#include "view/container/ZStack.hpp"
#include "view/control/Button.hpp"
#include "view/separator/Divider.hpp"
#include "view/separator/Spacer.hpp"
#include "view/shape/Capsule.hpp"
#include "view/shape/Circle.hpp"
#include "view/shape/Rectangle.hpp"
#include "MainScene.hpp"

namespace tears {

using namespace std;

// constructor
MainScene::MainScene(TearsEngine* aEngine, Size screenSize): Scene(aEngine, screenSize) {
    unique_ptr<View> heading = createHeading();
    heading->setHeightRatio(0.3f);

    unique_ptr<View> content = createContent();

    unique_ptr<View> footer = createFooter();
    footer->setHeight(70.f);

    auto vstack = make_unique<VStack>(std::move(heading), std::move(content), std::move(footer));

    addChild(std::move(vstack));
}

// destructor
MainScene::~MainScene() {}

unique_ptr<View> MainScene::createHeading() const {
    // title
    auto title = make_unique<Capsule>();
    title->setBackgroundColor(Color(255, 255, 255))
        .setHeight(24.f)
        .setWidthRatio(0.7f)
        .setPadding(EdgeBottom, 20.f)
        .setAlignment(AlignmentLeading);

    // text
    Color textColor = Color(240, 240, 240);
    auto textArea = make_unique<VStack>(
        std::move(title),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.3f, 0.7f), textColor),
        make_unique<Spacer>());
    textArea->setWidthRatio(0.7f);

    // user icon
    auto userIcon = make_unique<Circle>();
    userIcon->setBackgroundColor(Color(255, 255, 255))
        .setSize(30.f, 30.f)
        .setAlignment(AlignmentTop);

    // button
    auto buttonBg = make_unique<Capsule>();
    buttonBg->setBackgroundColor(Color(255, 255, 255, 150)).setBlurSigma(20.f);
    auto button = make_unique<Button>([]() {
        cout << "button tapped!" << endl;
    });
    button->setBackground(std::move(buttonBg));
    button->setSize(100.f, 35.f).setAlignment(AlignmentTrailing).setPadding(EdgeBottom, 8.f);

    // background
    auto background = make_unique<Rectangle>();
    background->setBackgroundColor(Color(224, 222, 150))
        .setBackgroundColor(Color(192, 245, 164), EdgeTopTrailing)
        .setBackgroundColor(Color(255, 200, 135), EdgeBottomLeading);

    auto noLayoutArea = make_unique<View>();
    noLayoutArea->setHeight(60.f).setAlignment(AlignmentTop);

    auto hstack =
        make_unique<HStack>(std::move(textArea), make_unique<Spacer>(), std::move(userIcon));

    auto vstack =
        make_unique<VStack>(std::move(noLayoutArea), std::move(hstack), std::move(button));
    vstack->setPadding(EdgeBottom, 10.f).setPadding(EdgeHorizontal, 20.f);

    auto zstack = make_unique<ZStack>(std::move(background), std::move(vstack));
    return zstack;
}

unique_ptr<View> MainScene::createContent() const {
    // background
    auto background = make_unique<Rectangle>();
    background->setBackgroundColor(Color(240, 240, 240));

    // widget with image and text
    unique_ptr<View> imageWidget = createImageWidget();
    imageWidget->setPadding(EdgeBottom, 8.f);

    // widgets with text
    unique_ptr<View> textWidget1 = createTextWidget();
    textWidget1->setPadding(EdgeTrailing, 8.f);
    unique_ptr<View> textWidget2 = createTextWidget();

    auto hstack = make_unique<HStack>(std::move(textWidget1), std::move(textWidget2));
    auto vstack = make_unique<VStack>(std::move(imageWidget), std::move(hstack));
    vstack->setPadding(EdgeAll, 20.f);

    return make_unique<ZStack>(std::move(background), std::move(vstack));
}

unique_ptr<View> MainScene::createFooter() const {
    // background
    auto background = make_unique<Rectangle>();
    background->setBackgroundColor(Color::WHITE);

    // icons
    auto makeIcon = []() {
        auto icon = make_unique<Circle>();
        icon->setBackgroundColor(Color(230, 230, 230)).setSize(24.f, 24.f);
        return icon;
    };

    auto noLayoutArea = make_unique<View>();
    noLayoutArea->setHeight(20.f);

    auto hstack = make_unique<HStack>(
        make_unique<Spacer>(),
        makeIcon(),
        make_unique<Spacer>(),
        makeIcon(),
        make_unique<Spacer>(),
        makeIcon(),
        make_unique<Spacer>());

    auto vstack = make_unique<VStack>(std::move(hstack), std::move(noLayoutArea));

    return make_unique<ZStack>(std::move(background), std::move(vstack));
}

unique_ptr<View> MainScene::createText(Interval widthInterval, Color color) const {
    static mt19937 engine;
    std::uniform_real_distribution<float> dist1(widthInterval.left, widthInterval.right);

    float widthRatio = dist1(engine);
    auto text = make_unique<Capsule>();
    text->setBackgroundColor(color)
        .setHeight(20.f)
        .setWidthRatio(widthRatio)
        .setPadding(EdgeTop, 6.f)
        .setAlignment(AlignmentLeading);
    return text;
}

unique_ptr<View> MainScene::createTextWidget() const {
    // background
    auto background = make_unique<RoundedRectangle>();
    background->setBackgroundColor(Color::WHITE);

    // title
    auto title = make_unique<Capsule>();
    title->setBackgroundColor(Color(180, 180, 180))
        .setHeight(24.f)
        .setWidthRatio(0.6f)
        .setPadding(EdgeBottom, 8.f)
        .setAlignment(AlignmentLeading);

    // text
    Color textColor(200, 200, 200);
    auto vstack = make_unique<VStack>(
        std::move(title),
        make_unique<Divider>(),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.3f, 0.7f), textColor),
        make_unique<Spacer>());
    vstack->setPadding(EdgeAll, 16.f);

    return make_unique<ZStack>(std::move(background), std::move(vstack));
}

unique_ptr<View> MainScene::createImageWidget() const {
    // background
    auto background = make_unique<RoundedRectangle>();
    background->setBackgroundColor(Color::WHITE);

    // title
    auto title = make_unique<Capsule>();
    title->setBackgroundColor(Color(180, 180, 180))
        .setHeight(24.f)
        .setWidthRatio(0.6f)
        .setPadding(EdgeBottom, 8.f)
        .setAlignment(AlignmentLeading);

    // text area
    Color textColor(200, 200, 200);
    auto vstack = make_unique<VStack>(
        std::move(title),
        make_unique<Divider>(),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.7f, 1.f), textColor),
        createText(Interval(0.3f, 0.7f), textColor),
        make_unique<Spacer>());

    // image
    auto image = make_unique<RoundedRectangle>();
    image->setCornerRadius(16.f)
        .setBackgroundColor(Color(230, 230, 230))
        .setWidth(150.f)
        .setPadding(EdgeLeading, 16.f);

    auto hstack = make_unique<HStack>(std::move(vstack), std::move(image));
    hstack->setPadding(EdgeAll, 16.f);

    return make_unique<ZStack>(std::move(background), std::move(hstack));
}

}    // namespace tears
