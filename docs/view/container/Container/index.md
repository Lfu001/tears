---
title: Container
description: A view interface that arranges its subviews in a line 
generator: doxide
---


# Container

**class Container: public View**

A view interface that arranges its subviews in a line

## Functions

| Name | Description |
| ---- | ----------- |
| [Container](#Container) | default container  |
| [Container](#Container) | constructor (with child views) :material-location-enter: **Parameter** `aChildren` :    child views where child is subclass of `View`  |
| [~Container](#_u007eContainer) | destructor  |

## Function Details

### Container<a name="Container"></a>

!!! function "Container() = delete"

    default container

!!! function "template&lt;class... Views&gt; Container(Views&amp;&amp;... aChildren)"

    constructor (with child views)
    :material-location-enter: **Parameter** `aChildren`
    :    child views where child is subclass of `View`

### ~Container<a name="_u007eContainer"></a>

!!! function "virtual ~Container()"

    destructor
