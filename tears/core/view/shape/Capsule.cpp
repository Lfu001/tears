//
//  Capsule.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "Capsule.hpp"

namespace tears {

// default constructor
Capsule::Capsule() {}

// destructor
Capsule::~Capsule() {}

// main drawing process. call GLController::drawArrays() from this method.
void Capsule::drawMain() {
    cornerRadius = fminf(size.width, size.height) / 2.f;
    RoundedRectangle::drawMain();
}

}    // namespace tears
