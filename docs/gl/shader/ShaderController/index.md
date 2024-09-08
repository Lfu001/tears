---
title: ShaderController
description: a singleton class that manages shaders 
generator: doxide
---


# ShaderController

**class ShaderController**

a singleton class that manages shaders

## Variables

| Name | Description |
| ---- | ----------- |
| [controller](#controller) | singleton instance  |
| [shaderMap](#shaderMap) | a created shaders  |
| [shaderStack](#shaderStack) | shader stack  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | copy assignment operator  |
| [operator=](#operator_u003d) | move assignment operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [ShaderController](#ShaderController) | default constructor  |
| [~ShaderController](#_u007eShaderController) | destructor  |
| [ShaderController](#ShaderController) | copy constructor  |
| [ShaderController](#ShaderController) | move constructor  |
| [getCurrentShader](#getCurrentShader) | get current shader  |
| [pushShader](#pushShader) | push shader to stack  |
| [popShader](#popShader) | pop shader from stack  |
| [useShader](#useShader) | use shader  |
| [getInstance](#getInstance) | get singleton instance  |
| [createShader](#createShader) | create shader  |

## Variable Details

### controller<a name="controller"></a>

!!! variable "static unique_ptr&lt;ShaderController&gt; controller"

    singleton instance

### shaderMap<a name="shaderMap"></a>

!!! variable "unordered_map&lt;ShaderObjectType, unique_ptr&lt;Shader&gt;&gt; shaderMap"

    a created shaders

### shaderStack<a name="shaderStack"></a>

!!! variable "vector&lt;const Shader&#42;&gt; shaderStack"

    shader stack

## Operator Details

### operator=<a name="operator_u003d"></a>

!!! function "ShaderController&amp; operator=(const ShaderController&amp;) = delete"

    copy assignment operator

!!! function "ShaderController&amp; operator=(ShaderController&amp;&amp;) = delete"

    move assignment operator

## Function Details

### ShaderController<a name="ShaderController"></a>

!!! function "ShaderController()"

    default constructor

!!! function "ShaderController(const ShaderController&amp;) = delete"

    copy constructor

!!! function "ShaderController(ShaderController&amp;&amp;) = delete"

    move constructor

### createShader<a name="createShader"></a>

!!! function "Shader&#42; createShader(ShaderObjectType shaderObjectType)"

    create shader

### getCurrentShader<a name="getCurrentShader"></a>

!!! function "const Shader&#42; getCurrentShader() const"

    get current shader

### getInstance<a name="getInstance"></a>

!!! function "static ShaderController&#42; getInstance()"

    get singleton instance

### popShader<a name="popShader"></a>

!!! function "void popShader()"

    pop shader from stack

### pushShader<a name="pushShader"></a>

!!! function "void pushShader(const Shader&#42; shader)"

    push shader to stack

### useShader<a name="useShader"></a>

!!! function "void useShader(const Shader&#42; shader) const"

    use shader

### ~ShaderController<a name="_u007eShaderController"></a>

!!! function "virtual ~ShaderController()"

    destructor
