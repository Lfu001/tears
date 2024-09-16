---
title: View
description: represents part of the user interface and provide modifier to configure views 
generator: doxide
---


# View

**class View: public Modifier, public ViewFlag**

represents part of the user interface and provide modifier to configure views

## Variables

| Name | Description |
| ---- | ----------- |
| [nextViewId](#nextViewId) | assignable view ID  |
| [id](#id) | view ID  |
| [parent](#parent) | parent view  |
| [position](#position) | view position  |
| [size](#size) | view size  |
| [children](#children) | children views  |
| [layoutDirection](#layoutDirection) | layout direction (default: vertical)  |

## Functions

| Name | Description |
| ---- | ----------- |
| [assignViewId](#assignViewId) | assign view ID  |
| [computeChildPosition](#computeChildPosition) | compute and set a position of child views  |
| [computeChildSize](#computeChildSize) | compute and set a size of child views  |
| [computeChildSizeIfSpecified](#computeChildSizeIfSpecified) | compute and set a size of child views if specified :material-location-exit: **Parameter** `outWidthFlags` :    an output flags for each child that represents whether width is already computed :material-location-exit: **Parameter** `outHeightFlags` :    an output flags for each child that represents whether height is already computed :material-location-exit: **Parameter** `outLayoutSpace` :    an output size represents available layout space remained  |
| [computeProposingSize](#computeProposingSize) | compute size to be proposed to child views :material-location-enter: **Parameter** `layoutSpace` :    a space that can be used to layout children :material-location-enter: **Parameter** `widthCount` :    the number of children which width is not computed yet :material-location-enter: **Parameter** `heightCount` :    the number of children which height is not computed yet  |
| [computeWidth](#computeWidth) | respond the width computed from width range and the proposed width by parent :material-location-enter: **Parameter** `proposedWidth` :    a width proposed by parent :material-keyboard-return: **Return** :    a proposed width clamped between minimum width and maximum width  |
| [computeHeight](#computeHeight) | respond the height computed from height range and the proposed height by parent :material-location-enter: **Parameter** `proposedHeight` :    a height proposed by parent :material-keyboard-return: **Return** :    a proposed height clamped between minimum height and maximum height  |
| [setPosition](#setPosition) | set view position  |
| [setX](#setX) | set view position x  |
| [setY](#setY) | set view position y  |
| [setSizeInternal](#setSizeInternal) | set view size  |
| [setWidthInternal](#setWidthInternal) | set view width  |
| [setHeightInternal](#setHeightInternal) | set view height  |
| [layout](#layout) | layout the view  |
| [draw](#draw) | calculate layout if needed, and draw this view and the children  |
| [addChild](#addChild) | add child view  |
| [setParent](#setParent) | set parent view  |
| [drawMain](#drawMain) | main drawing process ! |
| [getVertices](#getVertices) | get the vertices of the view  |
| [getTexCoord](#getTexCoord) | get the texture coordinates of the view in the screen texture  |
| [viewWillLayout](#viewWillLayout) | A handler called before this view is layed out. |
| [viewDidLayout](#viewDidLayout) | A handler called after this view is layed out. |
| [View](#View) | default constructor  |
| [View](#View) | constructor (with child views) by default, children will be ordered vertically :material-location-enter: **Parameter** `aChildren` :    child views where child is subclass of `View`  |
| [~View](#_u007eView) | destructor  |
| [getViewId](#getViewId) | get view id  |
| [getPosition](#getPosition) | get view postion  |
| [getX](#getX) | get view position x  |
| [getY](#getY) | get view position y  |
| [getSize](#getSize) | get view size  |
| [getWidth](#getWidth) | get view width  |
| [getHeight](#getHeight) | get view height  |
| [getInnerWidth](#getInnerWidth) | get inner width  |
| [getInnerHeight](#getInnerHeight) | get inner height  |
| [getLayoutDirection](#getLayoutDirection) | get layout direction  |

## Variable Details

### children<a name="children"></a>

!!! variable "vector&lt;unique_ptr&lt;View&gt;&gt; children"

    children views
    

### id<a name="id"></a>

!!! variable "int64_t id"

    view ID
    

### layoutDirection<a name="layoutDirection"></a>

!!! variable "LayoutDirectionType layoutDirection"

    layout direction (default: vertical)
    

### nextViewId<a name="nextViewId"></a>

!!! variable "static int64_t nextViewId"

    assignable view ID
    

### parent<a name="parent"></a>

!!! variable "View&#42; parent"

    parent view
    

### position<a name="position"></a>

!!! variable "Point position"

    view position
    

### size<a name="size"></a>

!!! variable "Size size"

    view size
    

## Function Details

### View<a name="View"></a>

!!! function "View()"

    default constructor
    

!!! function "template&lt;class... Views&gt; View(Views&amp;&amp;... aChildren)"

    constructor (with child views)
    by default, children will be ordered vertically
    :material-location-enter: **Parameter** `aChildren`
    :    child views where child is subclass of `View`
    

### addChild<a name="addChild"></a>

!!! function "template&lt;typename T&gt; void addChild(T&amp;&amp; child)"

    add child view
    

### assignViewId<a name="assignViewId"></a>

!!! function "void assignViewId()"

    assign view ID
    

### computeChildPosition<a name="computeChildPosition"></a>

!!! function "void computeChildPosition()"

    compute and set a position of child views
    

### computeChildSize<a name="computeChildSize"></a>

!!! function "void computeChildSize()"

    compute and set a size of child views
    

### computeChildSizeIfSpecified<a name="computeChildSizeIfSpecified"></a>

!!! function "void computeChildSizeIfSpecified( vector&lt;bool&gt;&amp; outWidthFlags, vector&lt;bool&gt;&amp; outHeightFlags, Size&amp; outLayoutSpace)"

    compute and set a size of child views if specified
    :material-location-exit: **Parameter** `outWidthFlags`
    :    an output flags for each child that represents whether width is
        already computed
    :material-location-exit: **Parameter** `outHeightFlags`
    :    an output flags for each child that represents whether height is
        already computed
    :material-location-exit: **Parameter** `outLayoutSpace`
    :    an output size represents available layout space remained
    

### computeHeight<a name="computeHeight"></a>

!!! function "float computeHeight(float proposedHeight)"

    respond the height computed from height range and the proposed height by parent
    :material-location-enter: **Parameter** `proposedHeight`
    :    a height proposed by parent
    :material-keyboard-return: **Return**
    :    a proposed height clamped between minimum height and maximum height
    

### computeProposingSize<a name="computeProposingSize"></a>

!!! function "Size computeProposingSize(const Size&amp; layoutSpace, int widthCount, int heightCount) const"

    compute size to be proposed to child views
    :material-location-enter: **Parameter** `layoutSpace`
    :    a space that can be used to layout children
    :material-location-enter: **Parameter** `widthCount`
    :    the number of children which width is not computed yet
    :material-location-enter: **Parameter** `heightCount`
    :    the number of children which height is not computed yet
    

### computeWidth<a name="computeWidth"></a>

!!! function "float computeWidth(float proposedWidth)"

    respond the width computed from width range and the proposed width by parent
    :material-location-enter: **Parameter** `proposedWidth`
    :    a width proposed by parent
    :material-keyboard-return: **Return**
    :    a proposed width clamped between minimum width and maximum width
    

### draw<a name="draw"></a>

!!! function "void draw()"

    calculate layout if needed, and draw this view and the children
    

### drawMain<a name="drawMain"></a>

!!! function "virtual void drawMain()"

    main drawing process
    !!! info
    call GLController::drawArrays() from this method.
    

### getHeight<a name="getHeight"></a>

!!! function "float getHeight() const"

    get view height
    

### getInnerHeight<a name="getInnerHeight"></a>

!!! function "float getInnerHeight()"

    get inner height
    

### getInnerWidth<a name="getInnerWidth"></a>

!!! function "float getInnerWidth()"

    get inner width
    

### getLayoutDirection<a name="getLayoutDirection"></a>

!!! function "LayoutDirectionType getLayoutDirection() const"

    get layout direction
    

### getPosition<a name="getPosition"></a>

!!! function "Point getPosition() const"

    get view postion
    

### getSize<a name="getSize"></a>

!!! function "Size getSize() const"

    get view size
    

### getTexCoord<a name="getTexCoord"></a>

!!! function "vector&lt;Point&gt; getTexCoord() const"

    get the texture coordinates of the view in the screen texture
    

### getVertices<a name="getVertices"></a>

!!! function "vector&lt;Point&gt; getVertices() const"

    get the vertices of the view
    

### getViewId<a name="getViewId"></a>

!!! function "int64_t getViewId() const"

    get view id
    

### getWidth<a name="getWidth"></a>

!!! function "float getWidth() const"

    get view width
    

### getX<a name="getX"></a>

!!! function "float getX() const"

    get view position x
    

### getY<a name="getY"></a>

!!! function "float getY() const"

    get view position y
    

### layout<a name="layout"></a>

!!! function "virtual void layout()"

    layout the view
    

### setHeightInternal<a name="setHeightInternal"></a>

!!! function "void setHeightInternal(float aHeight)"

    set view height
    

### setParent<a name="setParent"></a>

!!! function "void setParent(View&#42; aParent)"

    set parent view
    

### setPosition<a name="setPosition"></a>

!!! function "void setPosition(float aX, float aY)"

    set view position
    

### setSizeInternal<a name="setSizeInternal"></a>

!!! function "void setSizeInternal(float aWidth, float aHeight)"

    set view size
    

### setWidthInternal<a name="setWidthInternal"></a>

!!! function "void setWidthInternal(float aWidth)"

    set view width
    

### setX<a name="setX"></a>

!!! function "void setX(float aX)"

    set view position x
    

### setY<a name="setY"></a>

!!! function "void setY(float aY)"

    set view position y
    

### viewDidLayout<a name="viewDidLayout"></a>

!!! function "virtual void viewDidLayout()"

    A handler called after this view is layed out.
    

### viewWillLayout<a name="viewWillLayout"></a>

!!! function "virtual void viewWillLayout()"

    A handler called before this view is layed out.
    

### ~View<a name="_u007eView"></a>

!!! function "virtual ~View()"

    destructor
    
