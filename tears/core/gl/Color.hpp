//
//  Color.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/03.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <cstdint>

namespace tears {

/// a color
class Color {
public:
    /// red
    uint8_t red = 0x0;
    /// green
    uint8_t green = 0x0;
    /// blue
    uint8_t blue = 0x0;
    /// alpha
    uint8_t alpha = 0x0;

public:
    /// preset red
    static Color RED;
    /// preset pink
    static Color PINK;
    /// preset orange
    static Color ORANGE;
    /// preset yellow
    static Color YELLOW;
    /// preset purple
    static Color PURPLE;
    /// preset green
    static Color GREEN;
    /// preset blue
    static Color BLUE;
    /// preset brown
    static Color BROWN;
    /// preset white
    static Color WHITE;
    /// preset gray
    static Color GRAY;
    /// preset black
    static Color BLACK;
    /// preset white-transparent
    static Color WHITE_TRANSPARENT;
    /// preset black-transparent
    static Color BLACK_TRANSPARENT;

public:
    /// default constructor
    Color();
    /// constructor from color
    /// @param aRed red value
    /// @param aGreen green value
    /// @param aBlue blue value
    /// @param aAlpha alpha value. default is 255.
    Color(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha = 255);
    /// constructor from RGBA byte
    /// @param color 32 bit integer for each 8 bit represents R, G, B, A respectively
    Color(uint32_t color);
    /// destructor
    virtual ~Color();

public:
    /// convert the color to 32 bit representation (0xRRGGBBAA)
    uint32_t toInteger() const;
};

}    // namespace tears

#endif /* Color_hpp */
