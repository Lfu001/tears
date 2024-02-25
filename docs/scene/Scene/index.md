---
title: Scene
description:  a root class of the View tree 
generator: doxide
---


# Scene

**class Scene: public View**

 a root class of the View tree
 


## Variables

| Name | Description |
| ---- | ----------- |
| [engine](#engine) |  app engine (no ownership) ! |

## Functions

| Name | Description |
| ---- | ----------- |
| [Scene](#Scene) |  default constructor  |
| [Scene](#Scene) |  constructor  |
| [Scene](#Scene) |  constructor (with child views) :material-location-enter: **Parameter** `aChildren` :    child views where child is subclass of `View`  |
| [~Scene](#_u007eScene) |  destructor  |
| [render](#render) |  render the scene  |
| [getSize](#getSize) |  get scene size  |
| [setSize](#setSize) |  set scene size  |
| [setSize](#setSize) |  set scene size by Vector2D  |

## Variable Details

### engine<a name="engine"></a>

!!! variable "TearsEngine&#42; engine"

     app engine (no ownership)
    !!! warning
        do not delete this pointer variable since `Scene` class does not have the ownership
    

## Function Details

### Scene<a name="Scene"></a>
!!! function "Scene() = delete"

     default constructor
    

!!! function "Scene(TearsEngine&#42; aEngine, Size screenSize)"

     constructor
    

!!! function "template&lt;class... Views&gt; Scene(Views&amp;&amp;... aChildren)"

     constructor (with child views)
     :material-location-enter: **Parameter** `aChildren`
    :    child views where child is subclass of `View`
    

### getSize<a name="getSize"></a>
!!! function "Size getSize() const"

     get scene size
    

### render<a name="render"></a>
!!! function "virtual void render()"

     render the scene
    

### setSize<a name="setSize"></a>
!!! function "void setSize(float x, float y)"

     set scene size
    

!!! function "void setSize(Size aSize)"

     set scene size by Vector2D
    

### ~Scene<a name="_u007eScene"></a>
!!! function "virtual ~Scene()"

     destructor
    

