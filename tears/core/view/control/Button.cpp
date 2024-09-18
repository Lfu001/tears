//
//  Button.cpp
//  tears
//
//  Created by Lfu001 on 2024/09/18.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "view/shape/Shape.hpp"
#include "Button.hpp"

namespace tears {
using namespace std;

// constructor
Button::Button(function<void()> aAction /* = nullptr */) {
    action = aAction;
}

// destructor
Button::~Button() {}

// Set backgroud.
void Button::setBackground(unique_ptr<Shape> aBackground) {
    children.clear();
    background = aBackground.get();
    addChild(std::move(aBackground));
}

// Handle a touch event. Call this method from the OS API.
void Button::onTap() {
    if (action) {
        action();
    }
}

}    // namespace tears
