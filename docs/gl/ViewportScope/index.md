---
title: ViewportScope
description: a class that set viewport matrix 
generator: doxide
---


# ViewportScope

**class ViewportScope**

a class that set viewport matrix

## Variables

| Name | Description |
| ---- | ----------- |
| [viewportSizeBackup](#viewportSizeBackup) | a backup of the viewport size  |
| [viewportMatrixBackup](#viewportMatrixBackup) | a backup of the viewport matrix  |

## Functions

| Name | Description |
| ---- | ----------- |
| [ViewportScope](#ViewportScope) | constructor :material-location-enter: **Parameter** `width` :    a viewport width [px] :material-location-enter: **Parameter** `height` :    a viewport height [px]  |
| [~ViewportScope](#_u007eViewportScope) | destructor  |

## Variable Details

### viewportMatrixBackup<a name="viewportMatrixBackup"></a>

!!! variable "AffineTransform viewportMatrixBackup"

    a backup of the viewport matrix

### viewportSizeBackup<a name="viewportSizeBackup"></a>

!!! variable "Size viewportSizeBackup"

    a backup of the viewport size

## Function Details

### ViewportScope<a name="ViewportScope"></a>

!!! function "ViewportScope(int width, int height)"

    constructor
    :material-location-enter: **Parameter** `width`
    :    a viewport width [px]
    :material-location-enter: **Parameter** `height`
    :    a viewport height [px]

### ~ViewportScope<a name="_u007eViewportScope"></a>

!!! function "virtual ~ViewportScope()"

    destructor
