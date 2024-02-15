//
//  Size.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/15.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "math/AffineTransform.hpp"
#include "Size.hpp"

namespace tears {

// default constructor
Size::Size() {}

// constructor from width and height
Size::Size(float aWidth, float aHeight) {
    width = aWidth;
    height = aHeight;
}

// destructor
Size::~Size() {}

// apply transforms
Size Size::applyTransform(AffineTransform affine) {
    float ow = affine[0][0] * width + affine[0][1] * height + affine[0][2];
    float oh = affine[1][0] * width + affine[1][1] * height + affine[1][2];
    return Size(ow, oh);
}

}    // namespace tears
