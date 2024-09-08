---
title: Texture
description: a wrapper class of a GL texture 
generator: doxide
---


# Texture

**class Texture**

a wrapper class of a GL texture

## Variables

| Name | Description |
| ---- | ----------- |
| [name](#name) | default texture coordinates texture name  |
| [size](#size) | texture size [px]  |
| [minFilter](#minFilter) | min filter parameter  |
| [magFilter](#magFilter) | mag filter parameter  |
| [wrapS](#wrapS) | wrap S parameter  |
| [wrapT](#wrapT) | wrap T parameter  |

## Functions

| Name | Description |
| ---- | ----------- |
| [setTextureParameter](#setTextureParameter) | set texture parameter  |
| [Texture](#Texture) | constructor (from size) :material-location-enter: **Parameter** `width` :    a width of the texture [px] :material-location-enter: **Parameter** `height` :    a height of the texture [px]  |
| [~Texture](#_u007eTexture) | destructor  |
| [getName](#getName) | get texture name  |
| [getSize](#getSize) | get texture size  |
| [getWidth](#getWidth) | get texture width  |
| [getHeight](#getHeight) | get texture height  |
| [getTextureParameter](#getTextureParameter) | get texture parameter  |

## Variable Details

### magFilter<a name="magFilter"></a>

!!! variable "TextureParameterType magFilter"

    mag filter parameter

### minFilter<a name="minFilter"></a>

!!! variable "TextureParameterType minFilter"

    min filter parameter

### name<a name="name"></a>

!!! variable "unsigned int name"

    default texture coordinates
    texture name

### size<a name="size"></a>

!!! variable "Size size"

    texture size [px]

### wrapS<a name="wrapS"></a>

!!! variable "TextureParameterType wrapS"

    wrap S parameter

### wrapT<a name="wrapT"></a>

!!! variable "TextureParameterType wrapT"

    wrap T parameter

## Function Details

### Texture<a name="Texture"></a>

!!! function "Texture(int width, int height)"

    constructor (from size)
    :material-location-enter: **Parameter** `width`
    :    a width of the texture [px]
    :material-location-enter: **Parameter** `height`
    :    a height of the texture [px]

### getHeight<a name="getHeight"></a>

!!! function "float getHeight() const"

    get texture height

### getName<a name="getName"></a>

!!! function "unsigned int getName() const"

    get texture name

### getSize<a name="getSize"></a>

!!! function "Size getSize() const"

    get texture size

### getTextureParameter<a name="getTextureParameter"></a>

!!! function "TextureParameterType getTextureParameter(TextureParameterNameType name) const"

    get texture parameter

### getWidth<a name="getWidth"></a>

!!! function "float getWidth() const"

    get texture width

### setTextureParameter<a name="setTextureParameter"></a>

!!! function "void setTextureParameter(TextureParameterNameType name, TextureParameterType param)"

    set texture parameter

### ~Texture<a name="_u007eTexture"></a>

!!! function "virtual ~Texture()"

    destructor
