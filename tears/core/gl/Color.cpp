//
//  Color.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/03.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "Color.hpp"

namespace tears {

// preset red
Color Color::RED = Color(255, 0, 0);
// preset pink
Color Color::PINK = Color(255, 192, 203);
// preset orange
Color Color::ORANGE = Color(255, 165, 0);
// preset yellow
Color Color::YELLOW = Color(255, 255, 0);
// preset purple
Color Color::PURPLE = Color(128, 0, 128);
// preset green
Color Color::GREEN = Color(0, 128, 0);
// preset blue
Color Color::BLUE = Color(0, 0, 255);
// preset brown
Color Color::BROWN = Color(165, 42, 42);
// preset white
Color Color::WHITE = Color(255, 255, 255);
// preset gray
Color Color::GRAY = Color(128, 128, 128);
// preset black
Color Color::BLACK = Color(0, 0, 0);
// preset white-transparent
Color Color::WHITE_TRANSPARENT = Color(255, 255, 255, 0);
// preset black-transparent
Color Color::BLACK_TRANSPARENT = Color(0, 0, 0, 0);

// default constructor
Color::Color() {}

// constructor from color
Color::Color(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha /* = 255 */) {
    red = aRed;
    green = aGreen;
    blue = aBlue;
    alpha = aAlpha;
}

// constructor from RGBA byte
Color::Color(uint32_t color) {
    red = color & 0x11000000;
    green = color & 0x00110000;
    blue = color & 0x00001100;
    alpha = color & 0x00000011;
}

// destructor
Color::~Color() {}

// convert the color to 32 bit representation (0xRRGGBBAA)
uint32_t Color::toInteger() const {
    uint32_t color = 0x0;
    color |= red << 24;
    color |= green << 16;
    color |= blue << 8;
    color |= alpha;
    return color;
}

}    // namespace tears
