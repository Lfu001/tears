---
title: Divider
description: A visual element that can be used to separate other content.
generator: doxide
---


# Divider

**class Divider: public View**

A visual element that can be used to separate other content.

## Functions

| Name | Description |
| ---- | ----------- |
| [setOffset](#setOffset) | set offset x and y  |
| [setOffsetX](#setOffsetX) | set offset x  |
| [setOffsetY](#setOffsetY) | set offset y  |
| [setSize](#setSize) | set size  |
| [setWidth](#setWidth) | set width  |
| [setHeight](#setHeight) | set height  |
| [setWidthRange](#setWidthRange) | set width range (ignored if width is specified)  |
| [setHeightRange](#setHeightRange) | set height range (ignored if height is specified)  |
| [setMinWidth](#setMinWidth) | set minimum width (ignored if width is specified)  |
| [setMinHeight](#setMinHeight) | set minimum height (ignored if height is specified)  |
| [setMaxWidth](#setMaxWidth) | set maximum width (ignored if width is specified)  |
| [setMaxHeight](#setMaxHeight) | set maximum height (ignored if height is specified)  |
| [setWidthRatio](#setWidthRatio) | set width ratio (ignored if width is specified)  |
| [setHeightRatio](#setHeightRatio) | set height ratio (ignored if height is specified)  |
| [setLayoutPriority](#setLayoutPriority) | set layout priority (the higher the value, the higher the priority)  |
| [setAlignment](#setAlignment) | set alignment  |
| [setPadding](#setPadding) | set padding  |
| [setBorder](#setBorder) | set border  |
| [viewWillLayout](#viewWillLayout) | A color of the divider. |
| [drawMain](#drawMain) | main drawing process  |
| [Divider](#Divider) | constructor  |
| [~Divider](#_u007eDivider) | destructor  |
| [setColor](#setColor) | Set the color of the divider. |

## Function Details

### Divider<a name="Divider"></a>

!!! function "Divider()"

    constructor
    

### drawMain<a name="drawMain"></a>

!!! function "virtual void drawMain() override"

    main drawing process
    

### setAlignment<a name="setAlignment"></a>

!!! function "virtual Modifier&amp; setAlignment(AlignmentType alignment) override"

    set alignment
    

### setBorder<a name="setBorder"></a>

!!! function "virtual Modifier&amp; setBorder(EdgeType edge, float val) override"

    set border
    

### setColor<a name="setColor"></a>

!!! function "Divider&amp; setColor(Color aColor)"

    Set the color of the divider.
    

### setHeight<a name="setHeight"></a>

!!! function "virtual Modifier&amp; setHeight(float height) override"

    set height
    

### setHeightRange<a name="setHeightRange"></a>

!!! function "virtual Modifier&amp; setHeightRange(float min, float max) override"

    set height range (ignored if height is specified)
    

### setHeightRatio<a name="setHeightRatio"></a>

!!! function "virtual Modifier&amp; setHeightRatio(float ratio) override"

    set height ratio (ignored if height is specified)
    

### setLayoutPriority<a name="setLayoutPriority"></a>

!!! function "virtual Modifier&amp; setLayoutPriority(float priority) override"

    set layout priority (the higher the value, the higher the priority)
    

### setMaxHeight<a name="setMaxHeight"></a>

!!! function "virtual Modifier&amp; setMaxHeight(float max) override"

    set maximum height (ignored if height is specified)
    

### setMaxWidth<a name="setMaxWidth"></a>

!!! function "virtual Modifier&amp; setMaxWidth(float max) override"

    set maximum width (ignored if width is specified)
    

### setMinHeight<a name="setMinHeight"></a>

!!! function "virtual Modifier&amp; setMinHeight(float min) override"

    set minimum height (ignored if height is specified)
    

### setMinWidth<a name="setMinWidth"></a>

!!! function "virtual Modifier&amp; setMinWidth(float min) override"

    set minimum width (ignored if width is specified)
    

### setOffset<a name="setOffset"></a>

!!! function "virtual Modifier&amp; setOffset(float x, float y) override"

    set offset x and y
    

### setOffsetX<a name="setOffsetX"></a>

!!! function "virtual Modifier&amp; setOffsetX(float x) override"

    set offset x
    

### setOffsetY<a name="setOffsetY"></a>

!!! function "virtual Modifier&amp; setOffsetY(float y) override"

    set offset y
    

### setPadding<a name="setPadding"></a>

!!! function "virtual Modifier&amp; setPadding(EdgeType edge, float val) override"

    set padding
    

### setSize<a name="setSize"></a>

!!! function "virtual Modifier&amp; setSize(float width, float height) override"

    set size
    

### setWidth<a name="setWidth"></a>

!!! function "virtual Modifier&amp; setWidth(float width) override"

    set width
    

### setWidthRange<a name="setWidthRange"></a>

!!! function "virtual Modifier&amp; setWidthRange(float min, float max) override"

    set width range (ignored if width is specified)
    

### setWidthRatio<a name="setWidthRatio"></a>

!!! function "virtual Modifier&amp; setWidthRatio(float ratio) override"

    set width ratio (ignored if width is specified)
    

### viewWillLayout<a name="viewWillLayout"></a>

!!! function "virtual void viewWillLayout() override"

    A color of the divider. The default value is `Color::GRAY`.
    A handler called before this view is layed out.
    

### ~Divider<a name="_u007eDivider"></a>

!!! function "~Divider()"

    destructor
    
