---
title: Framebuffer
description: a wrapper class of a GL frame buffer.
generator: doxide
---


# Framebuffer

**class Framebuffer**

a wrapper class of a GL frame buffer. consider using it via `FramebufferScope` class.

## Variables

| Name | Description |
| ---- | ----------- |
| [name](#name) | framebuffer name  |

## Functions

| Name | Description |
| ---- | ----------- |
| [initialize](#initialize) | initializer  |
| [Framebuffer](#Framebuffer) | default constructor  |
| [Framebuffer](#Framebuffer) | constructor (from texture) :material-location-enter: **Parameter** `aTexture` :    a texture to be attached to the frame buffer  |
| [~Framebuffer](#_u007eFramebuffer) | destructor  |
| [attachTexture](#attachTexture) | attach texture  |
| [bind](#bind) | bind framebuffer  |
| [unbind](#unbind) | unbind framebuffer. |
| [getName](#getName) | get framebuffer name  |

## Variable Details

### name<a name="name"></a>

!!! variable "unsigned int name"

    framebuffer name

## Function Details

### Framebuffer<a name="Framebuffer"></a>

!!! function "Framebuffer()"

    default constructor

!!! function "Framebuffer(const Texture&#42; aTexture)"

    constructor (from texture)
    :material-location-enter: **Parameter** `aTexture`
    :    a texture to be attached to the frame buffer

### attachTexture<a name="attachTexture"></a>

!!! function "void attachTexture(const Texture&#42; texture) const"

    attach texture

### bind<a name="bind"></a>

!!! function "void bind() const"

    bind framebuffer

### getName<a name="getName"></a>

!!! function "unsigned int getName() const"

    get framebuffer name

### initialize<a name="initialize"></a>

!!! function "void initialize()"

    initializer

### unbind<a name="unbind"></a>

!!! function "void unbind() const"

    unbind framebuffer. equivalent to binding default framebuffer.

### ~Framebuffer<a name="_u007eFramebuffer"></a>

!!! function "virtual ~Framebuffer()"

    destructor
