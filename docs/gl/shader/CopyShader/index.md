---
title: CopyShader
description: a shader to copy bound texture 
generator: doxide
---


# CopyShader

**class CopyShader: public Shader**

a shader to copy bound texture

## Functions

| Name | Description |
| ---- | ----------- |
| [loadShader](#loadShader) | load shader  |
| [CopyShader](#CopyShader) | default constructor  |
| [~CopyShader](#_u007eCopyShader) | destructor  |
| [drawCopy](#drawCopy) | draw copy :material-location-enter: **Parameter** `texSrc` :    a texture to copy from :material-location-enter: **Parameter** `texCoord` :    an array of texture coordinates :material-location-enter: **Parameter** `vertices` :    an array of vertices :material-location-enter: **Parameter** `count` :    a length of the array  |

## Function Details

### CopyShader<a name="CopyShader"></a>

!!! function "CopyShader()"

    default constructor

### drawCopy<a name="drawCopy"></a>

!!! function "void drawCopy(Texture&#42; texSrc, const Point texCoord[], Point vertices[], int count) const"

    draw copy
    :material-location-enter: **Parameter** `texSrc`
    :    a texture to copy from
    :material-location-enter: **Parameter** `texCoord`
    :    an array of texture coordinates
    :material-location-enter: **Parameter** `vertices`
    :    an array of vertices
    :material-location-enter: **Parameter** `count`
    :    a length of the array

### loadShader<a name="loadShader"></a>

!!! function "virtual void loadShader() override"

    load shader

### ~CopyShader<a name="_u007eCopyShader"></a>

!!! function "virtual ~CopyShader()"

    destructor
