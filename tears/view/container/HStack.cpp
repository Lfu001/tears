//
//  HStack.cpp
//  tears
//
//  Created by Lfu001 on 2023/12/17.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "HStack.hpp"

namespace tears {

// destructor
HStack::~HStack() {}

// initializer
void HStack::initialize() {
    layoutDirection = LayoutDirectionHorizontal;
    setAlignment(AlignmentCenter);
}

}    // namespace tears
