//
//  CallbackScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/03.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "CallbackScope.hpp"

namespace tears {

using namespace std;

/// constructor
CallbackScope::CallbackScope(function<void()> aCallback) {
    callback = aCallback;
}

/// destructor
CallbackScope::~CallbackScope() noexcept {
    try {
        if (callback) {
            callback();
        }
    } catch (...) {}
}

}    // namespace tears
