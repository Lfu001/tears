//
//  Interval.cpp
//  tears
//
//  Created by Lfu001 on 2024/07/14.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "utils/DebugUtil.hpp"
#include "Interval.hpp"

namespace tears {
using namespace std;

// default constructor
Interval::Interval() {}

// constructor from endpoints
Interval::Interval(
    float leftVal,
    float rightVal,
    bool leftClosed /* = true */,
    bool rightClosed /* = true */) {
    tears_assert(leftVal <= rightVal);
    left = leftVal;
    right = rightVal;
    isLeftClosed = leftClosed;
    isRightClosed = rightClosed;
}

// copy constructor
Interval::Interval(const Interval& other) {
    left = other.left;
    right = other.right;
    isLeftClosed = other.isLeftClosed;
    isRightClosed = other.isRightClosed;
}

// move constructor
Interval::Interval(Interval&& other) {
    left = other.left;
    right = other.right;
    isLeftClosed = other.isLeftClosed;
    isRightClosed = other.isRightClosed;
}

// destructor
Interval::~Interval() {}

// copy assignment
Interval& Interval::operator=(const Interval& other) {
    left = other.left;
    right = other.right;
    isLeftClosed = other.isLeftClosed;
    isRightClosed = other.isRightClosed;
    return *this;
}

// move assignment
Interval& Interval::operator=(Interval&& other) {
    left = other.left;
    right = other.right;
    isLeftClosed = other.isLeftClosed;
    isRightClosed = other.isRightClosed;
    return *this;
}

// equality operator
bool Interval::operator==(const Interval& other) const {
    return left == other.left && right == other.right && isLeftClosed == other.isLeftClosed
           && isRightClosed == other.isRightClosed;
}

// inequality operator
bool Interval::operator!=(const Interval& other) const {
    return !(*this == other);
}

// set interval
void Interval::set(
    float leftVal,
    float rightVal,
    bool leftClosed /* = true */,
    bool rightClosed /* = true */) {
    tears_assert(leftVal <= rightVal);
    left = leftVal;
    right = rightVal;
    isLeftClosed = leftClosed;
    isRightClosed = rightClosed;
}

// get supremum
float Interval::getSupremum() const {
    return right;
}

// get maximum
optional<float> Interval::getMaximum() const {
    if (isRightClosed) {
        return right;
    } else {
        return nullopt;
    }
}

// get infimum
float Interval::getInfimum() const {
    return left;
}

// get minimum
optional<float> Interval::getMinimum() const {
    if (isLeftClosed) {
        return left;
    } else {
        return nullopt;
    }
}

// whether the interval contains the value
bool Interval::contains(float value) const {
    if (isLeftClosed) {
        if (isRightClosed) {    // [left, right]
            return left <= value && value <= right;
        } else {                // [left, right)
            return left <= value && value < right;
        }
    } else {
        if (isRightClosed) {    // (left, right]
            return left < value && value <= right;
        } else {                // (left, right)
            return left < value && value < right;
        }
    }
}

}    // namespace tears
