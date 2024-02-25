---
title: tears
description: 
generator: doxide
---


# tears



## Macros

| Name | Description |
| ---- | ----------- |
| [__TEARS_FUNCTION__](#__TEARS_FUNCTION__) |  a name of the function  |
| [tears_assert](#tears_assert) |  validates the condition in debug builds and breaks if the condition is false (and then you can continue executing the program). |
| [tears_printf](#tears_printf) |  print to console on debug build, otherwise do nothing  |

## Macro Details

### __TEARS_FUNCTION__<a name="__TEARS_FUNCTION__"></a>

!!! macro "#    define __TEARS_FUNCTION__"

     a name of the function
    

### tears_assert<a name="tears_assert"></a>

!!! macro "#    define tears_assert(condition) \"

     validates the condition in debug builds and breaks if the condition is false (and then you can
     continue executing the program). In a release build, it does nothing.
    

### tears_printf<a name="tears_printf"></a>

!!! macro "#    define tears_printf(...)"

     print to console on debug build, otherwise do nothing
    

