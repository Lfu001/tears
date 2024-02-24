//
//  Shape.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "Shape.hpp"

namespace tears {

// default constructor
Shape::Shape() {}

// destructor
Shape::~Shape() {}

// fill the shape with specified color
Shape& Shape::fill(Color color) {
    fillColor = std::move(color);
    return *this;
}

}    // namespace tears
