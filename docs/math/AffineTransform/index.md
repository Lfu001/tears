---
title: AffineTransform
description:  an affine transform matrix for 2D graphics 
generator: doxide
---


# AffineTransform

**class AffineTransform: public Matrix**

 an affine transform matrix for 2D graphics
 


## Functions

| Name | Description |
| ---- | ----------- |
| [AffineTransform](#AffineTransform) |  default constructor  |
| [~AffineTransform](#_u007eAffineTransform) |  destructor  |
| [translate](#translate) |  translate :material-location-enter: **Parameter** `matrix` :    a affine transform matrix to concatenate translation matrix :material-location-enter: **Parameter** `offset` :    an offset of translation matrix  |
| [translate](#translate) |  translate inplace :material-location-enter: **Parameter** `offset` :    an offset of translation matrix  |
| [scale](#scale) |  scale :material-location-enter: **Parameter** `matrix` :    a affine transform matrix to concatenate scaling matrix :material-location-enter: **Parameter** `factor` :    a factor of scaling matrix  |
| [scale](#scale) |  scale inplace :material-location-enter: **Parameter** `factor` :    a factor of scaling matrix  |
| [rotate](#rotate) |  rotate :material-location-enter: **Parameter** `matrix` :    a affine transform matrix to concatenate rotation matrix :material-location-enter: **Parameter** `angle` :    an angle of rotation matrix. the unit is [°].  |
| [rotate](#rotate) |  rotate inplace :material-location-enter: **Parameter** `angle` :    an angle of rotation matrix. the unit is [°].  |
| [reflectX](#reflectX) |  reflect about the line y=0 :material-location-enter: **Parameter** `matrix` :    a affine transform matrix to concatenate reflection matrix  |
| [reflectX](#reflectX) |  reflect about the line y=0 inplace  |
| [reflectY](#reflectY) |  reflect about the line x=0 :material-location-enter: **Parameter** `matrix` :    a affine transform matrix to concatenate reflection matrix  |
| [reflectY](#reflectY) |  reflect about the line x=0 inplace  |

## Function Details

### AffineTransform<a name="AffineTransform"></a>
!!! function "AffineTransform()"

     default constructor
    

### reflectX<a name="reflectX"></a>
!!! function "static AffineTransform reflectX(const AffineTransform&amp; matrix)"

     reflect about the line y=0
     :material-location-enter: **Parameter** `matrix`
    :    a affine transform matrix to concatenate reflection matrix
    

!!! function "void reflectX()"

     reflect about the line y=0 inplace
    

### reflectY<a name="reflectY"></a>
!!! function "static AffineTransform reflectY(const AffineTransform&amp; matrix)"

     reflect about the line x=0
     :material-location-enter: **Parameter** `matrix`
    :    a affine transform matrix to concatenate reflection matrix
    

!!! function "void reflectY()"

     reflect about the line x=0 inplace
    

### rotate<a name="rotate"></a>
!!! function "static AffineTransform rotate(const AffineTransform&amp; matrix, float angle)"

     rotate
     :material-location-enter: **Parameter** `matrix`
    :    a affine transform matrix to concatenate rotation matrix
     :material-location-enter: **Parameter** `angle`
    :    an angle of rotation matrix. the unit is [°].
    

!!! function "void rotate(float angle)"

     rotate inplace
     :material-location-enter: **Parameter** `angle`
    :    an angle of rotation matrix. the unit is [°].
    

### scale<a name="scale"></a>
!!! function "static AffineTransform scale(const AffineTransform&amp; matrix, Size factor)"

     scale
     :material-location-enter: **Parameter** `matrix`
    :    a affine transform matrix to concatenate scaling matrix
     :material-location-enter: **Parameter** `factor`
    :    a factor of scaling matrix
    

!!! function "void scale(Size factor)"

     scale inplace
     :material-location-enter: **Parameter** `factor`
    :    a factor of scaling matrix
    

### translate<a name="translate"></a>
!!! function "static AffineTransform translate(const AffineTransform&amp; matrix, Size offset)"

     translate
     :material-location-enter: **Parameter** `matrix`
    :    a affine transform matrix to concatenate translation matrix
     :material-location-enter: **Parameter** `offset`
    :    an offset of translation matrix
    

!!! function "void translate(Size offset)"

     translate inplace
     :material-location-enter: **Parameter** `offset`
    :    an offset of translation matrix
    

### ~AffineTransform<a name="_u007eAffineTransform"></a>
!!! function "virtual ~AffineTransform()"

     destructor
    

