//
//  View.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/19.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "utils/DebugUtil.hpp"
#include "View.hpp"

namespace tears {

using namespace std;

// assignable view ID (initial value)
int64_t View::nextViewId = 0x0;

// default constructor
View::View() {
    assignViewId();
}

/// constructor (with child views)
View::View(initializer_list<unique_ptr<View>> aChildren) {
    assignViewId();
    for (const auto& child: aChildren) {
        if (!child) {
            tears_assert(false);
            continue;
        }
        children.push_back(child);
    }
}

/// destructor
View::~View() {}

// assign view ID
void View::assignViewId() {
    id = nextViewId;
    nextViewId++;
}

}    // namespace tears
