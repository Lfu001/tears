---
title: BlendScope
description: a class that set GL blend equation and blend factors 
generator: doxide
---


# BlendScope

**class BlendScope**

a class that set GL blend equation and blend factors

## Variables

| Name | Description |
| ---- | ----------- |
| [blendBackup](#blendBackup) | a backup of blend settings  |

## Functions

| Name | Description |
| ---- | ----------- |
| [BlendScope](#BlendScope) | constructor :material-location-enter: **Parameter** `equation` :    a blend equation :material-location-enter: **Parameter** `factorSrc` :    a blend factor for source :material-location-enter: **Parameter** `factorDst` :    a blend factor for destination  |
| [~BlendScope](#_u007eBlendScope) | destructor  |

## Variable Details

### blendBackup<a name="blendBackup"></a>

!!! variable "BlendSettings blendBackup"

    a backup of blend settings

## Function Details

### BlendScope<a name="BlendScope"></a>

!!! function "BlendScope(BlendEquationType equation, BlendType factorSrc, BlendType factorDst)"

    constructor
    :material-location-enter: **Parameter** `equation`
    :    a blend equation
    :material-location-enter: **Parameter** `factorSrc`
    :    a blend factor for source
    :material-location-enter: **Parameter** `factorDst`
    :    a blend factor for destination

### ~BlendScope<a name="_u007eBlendScope"></a>

!!! function "virtual ~BlendScope()"

    destructor
