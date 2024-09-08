---
title: FramebufferScope
description: a scope class that create, bind, delete framebuffer 
generator: doxide
---


# FramebufferScope

**class FramebufferScope**

a scope class that create, bind, delete framebuffer

## Variables

| Name | Description |
| ---- | ----------- |
| [framebuffer](#framebuffer) | current framebuffer  |
| [viewportScope](#viewportScope) | a scope to set viewport  |

## Functions

| Name | Description |
| ---- | ----------- |
| [FramebufferScope](#FramebufferScope) | constructor (from texture) :material-location-enter: **Parameter** `texture` :    a texture to be attached to the framebuffer  |
| [~FramebufferScope](#_u007eFramebufferScope) | destructor  |

## Variable Details

### framebuffer<a name="framebuffer"></a>

!!! variable "unique_ptr&lt;Framebuffer&gt; framebuffer"

    current framebuffer

### viewportScope<a name="viewportScope"></a>

!!! variable "ViewportScope viewportScope"

    a scope to set viewport

## Function Details

### FramebufferScope<a name="FramebufferScope"></a>

!!! function "FramebufferScope(const Texture&#42; texture)"

    constructor (from texture)
    :material-location-enter: **Parameter** `texture`
    :    a texture to be attached to the framebuffer

### ~FramebufferScope<a name="_u007eFramebufferScope"></a>

!!! function "virtual ~FramebufferScope()"

    destructor
