---
title: Color
description: a color 
generator: doxide
---


# Color

**class Color**

a color

## Variables

| Name | Description |
| ---- | ----------- |
| [red](#red) | red value  |
| [green](#green) | green value  |
| [blue](#blue) | blue value  |
| [alpha](#alpha) | alpha value  |
| [RED](#RED) | preset red  |
| [PINK](#PINK) | preset pink  |
| [ORANGE](#ORANGE) | preset orange  |
| [YELLOW](#YELLOW) | preset yellow  |
| [PURPLE](#PURPLE) | preset purple  |
| [GREEN](#GREEN) | preset green  |
| [BLUE](#BLUE) | preset blue  |
| [BROWN](#BROWN) | preset brown  |
| [WHITE](#WHITE) | preset white  |
| [GRAY](#GRAY) | preset gray  |
| [BLACK](#BLACK) | preset black  |
| [WHITE_TRANSPARENT](#WHITE_TRANSPARENT) | preset white-transparent  |
| [BLACK_TRANSPARENT](#BLACK_TRANSPARENT) | preset black-transparent  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Color](#Color) | default constructor  |
| [Color](#Color) | constructor from color :material-location-enter: **Parameter** `aRed` :    red value :material-location-enter: **Parameter** `aGreen` :    green value :material-location-enter: **Parameter** `aBlue` :    blue value :material-location-enter: **Parameter** `aAlpha` :    alpha value. default is 255.  |
| [Color](#Color) | constructor from RGBA byte :material-location-enter: **Parameter** `color` :    32 bit integer for each 8 bit represents R, G, B, A respectively  |
| [~Color](#_u007eColor) | destructor  |
| [toInteger](#toInteger) | convert the color to 32 bit representation (0xRRGGBBAA)  |
| [toNormalizedString](#toNormalizedString) | normalize the color to [0, 1] and convert it to string :material-keyboard-return: **Return** :    `vec4(r', g', b', a')` where x' = x / 255  |

## Variable Details

### BLACK<a name="BLACK"></a>

!!! variable "static Color BLACK"

    preset black

### BLACK_TRANSPARENT<a name="BLACK_TRANSPARENT"></a>

!!! variable "static Color BLACK_TRANSPARENT"

    preset black-transparent

### BLUE<a name="BLUE"></a>

!!! variable "static Color BLUE"

    preset blue

### BROWN<a name="BROWN"></a>

!!! variable "static Color BROWN"

    preset brown

### GRAY<a name="GRAY"></a>

!!! variable "static Color GRAY"

    preset gray

### GREEN<a name="GREEN"></a>

!!! variable "static Color GREEN"

    preset green

### ORANGE<a name="ORANGE"></a>

!!! variable "static Color ORANGE"

    preset orange

### PINK<a name="PINK"></a>

!!! variable "static Color PINK"

    preset pink

### PURPLE<a name="PURPLE"></a>

!!! variable "static Color PURPLE"

    preset purple

### RED<a name="RED"></a>

!!! variable "static Color RED"

    preset red

### WHITE<a name="WHITE"></a>

!!! variable "static Color WHITE"

    preset white

### WHITE_TRANSPARENT<a name="WHITE_TRANSPARENT"></a>

!!! variable "static Color WHITE_TRANSPARENT"

    preset white-transparent

### YELLOW<a name="YELLOW"></a>

!!! variable "static Color YELLOW"

    preset yellow

### alpha<a name="alpha"></a>

!!! variable "uint8_t alpha"

    alpha value

### blue<a name="blue"></a>

!!! variable "uint8_t blue"

    blue value

### green<a name="green"></a>

!!! variable "uint8_t green"

    green value

### red<a name="red"></a>

!!! variable "uint8_t red"

    red value

## Function Details

### Color<a name="Color"></a>

!!! function "Color()"

    default constructor

!!! function "Color(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha = 255)"

    constructor from color
    :material-location-enter: **Parameter** `aRed`
    :    red value
    :material-location-enter: **Parameter** `aGreen`
    :    green value
    :material-location-enter: **Parameter** `aBlue`
    :    blue value
    :material-location-enter: **Parameter** `aAlpha`
    :    alpha value. default is 255.

!!! function "Color(uint32_t color)"

    constructor from RGBA byte
    :material-location-enter: **Parameter** `color`
    :    32 bit integer for each 8 bit represents R, G, B, A respectively

### toInteger<a name="toInteger"></a>

!!! function "uint32_t toInteger() const"

    convert the color to 32 bit representation (0xRRGGBBAA)

### toNormalizedString<a name="toNormalizedString"></a>

!!! function "string toNormalizedString() const"

    normalize the color to [0, 1] and convert it to string
    :material-keyboard-return: **Return**
    :    `vec4(r', g', b', a')` where x' = x / 255

### ~Color<a name="_u007eColor"></a>

!!! function "~Color()"

    destructor
