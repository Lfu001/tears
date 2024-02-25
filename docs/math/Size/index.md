---
title: Size
description:  A structure that contains width and height values 
generator: doxide
---


# Size

**struct Size: public Transformable&lt;Size&gt;**

 A structure that contains width and height values
 


## Variables

| Name | Description |
| ---- | ----------- |
| [width](#width) |  a width  |
| [height](#height) |  a height  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Size](#Size) |  default constructor  |
| [Size](#Size) |  constructor from width and height  |
| [~Size](#_u007eSize) |  destructor  |
| [applyTransform](#applyTransform) |  apply transforms  |

## Variable Details

### height<a name="height"></a>

!!! variable "float height"

     a height
    

### width<a name="width"></a>

!!! variable "float width"

     a width
    

## Function Details

### Size<a name="Size"></a>
!!! function "Size()"

     default constructor
    

!!! function "Size(float aWidth, float aHeight)"

     constructor from width and height
    

### applyTransform<a name="applyTransform"></a>
!!! function "virtual Size applyTransform(AffineTransform affine) override"

     apply transforms
    

### ~Size<a name="_u007eSize"></a>
!!! function "virtual ~Size()"

     destructor
    

