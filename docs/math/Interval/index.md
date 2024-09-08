---
title: Interval
description: a interval 
generator: doxide
---


# Interval

**struct Interval**

a interval

## Variables

| Name | Description |
| ---- | ----------- |
| [isLeftClosed](#isLeftClosed) | whether the left endpoint is included  |
| [isRightClosed](#isRightClosed) | whether the right endpoint is included  |
| [left](#left) | a left value  |
| [right](#right) | a right value  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | copy assignment  |
| [operator=](#operator_u003d) | move assignment  |
| [operator==](#operator_u003d_u003d) | equality operator  |
| [operator!=](#operator_u0021_u003d) | inequality operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Interval](#Interval) | default constructor  |
| [Interval](#Interval) | constructor from endpoints  |
| [Interval](#Interval) | copy constructor  |
| [Interval](#Interval) | move constructor  |
| [~Interval](#_u007eInterval) | destructor  |
| [set](#set) | set interval :material-location-enter: **Parameter** `leftVal` :    a left endpoint :material-location-enter: **Parameter** `rightVal` :    a right endpoint :material-location-enter: **Parameter** `leftClosed` :    whether the left endpoint is included :material-location-enter: **Parameter** `rightClosed` :    whether the right endpoint is included  |
| [getSupremum](#getSupremum) | get supremum  |
| [getMaximum](#getMaximum) | get maximum  |
| [getInfimum](#getInfimum) | get infimum  |
| [getMinimum](#getMinimum) | get minimum  |
| [getIsLeftClosed](#getIsLeftClosed) | get whether the left endpoint is included  |
| [getIsRightClosed](#getIsRightClosed) | get whether the right endpoint is included  |
| [contains](#contains) | whether the interval contains the value :material-location-enter: **Parameter** `value` :    a value to be checked  |

## Variable Details

### isLeftClosed<a name="isLeftClosed"></a>

!!! variable "bool isLeftClosed"

    whether the left endpoint is included

### isRightClosed<a name="isRightClosed"></a>

!!! variable "bool isRightClosed"

    whether the right endpoint is included

### left<a name="left"></a>

!!! variable "float left"

    a left value

### right<a name="right"></a>

!!! variable "float right"

    a right value

## Operator Details

### operator!=<a name="operator_u0021_u003d"></a>

!!! function "bool operator!=(const Interval&amp; other) const"

    inequality operator

### operator=<a name="operator_u003d"></a>

!!! function "Interval&amp; operator=(const Interval&amp; other)"

    copy assignment

!!! function "Interval&amp; operator=(Interval&amp;&amp; other)"

    move assignment

### operator==<a name="operator_u003d_u003d"></a>

!!! function "bool operator==(const Interval&amp; other) const"

    equality operator

## Function Details

### Interval<a name="Interval"></a>

!!! function "Interval()"

    default constructor

!!! function "Interval(float leftVal, float rightVal, bool leftClosed = true, bool rightClosed = true)"

    constructor from endpoints

!!! function "Interval(const Interval&amp; other)"

    copy constructor

!!! function "Interval(Interval&amp;&amp; other)"

    move constructor

### contains<a name="contains"></a>

!!! function "bool contains(float value) const"

    whether the interval contains the value
    :material-location-enter: **Parameter** `value`
    :    a value to be checked

### getInfimum<a name="getInfimum"></a>

!!! function "float getInfimum() const"

    get infimum

### getIsLeftClosed<a name="getIsLeftClosed"></a>

!!! function "bool getIsLeftClosed() const"

    get whether the left endpoint is included

### getIsRightClosed<a name="getIsRightClosed"></a>

!!! function "bool getIsRightClosed() const"

    get whether the right endpoint is included

### getMaximum<a name="getMaximum"></a>

!!! function "optional&lt;float&gt; getMaximum() const"

    get maximum

### getMinimum<a name="getMinimum"></a>

!!! function "optional&lt;float&gt; getMinimum() const"

    get minimum

### getSupremum<a name="getSupremum"></a>

!!! function "float getSupremum() const"

    get supremum

### set<a name="set"></a>

!!! function "void set(float leftVal, float rightVal, bool leftClosed = true, bool rightClosed = true)"

    set interval
    :material-location-enter: **Parameter** `leftVal`
    :    a left endpoint
    :material-location-enter: **Parameter** `rightVal`
    :    a right endpoint
    :material-location-enter: **Parameter** `leftClosed`
    :    whether the left endpoint is included
    :material-location-enter: **Parameter** `rightClosed`
    :    whether the right endpoint is included

### ~Interval<a name="_u007eInterval"></a>

!!! function "virtual ~Interval()"

    destructor
