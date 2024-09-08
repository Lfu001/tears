---
title: RoundedRectangleShader
description: a shader to draw rounded rectangle shape 
generator: doxide
---


# RoundedRectangleShader

**class RoundedRectangleShader: public Shader**

a shader to draw rounded rectangle shape

## Functions

| Name | Description |
| ---- | ----------- |
| [loadShader](#loadShader) | load shader  |
| [RoundedRectangleShader](#RoundedRectangleShader) | default constructor  |
| [~RoundedRectangleShader](#_u007eRoundedRectangleShader) | destructor  |
| [drawRoundedRectangle](#drawRoundedRectangle) | draw rounded rectangle :material-location-enter: **Parameter** `center` :    a center of the rounded rectangle :material-location-enter: **Parameter** `cornerRadius` :    a radius of the corner :material-location-enter: **Parameter** `halfSize` :    a half size of the rectangle :material-location-enter: **Parameter** `textureSrc` :    a texture to draw inside the shape. if nullptr, transparent texture will be drawn. :material-location-enter: **Parameter** `texCoordSrc` :    an array of texture coordinates :material-location-enter: **Parameter** `vertices` :    an array of vertices :material-location-enter: **Parameter** `colors` :    an array of colors :material-location-enter: **Parameter** `count` :    a length of the array  |

## Function Details

### RoundedRectangleShader<a name="RoundedRectangleShader"></a>

!!! function "RoundedRectangleShader()"

    default constructor

### drawRoundedRectangle<a name="drawRoundedRectangle"></a>

!!! function "void drawRoundedRectangle( Point center, float cornerRadius, Size halfSize, Texture&#42; textureSrc, const Point texCoordSrc[], Point vertices[], Color colors[], int count) const"

    draw rounded rectangle
    :material-location-enter: **Parameter** `center`
    :    a center of the rounded rectangle
    :material-location-enter: **Parameter** `cornerRadius`
    :    a radius of the corner
    :material-location-enter: **Parameter** `halfSize`
    :    a half size of the rectangle
    :material-location-enter: **Parameter** `textureSrc`
    :    a texture to draw inside the shape. if nullptr, transparent texture will
        be drawn.
    :material-location-enter: **Parameter** `texCoordSrc`
    :    an array of texture coordinates
    :material-location-enter: **Parameter** `vertices`
    :    an array of vertices
    :material-location-enter: **Parameter** `colors`
    :    an array of colors
    :material-location-enter: **Parameter** `count`
    :    a length of the array

### loadShader<a name="loadShader"></a>

!!! function "virtual void loadShader() override"

    load shader

### ~RoundedRectangleShader<a name="_u007eRoundedRectangleShader"></a>

!!! function "virtual ~RoundedRectangleShader()"

    destructor
