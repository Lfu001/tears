---
title: BlendSettings
description: A structure of blend equation and blend factors 
generator: doxide
---


# BlendSettings

**struct BlendSettings**

A structure of blend equation and blend factors

## Variables

| Name | Description |
| ---- | ----------- |
| [equation](#equation) | blend equation  |
| [factorSrc](#factorSrc) | blend factor for source  |
| [factorDst](#factorDst) | blend factor for destination  |

## Functions

| Name | Description |
| ---- | ----------- |
| [BlendSettings](#BlendSettings) | default constructor  |
| [BlendSettings](#BlendSettings) | constructor :material-location-enter: **Parameter** `aEquation` :    a blend equation :material-location-enter: **Parameter** `aFactorSrc` :    a blend factor for source :material-location-enter: **Parameter** `aFactorDst` :    a blend factor for destination  |

## Variable Details

### equation<a name="equation"></a>

!!! variable "BlendEquationType equation"

    blend equation

### factorDst<a name="factorDst"></a>

!!! variable "BlendType factorDst"

    blend factor for destination

### factorSrc<a name="factorSrc"></a>

!!! variable "BlendType factorSrc"

    blend factor for source

## Function Details

### BlendSettings<a name="BlendSettings"></a>

!!! function "BlendSettings()"

    default constructor

!!! function "BlendSettings(BlendEquationType aEquation, BlendType aFactorSrc, BlendType aFactorDst)"

    constructor
    :material-location-enter: **Parameter** `aEquation`
    :    a blend equation
    :material-location-enter: **Parameter** `aFactorSrc`
    :    a blend factor for source
    :material-location-enter: **Parameter** `aFactorDst`
    :    a blend factor for destination
