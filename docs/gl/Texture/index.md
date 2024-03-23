---
title: Texture
description:  a wrapper class of a GL texture 
generator: doxide
---


# Texture

**class Texture**

 a wrapper class of a GL texture
 


## Variables

| Name | Description |
| ---- | ----------- |
| [name](#name) |  texture name  |
| [size](#size) |  texture size [px]  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Texture](#Texture) |  constructor (from size) :material-location-enter: **Parameter** `width` :    a width of the texture [px] :material-location-enter: **Parameter** `height` :    a height of the texture [px]  |
| [~Texture](#_u007eTexture) |  destructor  |
| [getName](#getName) |  get texture name  |
| [getSize](#getSize) |  get texture size  |

## Variable Details

### name<a name="name"></a>

!!! variable "unsigned int name"

     texture name
    

### size<a name="size"></a>

!!! variable "Size size"

     texture size [px]
    

## Function Details

### Texture<a name="Texture"></a>
!!! function "Texture(int width, int height)"

     constructor (from size)
     :material-location-enter: **Parameter** `width`
    :    a width of the texture [px]
     :material-location-enter: **Parameter** `height`
    :    a height of the texture [px]
    

### getName<a name="getName"></a>
!!! function "unsigned int getName() const"

     get texture name
    

### getSize<a name="getSize"></a>
!!! function "Size getSize() const"

     get texture size
    

### ~Texture<a name="_u007eTexture"></a>
!!! function "virtual ~Texture()"

     destructor
    

