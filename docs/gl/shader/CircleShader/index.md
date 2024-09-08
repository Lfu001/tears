---
title: CircleShader
description: a shader to draw circle shape 
generator: doxide
---


# CircleShader

**class CircleShader: public Shader**

a shader to draw circle shape

## Functions

| Name | Description |
| ---- | ----------- |
| [loadShader](#loadShader) | load shader  |
| [CircleShader](#CircleShader) | default constructor  |
| [~CircleShader](#_u007eCircleShader) | destructor  |
| [drawCircle](#drawCircle) | draw circle :material-location-enter: **Parameter** `center` :    a center of the circle :material-location-enter: **Parameter** `radius` :    a radius of the circle :material-location-enter: **Parameter** `vertices` :    an array of vertices :material-location-enter: **Parameter** `textureSrc` :    a texture to draw inside the shape. if nullptr, transparent texture will be drawn. :material-location-enter: **Parameter** `texCoordSrc` :    an array of texture coordinates :material-location-enter: **Parameter** `colors` :    an array of colors :material-location-enter: **Parameter** `count` :    a length of the array  |

## Function Details

### CircleShader<a name="CircleShader"></a>

!!! function "CircleShader()"

    default constructor

### drawCircle<a name="drawCircle"></a>

!!! function "void drawCircle( Point center, float radius, const Point vertices[], Texture&#42; textureSrc, const Point texCoordSrc[], const Color colors[], int count) const"

    draw circle
    :material-location-enter: **Parameter** `center`
    :    a center of the circle
    :material-location-enter: **Parameter** `radius`
    :    a radius of the circle
    :material-location-enter: **Parameter** `vertices`
    :    an array of vertices
    :material-location-enter: **Parameter** `textureSrc`
    :    a texture to draw inside the shape. if nullptr, transparent texture will
        be drawn.
    :material-location-enter: **Parameter** `texCoordSrc`
    :    an array of texture coordinates
    :material-location-enter: **Parameter** `colors`
    :    an array of colors
    :material-location-enter: **Parameter** `count`
    :    a length of the array

### loadShader<a name="loadShader"></a>

!!! function "virtual void loadShader() override"

    load shader

### ~CircleShader<a name="_u007eCircleShader"></a>

!!! function "virtual ~CircleShader()"

    destructor
