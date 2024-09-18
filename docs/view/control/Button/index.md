---
title: Button
description: A control that initiates an action.
generator: doxide
---


# Button

**class Button: public View**

A control that initiates an action.

## Variables

| Name | Description |
| ---- | ----------- |
| [action](#action) | An action which is triggered when the button is pressed. |
| [background](#background) | A background. |

## Functions

| Name | Description |
| ---- | ----------- |
| [Button](#Button) | constructor  |
| [~Button](#_u007eButton) | destructor  |
| [setBackground](#setBackground) | Set backgroud. |
| [onTap](#onTap) | Handle a touch event. |

## Variable Details

### action<a name="action"></a>

!!! variable "function&lt;void()&gt; action"

    An action which is triggered when the button is pressed.
    

### background<a name="background"></a>

!!! variable "Shape&#42; background"

    A background.
    

## Function Details

### Button<a name="Button"></a>

!!! function "Button(function&lt;void()&gt; aAction = nullptr)"

    constructor
    

### onTap<a name="onTap"></a>

!!! function "void onTap()"

    Handle a touch event. Call this method from the OS API.
    

### setBackground<a name="setBackground"></a>

!!! function "void setBackground(unique_ptr&lt;Shape&gt; background)"

    Set backgroud.
    

### ~Button<a name="_u007eButton"></a>

!!! function "virtual ~Button()"

    destructor
    
