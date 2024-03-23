---
title: GLController
description:  A singleton class that manage GL states and provide drawer.
generator: doxide
---


# GLController

**class GLController**

 A singleton class that manage GL states and provide drawer.
 


## Variables

| Name | Description |
| ---- | ----------- |
| [glController](#glController) |  singleton instance  |
| [screenSize](#screenSize) |  screen size  |
| [screenTexture](#screenTexture) |  screen texture  |
| [programObject](#programObject) |  program object  |
| [viewportMatrix](#viewportMatrix) |  a matrix to convert viewport points to uv coordinates  |
| [matrixStack](#matrixStack) |  a matrix stack to convert local coordinates to screen coordinates  |
| [screenScale](#screenScale) |  screen scale  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) |  copy assignment operator  |
| [operator=](#operator_u003d) |  move assignment operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [GLController](#GLController) |  default constructor  |
| [GLController](#GLController) |  copy constructor  |
| [GLController](#GLController) |  move constructor  |
| [initialize](#initialize) |  initializer  |
| [setViewport](#setViewport) |  set viewport  |
| [createTexture](#createTexture) |  create texture :material-location-enter: **Parameter** `width` :    texture width to create :material-location-enter: **Parameter** `height` :    texture height to create :material-location-exit: **Parameter** `texture` :    created texture  |
| [deleteTexture](#deleteTexture) |  delete texture :material-location-enter: **Parameter** `texture` :     a texture to delete  |
| [compileShader](#compileShader) |  compile shader :material-location-enter: **Parameter** `type` :    shader type (vertex shader or fragment shader) :material-location-enter: **Parameter** `shaderSource` :    shader source code  |
| [compileProgram](#compileProgram) |  compile program :material-location-enter: **Parameter** `vertexShaderSource` :    a vertex shader source code :material-location-enter: **Parameter** `fragmentShaderSource` :    a fragment shader source code  |
| [linkProgram](#linkProgram) |  link program  |
| [buildBasicFragmentShaderSource](#buildBasicFragmentShaderSource) |  build basic fragment shader source code :material-location-enter: **Parameter** `color` :    a color to draw :material-keyboard-return: **Return** :    a fragment shader source code  |
| [~GLController](#_u007eGLController) |  destructor  |
| [getInstance](#getInstance) |  get singleton instance  |
| [setScreenSize](#setScreenSize) |  set screen size  |
| [getScreenScale](#getScreenScale) |  get screen scale  |
| [setScreenScale](#setScreenScale) |  set screen scale  |
| [getDefaultVertexShaderSource](#getDefaultVertexShaderSource) |  get default vertex shader source code :material-keyboard-return: **Return** :    a default vertex shader source code  |
| [prepareProgram](#prepareProgram) |  prepare program :material-location-enter: **Parameter** `vertexShaderSource` :    a vertex shader source code :material-location-enter: **Parameter** `fragmentShaderSource` :    a fragment shader source code  |
| [bindUniformPoint](#bindUniformPoint) |  specify a point as the value of the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `point` :    a point to pass to the uniform variable  |
| [bindUniformSize](#bindUniformSize) |  specify a size as the value of the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `size` :    a size to pass to the uniform variable  |
| [bindUniformFloat](#bindUniformFloat) |  specify a float value as the value of the uniform variable for the current program object :material-location-enter: **Parameter** `name` :    a name of the uniform variable :material-location-enter: **Parameter** `value` :    a float value to pass to the uniform variable  |
| [preprocess](#preprocess) |  preprocess for draw call  |
| [drawArrays](#drawArrays) |  draw arrays by basic shader with specified color :material-location-enter: **Parameter** `type` :    a primitive type :material-location-enter: **Parameter** `vertices` :    vertices of a lines or a polygons :material-location-enter: **Parameter** `count` :    length of the vertices array :material-location-enter: **Parameter** `color` :    a color of the primitive  |
| [drawArrays](#drawArrays) |  draw arrays. |

## Variable Details

### glController<a name="glController"></a>

!!! variable "static unique_ptr&lt;GLController&gt; glController"

     singleton instance
    

### matrixStack<a name="matrixStack"></a>

!!! variable "vector&lt;AffineTransform&gt; matrixStack"

     a matrix stack to convert local coordinates to screen coordinates
    

### programObject<a name="programObject"></a>

!!! variable "unique_ptr&lt;GLuint&gt; programObject"

     program object
    

### screenScale<a name="screenScale"></a>

!!! variable "float screenScale"

     screen scale
    

### screenSize<a name="screenSize"></a>

!!! variable "Size screenSize"

     screen size
    

### screenTexture<a name="screenTexture"></a>

!!! variable "unique_ptr&lt;Texture&gt; screenTexture"

     screen texture
    

### viewportMatrix<a name="viewportMatrix"></a>

!!! variable "AffineTransform viewportMatrix"

     a matrix to convert viewport points to uv coordinates
    

## Operator Details

### operator=<a name="operator_u003d"></a>

!!! function "GLController&amp; operator=(const GLController&amp; gl) = delete"

     copy assignment operator
    

!!! function "GLController&amp; operator=(GLController&amp;&amp; gl) = delete"

     move assignment operator
    

## Function Details

### GLController<a name="GLController"></a>
!!! function "GLController()"

     default constructor
    

!!! function "GLController(const GLController&amp; gl) = delete"

     copy constructor
    

!!! function "GLController(GLController&amp;&amp; gl) = delete"

     move constructor
    

### bindUniformFloat<a name="bindUniformFloat"></a>
!!! function "void bindUniformFloat(const char&#42; name, float value) const"

     specify a float value as the value of the uniform variable for the current program object
     :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
     :material-location-enter: **Parameter** `value`
    :    a float value to pass to the uniform variable
    

### bindUniformPoint<a name="bindUniformPoint"></a>
!!! function "void bindUniformPoint(const char&#42; name, Point point) const"

     specify a point as the value of the uniform variable for the current program object
     :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
     :material-location-enter: **Parameter** `point`
    :    a point to pass to the uniform variable
    

### bindUniformSize<a name="bindUniformSize"></a>
!!! function "void bindUniformSize(const char&#42; name, Size size) const"

     specify a size as the value of the uniform variable for the current program object
     :material-location-enter: **Parameter** `name`
    :    a name of the uniform variable
     :material-location-enter: **Parameter** `size`
    :    a size to pass to the uniform variable
    

### buildBasicFragmentShaderSource<a name="buildBasicFragmentShaderSource"></a>
!!! function "string buildBasicFragmentShaderSource(Color color) const"

     build basic fragment shader source code
     :material-location-enter: **Parameter** `color`
    :    a color to draw
     :material-keyboard-return: **Return**
    :    a fragment shader source code
    

### compileProgram<a name="compileProgram"></a>
!!! function "static GLuint compileProgram(const char&#42; vertexShaderSource, const char&#42; fragmentShaderSource)"

     compile program
     :material-location-enter: **Parameter** `vertexShaderSource`
    :    a vertex shader source code
     :material-location-enter: **Parameter** `fragmentShaderSource`
    :    a fragment shader source code
    

### compileShader<a name="compileShader"></a>
!!! function "static GLuint compileShader(ShaderType type, const char&#42; shaderSource)"

     compile shader
     :material-location-enter: **Parameter** `type`
    :    shader type (vertex shader or fragment shader)
     :material-location-enter: **Parameter** `shaderSource`
    :    shader source code
    

### createTexture<a name="createTexture"></a>
!!! function "void createTexture(int width, int height, GLuint&#42; texture) const"

     create texture
     :material-location-enter: **Parameter** `width`
    :    texture width to create
     :material-location-enter: **Parameter** `height`
    :    texture height to create
     :material-location-exit: **Parameter** `texture`
    :    created texture
    

### deleteTexture<a name="deleteTexture"></a>
!!! function "void deleteTexture(GLuint&#42; texture)"

     delete texture
     :material-location-enter: **Parameter** `texture`
    :     a texture to delete
    

### drawArrays<a name="drawArrays"></a>
!!! function "void drawArrays(PrimitiveType type, Point vertices[], int count, Color color)"

     draw arrays by basic shader with specified color
     :material-location-enter: **Parameter** `type`
    :    a primitive type
     :material-location-enter: **Parameter** `vertices`
    :    vertices of a lines or a polygons
     :material-location-enter: **Parameter** `count`
    :    length of the vertices array
     :material-location-enter: **Parameter** `color`
    :    a color of the primitive
    

!!! function "void drawArrays(PrimitiveType type, Point vertices[], int count)"

     draw arrays.
    !!! note
        call `prepareProgram()` before calling this method.
     :material-location-enter: **Parameter** `type`
    :    a primitive type
     :material-location-enter: **Parameter** `vertices`
    :    vertices of a lines or a polygons
     :material-location-enter: **Parameter** `count`
    :    length of the vertices array
    

### getDefaultVertexShaderSource<a name="getDefaultVertexShaderSource"></a>
!!! function "const char&#42; getDefaultVertexShaderSource()"

     get default vertex shader source code
     :material-keyboard-return: **Return**
    :    a default vertex shader source code
    

### getInstance<a name="getInstance"></a>
!!! function "static GLController&#42; getInstance()"

     get singleton instance
    

### getScreenScale<a name="getScreenScale"></a>
!!! function "float getScreenScale() const"

     get screen scale
    

### initialize<a name="initialize"></a>
!!! function "void initialize()"

     initializer
    

### linkProgram<a name="linkProgram"></a>
!!! function "static GLuint linkProgram(GLuint program)"

     link program
    

### prepareProgram<a name="prepareProgram"></a>
!!! function "void prepareProgram(const char&#42; vertexShaderSource, const char&#42; fragmentShaderSource)"

     prepare program
     :material-location-enter: **Parameter** `vertexShaderSource`
    :    a vertex shader source code
     :material-location-enter: **Parameter** `fragmentShaderSource`
    :    a fragment shader source code
    

### preprocess<a name="preprocess"></a>
!!! function "void preprocess()"

     preprocess for draw call
    

### setScreenScale<a name="setScreenScale"></a>
!!! function "void setScreenScale(float scale)"

     set screen scale
    

### setScreenSize<a name="setScreenSize"></a>
!!! function "void setScreenSize(int width, int height)"

     set screen size
    

### setViewport<a name="setViewport"></a>
!!! function "void setViewport() const"

     set viewport
    

### ~GLController<a name="_u007eGLController"></a>
!!! function "virtual ~GLController()"

     destructor
    

