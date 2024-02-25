---
title: CallbackScope
description:  a class that execute a callback function upon scope exit 
generator: doxide
---


# CallbackScope

**class CallbackScope**

 a class that execute a callback function upon scope exit
  


## Variables

| Name | Description |
| ---- | ----------- |
| [callback](#callback) |  a callback function to execute when scope exit  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) |  copy assignment operator  |
| [operator=](#operator_u003d) |  move assignment operator  |
| [operator new](#operatornew) |  new operator  |
| [operator new[]](#operatornew_u005b_u005d) |  new[] operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [CallbackScope](#CallbackScope) |  default constructor  |
| [CallbackScope](#CallbackScope) |  copy constructor  |
| [CallbackScope](#CallbackScope) |  move constructor  |
| [CallbackScope](#CallbackScope) |  constructor  |
| [~CallbackScope](#_u007eCallbackScope) |  destructor  |

## Variable Details

### callback<a name="callback"></a>

!!! variable "function&lt;void()&gt; callback"

     a callback function to execute when scope exit
    

## Operator Details

### operator new<a name="operatornew"></a>

!!! function "void&#42; operator new(std::size_t) = delete"

     new operator
    

### operator new[]<a name="operatornew_u005b_u005d"></a>

!!! function "void&#42; operator new[](std::size_t) = delete"

     new[] operator
    

### operator=<a name="operator_u003d"></a>

!!! function "CallbackScope&amp; operator=(const CallbackScope&amp;) = delete"

     copy assignment operator
    

!!! function "CallbackScope&amp; operator=(CallbackScope&amp;&amp;) = delete"

     move assignment operator
    

## Function Details

### CallbackScope<a name="CallbackScope"></a>
!!! function "CallbackScope() = delete"

     default constructor
    

!!! function "CallbackScope(const CallbackScope&amp;) = delete"

     copy constructor
    

!!! function "CallbackScope(CallbackScope&amp;&amp;) = delete"

     move constructor
    

!!! function "CallbackScope(function&lt;void()&gt; aCallback)"

     constructor
    

### ~CallbackScope<a name="_u007eCallbackScope"></a>
!!! function "~CallbackScope() noexcept"

     destructor
    

