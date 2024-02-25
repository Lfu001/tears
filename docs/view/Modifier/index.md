---
title: Modifier
description:  modifier collections for View /base 
generator: doxide
---


# Modifier

**class Modifier**

 modifier collections for View
 /base 


## Variables

| Name | Description |
| ---- | ----------- |
| [modifierMap](#modifierMap) |  specified modifiers  |

## Functions

| Name | Description |
| ---- | ----------- |
| [getOffset](#getOffset) |  get offset x and y  |
| [getOffsetX](#getOffsetX) |  get offset x  |
| [getOffsetY](#getOffsetY) |  get offset y  |
| [getAlignment](#getAlignment) |  get alignment  |
| [getPadding](#getPadding) |  get padding :material-location-enter: **Parameter** `edge` :    top, bottom, leading, trailing, vertical or horizontal  |
| [getBorder](#getBorder) |  get border :material-location-enter: **Parameter** `edge` :    top, bottom, leading, trailing, vertical or horizontal  |
| [Modifier](#Modifier) |  constructor  |
| [~Modifier](#_u007eModifier) |  destructor  |
| [setOffset](#setOffset) |  set offset x and y  |
| [setOffsetX](#setOffsetX) |  set offset x  |
| [setOffsetY](#setOffsetY) |  set offset y  |
| [setSize](#setSize) |  set size  |
| [setWidth](#setWidth) |  set width  |
| [setHeight](#setHeight) |  set height  |
| [setWidthRange](#setWidthRange) |  set width range (ignored if width is specified)  |
| [setHeightRange](#setHeightRange) |  set height range (ignored if height is specified)  |
| [setMinWidth](#setMinWidth) |  set minimum width (ignored if width is specified)  |
| [setMinHeight](#setMinHeight) |  set minimum height (ignored if height is specified)  |
| [setMaxWidth](#setMaxWidth) |  set maximum width (ignored if width is specified)  |
| [setMaxHeight](#setMaxHeight) |  set maximum height (ignored if height is specified)  |
| [setWidthRatio](#setWidthRatio) |  set width ratio (ignored if width is specified)  |
| [setHeightRatio](#setHeightRatio) |  set height ratio (ignored if height is specified)  |
| [setLayoutPriority](#setLayoutPriority) |  set layout priority (the higher the value, the higher the priority)  |
| [setAlignment](#setAlignment) |  set alignment  |
| [setPadding](#setPadding) |  set padding  |
| [setBorder](#setBorder) |  set border  |

## Variable Details

### modifierMap<a name="modifierMap"></a>

!!! variable "unordered_map&lt;ModifierType, float&gt; modifierMap"

     specified modifiers
    

## Function Details

### Modifier<a name="Modifier"></a>
!!! function "Modifier()"

     constructor
    

### getAlignment<a name="getAlignment"></a>
!!! function "AlignmentType getAlignment()"

     get alignment
    

### getBorder<a name="getBorder"></a>
!!! function "float getBorder(EdgeType edge)"

     get border
     :material-location-enter: **Parameter** `edge`
    :    top, bottom, leading, trailing, vertical or horizontal
    

### getOffset<a name="getOffset"></a>
!!! function "Point getOffset()"

     get offset x and y
    

### getOffsetX<a name="getOffsetX"></a>
!!! function "float getOffsetX()"

     get offset x
    

### getOffsetY<a name="getOffsetY"></a>
!!! function "float getOffsetY()"

     get offset y
    

### getPadding<a name="getPadding"></a>
!!! function "float getPadding(EdgeType edge)"

     get padding
     :material-location-enter: **Parameter** `edge`
    :    top, bottom, leading, trailing, vertical or horizontal
    

### setAlignment<a name="setAlignment"></a>
!!! function "Modifier&amp; setAlignment(AlignmentType alignment)"

     set alignment
    

### setBorder<a name="setBorder"></a>
!!! function "Modifier&amp; setBorder(EdgeType edge, float val)"

     set border
    

### setHeight<a name="setHeight"></a>
!!! function "Modifier&amp; setHeight(float height)"

     set height
    

### setHeightRange<a name="setHeightRange"></a>
!!! function "Modifier&amp; setHeightRange(float min, float max)"

     set height range (ignored if height is specified)
    

### setHeightRatio<a name="setHeightRatio"></a>
!!! function "Modifier&amp; setHeightRatio(float ratio)"

     set height ratio (ignored if height is specified)
    

### setLayoutPriority<a name="setLayoutPriority"></a>
!!! function "Modifier&amp; setLayoutPriority(float priority)"

     set layout priority (the higher the value, the higher the priority)
    

### setMaxHeight<a name="setMaxHeight"></a>
!!! function "Modifier&amp; setMaxHeight(float max)"

     set maximum height (ignored if height is specified)
    

### setMaxWidth<a name="setMaxWidth"></a>
!!! function "Modifier&amp; setMaxWidth(float max)"

     set maximum width (ignored if width is specified)
    

### setMinHeight<a name="setMinHeight"></a>
!!! function "Modifier&amp; setMinHeight(float min)"

     set minimum height (ignored if height is specified)
    

### setMinWidth<a name="setMinWidth"></a>
!!! function "Modifier&amp; setMinWidth(float min)"

     set minimum width (ignored if width is specified)
    

### setOffset<a name="setOffset"></a>
!!! function "Modifier&amp; setOffset(float x, float y)"

     set offset x and y
    

### setOffsetX<a name="setOffsetX"></a>
!!! function "Modifier&amp; setOffsetX(float x)"

     set offset x
    

### setOffsetY<a name="setOffsetY"></a>
!!! function "Modifier&amp; setOffsetY(float y)"

     set offset y
    

### setPadding<a name="setPadding"></a>
!!! function "Modifier&amp; setPadding(EdgeType edge, float val)"

     set padding
    

### setSize<a name="setSize"></a>
!!! function "Modifier&amp; setSize(float width, float height)"

     set size
    

### setWidth<a name="setWidth"></a>
!!! function "Modifier&amp; setWidth(float width)"

     set width
    

### setWidthRange<a name="setWidthRange"></a>
!!! function "Modifier&amp; setWidthRange(float min, float max)"

     set width range (ignored if width is specified)
    

### setWidthRatio<a name="setWidthRatio"></a>
!!! function "Modifier&amp; setWidthRatio(float ratio)"

     set width ratio (ignored if width is specified)
    

### ~Modifier<a name="_u007eModifier"></a>
!!! function "virtual ~Modifier()"

     destructor
    

