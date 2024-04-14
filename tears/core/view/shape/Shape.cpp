//
//  Shape.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "Shape.hpp"

namespace tears {

/// a maximum value of the blur strength
constexpr int MAX_BLUR_STRENGTH = 100;
/// a minimum value of th blur strength
constexpr int MIN_BLUR_STRENGTH = 0;

// default constructor
Shape::Shape() {}

// destructor
Shape::~Shape() {}

// get vertex shader source that supports color vertex
const char* Shape::getVertexShaderSource() const {
    const char* src = "uniform mat3 uMatrixMVP;"
                      "uniform mat3 uMatrixU;"
                      "attribute vec2 aPosition;"
                      "attribute vec4 aColor;"
                      "varying vec4 vColor;"
                      "void main() {"
                      "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
                      "    vColor = aColor;"
                      "}";
    return src;
}

// set background color
Shape& Shape::setBackgroundColor(Color color, EdgeType edge /* = EdgeAll */) {
    switch (edge) {
        case EdgeAll:
            backgroundColor[0] = color;
            backgroundColor[1] = color;
            backgroundColor[2] = color;
            backgroundColor[3] = color;
            break;
        case EdgeTop:
            backgroundColor[0] = color;
            backgroundColor[2] = color;
            break;
        case EdgeBottom:
            backgroundColor[1] = color;
            backgroundColor[3] = color;
            break;
        case EdgeLeading:
            backgroundColor[0] = color;
            backgroundColor[1] = color;
            break;
        case EdgeTrailing:
            backgroundColor[2] = color;
            backgroundColor[3] = color;
            break;
        case EdgeTopLeading:
            backgroundColor[0] = color;
            break;
        case EdgeBottomLeading:
            backgroundColor[1] = color;
            break;
        case EdgeTopTrailing:
            backgroundColor[2] = color;
            break;
        case EdgeBottomTrailing:
            backgroundColor[3] = color;
            break;
        default:
            tears_assert(false);
    }
    return *this;
}

// set blur strength
Shape& Shape::setBlurStrength(int strength) {
    if (MIN_BLUR_STRENGTH <= strength
        && strength <= MAX_BLUR_STRENGTH) {    /// if the specified strength is in the correct range
        blurStrength = strength;
    } else {
        tears_assert(false);
        /// clamp to available range edge
        blurStrength = max(MIN_BLUR_STRENGTH, min(strength, MAX_BLUR_STRENGTH));
    }
    return *this;
}

}    // namespace tears
