---
title: RectangleShader
description: a shader to draw rectangle shape 
generator: doxide
---


# RectangleShader

**class RectangleShader: public Shader**

a shader to draw rectangle shape

## Functions

| Name | Description |
| ---- | ----------- |
| [loadShader](#loadShader) | load shader  |
| [RectangleShader](#RectangleShader) | default constructor  |
| [~RectangleShader](#_u007eRectangleShader) | destructor  |
| [drawRectangle](#drawRectangle) | draw rectangle :material-location-enter: **Parameter** `textureSrc` :    a texture to draw inside the shape. if nullptr, transparent texture will be drawn :material-location-enter: **Parameter** `texCoordSrc` :    an array of texture coordinates :material-location-enter: **Parameter** `vertices` :    an array of vertices :material-location-enter: **Parameter** `colors` :    an array of colors :material-location-enter: **Parameter** `count` :    a length of the array  |

## Function Details

### RectangleShader<a name="RectangleShader"></a>

!!! function "RectangleShader()"

    default constructor

### drawRectangle<a name="drawRectangle"></a>

!!! function "void drawRectangle( Texture&#42; textureSrc, const Point texCoordSrc[], Point vertices[], Color colors[], int count) const"

    draw rectangle
    :material-location-enter: **Parameter** `textureSrc`
    :    a texture to draw inside the shape. if nullptr, transparent texture will
        be drawn
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

### ~RectangleShader<a name="_u007eRectangleShader"></a>

!!! function "virtual ~RectangleShader()"

    destructor
