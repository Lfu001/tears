---
title: Shape
description: a base class of all shapes 
generator: doxide
---


# Shape

**class Shape: public View**

a base class of all shapes

## Variables

| Name | Description |
| ---- | ----------- |
| [blurSigma](#blurSigma) | background color [0]=top-leading, [1]=bottom-leading, [2]=top-trailing, [3]=bottom-trailing the standard deviation of the gaussian function used for blurring. |
| [textureBlurred](#textureBlurred) | a texture for the blurred background  |

## Functions

| Name | Description |
| ---- | ----------- |
| [getVertexShaderSource](#getVertexShaderSource) | get vertex shader source that supports color vertex  |
| [needBlurring](#needBlurring) | check if blurring is enabled  |
| [createBlurredTexture](#createBlurredTexture) | create a texture for the blurred background  |
| [prepareBlurredTexture](#prepareBlurredTexture) | prepare a blurred texture of the view background if blurring is enabled. |
| [Shape](#Shape) | default constructor  |
| [~Shape](#_u007eShape) | destructor  |
| [setBlurSigma](#setBlurSigma) | set blur sigma :material-location-enter: **Parameter** `sigma` :    a standard deviation of the gaussian function. Must be larger than or equal to 0. 0 means no blurring.  |

## Variable Details

### blurSigma<a name="blurSigma"></a>

!!! variable "int blurSigma"

    background color [0]=top-leading, [1]=bottom-leading, [2]=top-trailing, [3]=bottom-trailing
    the standard deviation of the gaussian function used for blurring.

### textureBlurred<a name="textureBlurred"></a>

!!! variable "unique_ptr&lt;Texture&gt; textureBlurred"

    a texture for the blurred background

## Function Details

### Shape<a name="Shape"></a>

!!! function "Shape()"

    default constructor

### createBlurredTexture<a name="createBlurredTexture"></a>

!!! function "Texture&#42; createBlurredTexture()"

    create a texture for the blurred background

### getVertexShaderSource<a name="getVertexShaderSource"></a>

!!! function "const char&#42; getVertexShaderSource() const"

    get vertex shader source that supports color vertex

### needBlurring<a name="needBlurring"></a>

!!! function "bool needBlurring() const"

    check if blurring is enabled

### prepareBlurredTexture<a name="prepareBlurredTexture"></a>

!!! function "Texture&#42; prepareBlurredTexture()"

    prepare a blurred texture of the view background if blurring is enabled.

### setBlurSigma<a name="setBlurSigma"></a>

!!! function "Shape&amp; setBlurSigma(float sigma)"

    set blur sigma
    :material-location-enter: **Parameter** `sigma`
    :    a standard deviation of the gaussian function. Must be larger than or equal to
        0. 0 means no blurring.

### ~Shape<a name="_u007eShape"></a>

!!! function "virtual ~Shape()"

    destructor
