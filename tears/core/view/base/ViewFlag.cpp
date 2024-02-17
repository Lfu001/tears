//
//  ViewFlag.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "ViewFlag.hpp"

namespace tears {

using namespace std;

/// default flag state (all flags are false)
constexpr int64_t DEFAULT_FLAGS_STATE = 0x0;

// constructor
ViewFlag::ViewFlag() {
    resetFlagsDefault();
}

// destructor
ViewFlag::~ViewFlag() {}

// reset all the flags to false
void ViewFlag::resetFlagsDefault() {
    flags = DEFAULT_FLAGS_STATE;
    setIsVisible(true);
    setIsDirtyLayout(true);
}

// get whether the View is visible
bool ViewFlag::getIsVisible() const {
    return (bool)(flags & FlagVisible);
}

// set whether the View is visible
void ViewFlag::setIsVisible(bool b) {
    if (b) {
        flags |= FlagVisible;
    } else {
        flags &= ~FlagVisible;
    }
}

// get whether the View layout is dirty
bool ViewFlag::getIsDirtyLayout() const {
    return (bool)(flags & FlagDirtyLayout);
}

// set whether the View layout is dirty
void ViewFlag::setIsDirtyLayout(bool b) {
    if (b) {
        flags |= FlagDirtyLayout;
    } else {
        flags &= ~FlagDirtyLayout;
    }
}

}    // namespace tears
