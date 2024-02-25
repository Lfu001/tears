---
title: DebugUtil
description:  a utility available only on debug build 
generator: doxide
---


# DebugUtil

**class DebugUtil**

 a utility available only on debug build
 


## Variables

| Name | Description |
| ---- | ----------- |
| [noBreakMode](#noBreakMode) |  flag for disable execution pause on `tears_assert()` failed  |

## Functions

| Name | Description |
| ---- | ----------- |
| [pauseExecution](#pauseExecution) |  pause execution and prints failed check, file name, line and function  |

## Variable Details

### noBreakMode<a name="noBreakMode"></a>

!!! variable "inline static bool noBreakMode"

     flag for disable execution pause on `tears_assert()` failed
    

## Function Details

### pauseExecution<a name="pauseExecution"></a>
!!! function "static void pauseExecution( const char&#42; condition, const char&#42; fileName, int line, const char&#42; functionName)"

     pause execution and prints failed check, file name, line and function
    

