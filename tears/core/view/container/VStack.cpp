//
//  VStack.cpp
//  tears
//
//  Created by Lfu001 on 2023/12/17.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "VStack.hpp"

namespace tears {

// destructor
VStack::~VStack() {}

// initializer
void VStack::initialize() {
    layoutDirection = LayoutDirectionVertical;
    setAlignment(AlignmentCenter);
}

}    // namespace tears
