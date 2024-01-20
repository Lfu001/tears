//
//  ZStack.cpp
//  tears
//
//  Created by Lfu001 on 2023/12/24.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "ZStack.hpp"

namespace tears {

// destructor
ZStack::~ZStack() {}

// initializer
void ZStack::initialize() {
    layoutDirection = LayoutDirectionZ;
    setAlignment(AlignmentCenter);
}

}    // namespace tears
