---
title: TearsEngine
description: an engine of tears app 
generator: doxide
---


# TearsEngine

**class TearsEngine**

an engine of tears app

## Variables

| Name | Description |
| ---- | ----------- |
| [glController](#glController) | GL state manager and drawer  |
| [currentScene](#currentScene) | current scene  |
| [nextScene](#nextScene) | next scene  |
| [isDirty](#isDirty) | dirty flag  |
| [callback](#callback) | callback function  |
| [size](#size) | screen size  |

## Functions

| Name | Description |
| ---- | ----------- |
| [initialize](#initialize) | initializer  |
| [TearsEngine](#TearsEngine) | constructor  |
| [TearsEngine](#TearsEngine) | copy constructor  |
| [~TearsEngine](#_u007eTearsEngine) | destructor  |
| [runOneLoop](#runOneLoop) | run one event loop  |
| [setNextLoopCallback](#setNextLoopCallback) | register callback function to run on the beginning of the next event loop  |
| [setCurrentScene](#setCurrentScene) | set current scene :material-location-enter: **Parameter** `scene` :    a scene to be set as current scene :material-location-enter: **Parameter** `lazy` :    if true, set scene on the next event loop, otherwise set intermediately (default: true)  |
| [setViewSize](#setViewSize) | set a size of the view  |
| [setScreenScale](#setScreenScale) | set screen scale  |
| [getIsDirty](#getIsDirty) | get dirty flag  |
| [setIsDirty](#setIsDirty) | set dirty flag  |

## Variable Details

### callback<a name="callback"></a>

!!! variable "function&lt;void()&gt; callback"

    callback function

### currentScene<a name="currentScene"></a>

!!! variable "shared_ptr&lt;Scene&gt; currentScene"

    current scene

### glController<a name="glController"></a>

!!! variable "GLController&#42; glController"

    GL state manager and drawer

### isDirty<a name="isDirty"></a>

!!! variable "bool isDirty"

    dirty flag

### nextScene<a name="nextScene"></a>

!!! variable "unique_ptr&lt;Scene&gt; nextScene"

    next scene

### size<a name="size"></a>

!!! variable "Size size"

    screen size

## Function Details

### TearsEngine<a name="TearsEngine"></a>

!!! function "TearsEngine(int screenWidth, int screenHeight)"

    constructor

!!! function "TearsEngine(const TearsEngine&amp; engine)"

    copy constructor

### getIsDirty<a name="getIsDirty"></a>

!!! function "bool getIsDirty() const"

    get dirty flag

### initialize<a name="initialize"></a>

!!! function "void initialize(Size screenSize)"

    initializer

### runOneLoop<a name="runOneLoop"></a>

!!! function "void runOneLoop()"

    run one event loop

### setCurrentScene<a name="setCurrentScene"></a>

!!! function "void setCurrentScene(unique_ptr&lt;Scene&gt; scene, bool lazy = true)"

    set current scene
    :material-location-enter: **Parameter** `scene`
    :    a scene to be set as current scene
    :material-location-enter: **Parameter** `lazy`
    :    if true, set scene on the next event loop, otherwise set intermediately
        (default: true)

### setIsDirty<a name="setIsDirty"></a>

!!! function "void setIsDirty(bool b)"

    set dirty flag

### setNextLoopCallback<a name="setNextLoopCallback"></a>

!!! function "void setNextLoopCallback(function&lt;void()&gt; aCallback)"

    register callback function to run on the beginning of the next event loop

### setScreenScale<a name="setScreenScale"></a>

!!! function "void setScreenScale(float scale) const"

    set screen scale

### setViewSize<a name="setViewSize"></a>

!!! function "void setViewSize(int width, int height)"

    set a size of the view

### ~TearsEngine<a name="_u007eTearsEngine"></a>

!!! function "virtual ~TearsEngine()"

    destructor
