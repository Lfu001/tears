---
title: Shader
description: a base class that wraps OpenGL shaders 
generator: doxide
---


# Shader

**class Shader**

a base class that wraps OpenGL shaders

## Variables

| Name | Description |
| ---- | ----------- |
| [programObject](#programObject) | OpenGL program object  |
| [hasher](#hasher) | string hasher  |
| [vertexHash](#vertexHash) | vertex shader source hash  |
| [fragmentHash](#fragmentHash) | fragment shader source hash  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Shader](#Shader) | default constructor  |
| [~Shader](#_u007eShader) | destructor  |
| [loadShader](#loadShader) | load shader  |
| [buildProgram](#buildProgram) | build program object :material-location-enter: **Parameter** `vertexShaderSource` :    a source code of vertex shader :material-location-enter: **Parameter** `fragmentShaderSource` :    a source code of fragment shader  |
| [deleteProgram](#deleteProgram) | delete program  |
| [getUniformLocation](#getUniformLocation) | get uniform variable location  |
| [getAttributeLocation](#getAttributeLocation) | get attribute variable location  |
| [getProgramObject](#getProgramObject) | get program object  |
| [bindAttributePoints](#bindAttributePoints) | bind an array of points to the attribute variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the attribute variable :material-location-enter: **Parameter** `points` :    an array of vertices  |
| [bindAttributeColors](#bindAttributeColors) | bind an array of colors to the attribute variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the attribute variable :material-location-enter: **Parameter** `colors` :    an array of colors corresponding to vertices  |
| [bindUniformPoint](#bindUniformPoint) | bind a point to the uniform variable for the current program object. |
| [bindUniformSize](#bindUniformSize) | bind a size to the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `size` :    a size to pass to the uniform variable :material-location-enter: **Parameter** `scale` :    whether to scale the given size by screen scale  |
| [bindUniformTexture](#bindUniformTexture) | bind a texture unit to the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `unit` :    a texture unit to pass to the uniform variable  |
| [bindUniformInteger](#bindUniformInteger) | bind an integer value to the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `value` :    a value to pass to the uniform variable  |
| [bindUniformFloat](#bindUniformFloat) | bind a float value to the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `value` :    a value to pass to the uniform variable  |
| [bindUniformFloatArray](#bindUniformFloatArray) | bind a float array to the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `count` :    a length of the array :material-location-enter: **Parameter** `array` :    a value to pass to the uniform variable  |
| [bindMatrices](#bindMatrices) | bind a matrices to the uniform variables for the current program object  |

## Variable Details

### fragmentHash<a name="fragmentHash"></a>

!!! variable "uint32_t fragmentHash"

    fragment shader source hash

### hasher<a name="hasher"></a>

!!! variable "hash&lt;string&gt; hasher"

    string hasher

### programObject<a name="programObject"></a>

!!! variable "uint32_t programObject"

    OpenGL program object

### vertexHash<a name="vertexHash"></a>

!!! variable "uint32_t vertexHash"

    vertex shader source hash

## Function Details

### Shader<a name="Shader"></a>

!!! function "Shader()"

    default constructor

### bindAttributeColors<a name="bindAttributeColors"></a>

!!! function "void bindAttributeColors(const char&#42; name, const Color colors[]) const"

    bind an array of colors to the attribute variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the attribute variable
    :material-location-enter: **Parameter** `colors`
    :    an array of colors corresponding to vertices

### bindAttributePoints<a name="bindAttributePoints"></a>

!!! function "void bindAttributePoints(const char&#42; name, const Point points[]) const"

    bind an array of points to the attribute variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the attribute variable
    :material-location-enter: **Parameter** `points`
    :    an array of vertices

### bindMatrices<a name="bindMatrices"></a>

!!! function "void bindMatrices() const"

    bind a matrices to the uniform variables for the current program object

### bindUniformFloat<a name="bindUniformFloat"></a>

!!! function "void bindUniformFloat(const char&#42; name, float value) const"

    bind a float value to the uniform variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
    :material-location-enter: **Parameter** `value`
    :    a value to pass to the uniform variable

### bindUniformFloatArray<a name="bindUniformFloatArray"></a>

!!! function "void bindUniformFloatArray(const char&#42; name, int count, const float&#42; array) const"

    bind a float array to the uniform variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
    :material-location-enter: **Parameter** `count`
    :    a length of the array
    :material-location-enter: **Parameter** `array`
    :    a value to pass to the uniform variable

### bindUniformInteger<a name="bindUniformInteger"></a>

!!! function "void bindUniformInteger(const char&#42; name, int value) const"

    bind an integer value to the uniform variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
    :material-location-enter: **Parameter** `value`
    :    a value to pass to the uniform variable

### bindUniformPoint<a name="bindUniformPoint"></a>

!!! function "void bindUniformPoint(const char&#42; name, Point point) const"

    bind a point to the uniform variable for the current program object.
    !!! note
         the point will be converted to the screen coordinates internally.
    :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
    :material-location-enter: **Parameter** `point`
    :    a point to pass to the uniform variable

### bindUniformSize<a name="bindUniformSize"></a>

!!! function "void bindUniformSize(const char&#42; name, Size size, bool scale = true) const"

    bind a size to the uniform variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
    :material-location-enter: **Parameter** `size`
    :    a size to pass to the uniform variable
    :material-location-enter: **Parameter** `scale`
    :    whether to scale the given size by screen scale

### bindUniformTexture<a name="bindUniformTexture"></a>

!!! function "void bindUniformTexture(const char&#42; name, int unit) const"

    bind a texture unit to the uniform variable for the current program object
    :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
    :material-location-enter: **Parameter** `unit`
    :    a texture unit to pass to the uniform variable

### buildProgram<a name="buildProgram"></a>

!!! function "void buildProgram(const string&amp; vertexShaderSource, const string&amp; fragmentShaderSource)"

    build program object
    :material-location-enter: **Parameter** `vertexShaderSource`
    :    a source code of vertex shader
    :material-location-enter: **Parameter** `fragmentShaderSource`
    :    a source code of fragment shader

### deleteProgram<a name="deleteProgram"></a>

!!! function "void deleteProgram()"

    delete program

### getAttributeLocation<a name="getAttributeLocation"></a>

!!! function "int32_t getAttributeLocation(const char&#42; name) const"

    get attribute variable location

### getProgramObject<a name="getProgramObject"></a>

!!! function "uint32_t getProgramObject() const"

    get program object

### getUniformLocation<a name="getUniformLocation"></a>

!!! function "int32_t getUniformLocation(const char&#42; name) const"

    get uniform variable location

### loadShader<a name="loadShader"></a>

!!! function "virtual void loadShader() = 0"

    load shader

### ~Shader<a name="_u007eShader"></a>

!!! function "virtual ~Shader()"

    destructor
