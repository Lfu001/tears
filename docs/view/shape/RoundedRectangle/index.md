---
title: RoundedRectangle
description: a rectangular shape with rounded corners 
generator: doxide
---


# RoundedRectangle

**class RoundedRectangle: public Shape**

a rectangular shape with rounded corners

## Variables

| Name | Description |
| ---- | ----------- |
| [cornerRadius](#cornerRadius) | corner radius (default: 24)  |

## Functions

| Name | Description |
| ---- | ----------- |
| [RoundedRectangle](#RoundedRectangle) | default constructor  |
| [RoundedRectangle](#RoundedRectangle) | constructor from corner radius :material-location-enter: **Parameter** `radius` :    a corner radius  |
| [~RoundedRectangle](#_u007eRoundedRectangle) | destructor  |
| [drawMain](#drawMain) | main drawing process  |
| [setCornerRadius](#setCornerRadius) | set corner radius  |

## Variable Details

### cornerRadius<a name="cornerRadius"></a>

!!! variable "float cornerRadius"

    corner radius (default: 24)

## Function Details

### RoundedRectangle<a name="RoundedRectangle"></a>

!!! function "RoundedRectangle()"

    default constructor

!!! function "RoundedRectangle(float radius)"

    constructor from corner radius
    :material-location-enter: **Parameter** `radius`
    :    a corner radius

### drawMain<a name="drawMain"></a>

!!! function "virtual void drawMain() override"

    main drawing process

### setCornerRadius<a name="setCornerRadius"></a>

!!! function "void setCornerRadius(float radius)"

    set corner radius

### ~RoundedRectangle<a name="_u007eRoundedRectangle"></a>

!!! function "virtual ~RoundedRectangle()"

    destructor
