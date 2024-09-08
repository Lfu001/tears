---
title: EllipseShader
description: a shader to draw ellipse shape 
generator: doxide
---


# EllipseShader

**class EllipseShader: public Shader**

a shader to draw ellipse shape

## Functions

| Name | Description |
| ---- | ----------- |
| [loadShader](#loadShader) | load shader  |
| [EllipseShader](#EllipseShader) | default constructor  |
| [~EllipseShader](#_u007eEllipseShader) | destructor  |
| [drawEllipse](#drawEllipse) | draw ellipse :material-location-enter: **Parameter** `center` :    a center of the ellipse :material-location-enter: **Parameter** `semiAxisX` :    a semi axis in x-direction of the ellipse :material-location-enter: **Parameter** `semiAxisY` :    a semi axis in y-direction of the ellipse :material-location-enter: **Parameter** `textureSrc` :    a texture to draw inside the shape. if nullptr, transparent texture will be drawn. :material-location-enter: **Parameter** `texCoordSrc` :    an array of texture coordinates :material-location-enter: **Parameter** `vertices` :    an array of vertices :material-location-enter: **Parameter** `colors` :    an array of colors :material-location-enter: **Parameter** `count` :    a length of the array  |

## Function Details

### EllipseShader<a name="EllipseShader"></a>

!!! function "EllipseShader()"

    default constructor

### drawEllipse<a name="drawEllipse"></a>

!!! function "void drawEllipse( Point center, float semiAxisX, float semiAxisY, Texture&#42; textureSrc, const Point texCoordSrc[], Point vertices[], Color colors[], int count) const"

    draw ellipse
    :material-location-enter: **Parameter** `center`
    :    a center of the ellipse
    :material-location-enter: **Parameter** `semiAxisX`
    :    a semi axis in x-direction of the ellipse
    :material-location-enter: **Parameter** `semiAxisY`
    :    a semi axis in y-direction of the ellipse
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

### ~EllipseShader<a name="_u007eEllipseShader"></a>

!!! function "virtual ~EllipseShader()"

    destructor
