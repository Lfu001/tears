---
title: BlurShader
description: a shader to blur texture
reference: https://drafts.fxtf.org/filter-effects/#feGaussianBlurElement 
generator: doxide
---


# BlurShader

**class BlurShader: public Shader**

a shader to blur texture

reference: <https://drafts.fxtf.org/filter-effects/#feGaussianBlurElement>

## Functions

| Name | Description |
| ---- | ----------- |
| [loadShader](#loadShader) | load shader  |
| [calculateKernelSize](#calculateKernelSize) | calculate kernel size [px] :material-location-enter: **Parameter** `sigma` :    a standard deviation :material-keyboard-return: **Return** :    a kernel size rounded to the nearest integer  |
| [boxBlur1D](#boxBlur1D) | 1D box blur :material-location-enter: **Parameter** `isVertical` :    a flag to indicate the direction of the box blur :material-location-enter: **Parameter** `kernelInterval` :    a kernel interval [px]. The current pixel coordinate corresponds to 0. :material-location-enter: **Parameter** `overwriteDst` :    a flag to force overwrite the destination texture :material-location-enter: **Parameter** `textureSrc` :    a source texture :material-location-enter: **Parameter** `texCoordSrc` :    an array of texture coordinates :material-location-enter: **Parameter** `textureDst` :    a destination texture :material-location-enter: **Parameter** `vertices` :    an array of vertices :material-location-enter: **Parameter** `count` :    the number of elements in the vertices  |
| [BlurShader](#BlurShader) | default constructor  |
| [~BlurShader](#_u007eBlurShader) | destructor  |
| [drawBlur](#drawBlur) | draw blurred texture. |

## Function Details

### BlurShader<a name="BlurShader"></a>

!!! function "BlurShader()"

    default constructor

### boxBlur1D<a name="boxBlur1D"></a>

!!! function "void boxBlur1D( bool isVertical, Interval kernelInterval, bool overwriteDst, Texture&#42; textureSrc, const Point texCoordSrc[], Texture&#42; textureDst, const Point vertices[], int count)"

    1D box blur
    :material-location-enter: **Parameter** `isVertical`
    :    a flag to indicate the direction of the box blur
    :material-location-enter: **Parameter** `kernelInterval`
    :    a kernel interval [px]. The current pixel coordinate corresponds to 0.
    :material-location-enter: **Parameter** `overwriteDst`
    :    a flag to force overwrite the destination texture
    :material-location-enter: **Parameter** `textureSrc`
    :    a source texture
    :material-location-enter: **Parameter** `texCoordSrc`
    :    an array of texture coordinates
    :material-location-enter: **Parameter** `textureDst`
    :    a destination texture
    :material-location-enter: **Parameter** `vertices`
    :    an array of vertices
    :material-location-enter: **Parameter** `count`
    :    the number of elements in the vertices

### calculateKernelSize<a name="calculateKernelSize"></a>

!!! function "int calculateKernelSize(float sigma) const"

    calculate kernel size [px]
    :material-location-enter: **Parameter** `sigma`
    :    a standard deviation
    :material-keyboard-return: **Return**
    :    a kernel size rounded to the nearest integer

### drawBlur<a name="drawBlur"></a>

!!! function "void drawBlur( float sigma, Texture&#42; textureSrc, const Point texCoordSrc[], Size bboxSizeSrc, Texture&#42; textureDst, const Point vertices[], int count)"

    draw blurred texture.
    :material-location-enter: **Parameter** `sigma`
    :    the standard deviation of the gaussian fuction
    :material-location-enter: **Parameter** `textureSrc`
    :    a texture to blur
    :material-location-enter: **Parameter** `texCoordSrc`
    :    an array of texture coordinates of the source texture
    :material-location-enter: **Parameter** `bboxSizeSrc`
    :    a size [px] of the bbox to be blurred
    :material-location-enter: **Parameter** `textureDst`
    :    a destination texture where the blurred result is drawn
    :material-location-enter: **Parameter** `vertices`
    :    an array of vertices
    :material-location-enter: **Parameter** `count`
    :    the number of elements in vertices

### loadShader<a name="loadShader"></a>

!!! function "virtual void loadShader() override"

    load shader

### ~BlurShader<a name="_u007eBlurShader"></a>

!!! function "virtual ~BlurShader()"

    destructor
