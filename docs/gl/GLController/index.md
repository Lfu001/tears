---
title: GLController
description: A singleton class that manage GL states and provide drawer.
generator: doxide
---


# GLController

**class GLController**

A singleton class that manage GL states and provide drawer.

## Variables

| Name | Description |
| ---- | ----------- |
| [glController](#glController) | singleton instance  |
| [screenSize](#screenSize) | screen size [dp]  |
| [screenTexture](#screenTexture) | screen texture  |
| [framebufferStack](#framebufferStack) | a stack of bound framebuffer  |
| [defaultFramebuffer](#defaultFramebuffer) | default bound framebuffer  |
| [viewportSize](#viewportSize) | viewport size [px]  |
| [viewportMatrix](#viewportMatrix) | a matrix to convert viewport points to uv coordinates  |
| [matrixStack](#matrixStack) | a matrix stack to convert local coordinates to screen coordinates  |
| [screenScale](#screenScale) | screen scale  |
| [blendSettings](#blendSettings) | blend settings  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | copy assignment operator  |
| [operator=](#operator_u003d) | move assignment operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [GLController](#GLController) | default constructor  |
| [GLController](#GLController) | copy constructor  |
| [GLController](#GLController) | move constructor  |
| [initialize](#initialize) | initializer  |
| [setScreenSize](#setScreenSize) | set screen size  |
| [setScreenScale](#setScreenScale) | set screen scale  |
| [setViewport](#setViewport) | set viewport :material-location-enter: **Parameter** `width` :    a width of the viewport :material-location-enter: **Parameter** `height` :    a height of the viewport  |
| [setBlendSettings](#setBlendSettings) | set blend settings :material-location-enter: **Parameter** `equation` :    a blend equation :material-location-enter: **Parameter** `factorSrc` :    a blend factor for source :material-location-enter: **Parameter** `factorDst` :    a blend factor for destination  |
| [createTexture](#createTexture) | create texture :material-location-enter: **Parameter** `width` :    texture width to create :material-location-enter: **Parameter** `height` :    texture height to create :material-location-exit: **Parameter** `outTexture` :    created texture  |
| [bindTexture](#bindTexture) | bind texture :material-location-enter: **Parameter** `texture` :    a texture to bind. if `nullptr`, unbind texture.  |
| [setActiveTextureUnit](#setActiveTextureUnit) | set active texture unit :material-location-enter: **Parameter** `unit` :    a texture unit number to activate  |
| [setTextureParameter](#setTextureParameter) | set texture parameter :material-location-enter: **Parameter** `name` :    a name of the texture parameter :material-location-enter: **Parameter** `param` :    a parameter to set  |
| [deleteTexture](#deleteTexture) | delete texture :material-location-enter: **Parameter** `texture` :     a texture to delete  |
| [createFramebuffer](#createFramebuffer) | create framebuffer :material-location-exit: **Parameter** `outFramebuffer` :    created framebuffer  |
| [attachTexture](#attachTexture) | attach texture to the framebuffer :material-location-enter: **Parameter** `texture` :    a texture to be attached to the framebuffer  |
| [bindFramebuffer](#bindFramebuffer) | bind framebuffer :material-location-enter: **Parameter** `framebuffer` :    a framebuffer to bind. if `nullptr`, default framebuffer will be bound.  |
| [deleteFramebuffer](#deleteFramebuffer) | delete framebuffer :material-location-enter: **Parameter** `framebuffer` :    a framebuffer to delete  |
| [compileShader](#compileShader) | compile shader :material-location-enter: **Parameter** `type` :    shader type (vertex shader or fragment shader) :material-location-enter: **Parameter** `shaderSource` :    shader source code  |
| [compileProgram](#compileProgram) | compile program :material-location-enter: **Parameter** `vertexShaderSource` :    a vertex shader source code :material-location-enter: **Parameter** `fragmentShaderSource` :    a fragment shader source code  |
| [linkProgram](#linkProgram) | link program  |
| [useProgram](#useProgram) | use program  |
| [deleteProgram](#deleteProgram) | delete program  |
| [getCurrentProgram](#getCurrentProgram) | get current program object  |
| [getUniformLocation](#getUniformLocation) | get uniform location  |
| [getAttributeLocation](#getAttributeLocation) | get attribute location  |
| [bindUniform1i](#bindUniform1i) | bind int value to the current program object as uniform variable :material-location-enter: **Parameter** `location` :    a location of an uniform variable :material-location-enter: **Parameter** `v0` :    first int value  |
| [bindUniform1f](#bindUniform1f) | bind float value to the current program object as uniform variable :material-location-enter: **Parameter** `location` :    a location of an uniform variable :material-location-enter: **Parameter** `v0` :    first float value  |
| [bindUniform2f](#bindUniform2f) | bind 2-dimension float value to the current program object as uniform variable :material-location-enter: **Parameter** `location` :    a location of an uniform variable :material-location-enter: **Parameter** `v0` :    first float value :material-location-enter: **Parameter** `v1` :    second float value  |
| [bindUniform1fv](#bindUniform1fv) | bind float array to the current program object as uniform variable :material-location-enter: **Parameter** `location` :    a location of an uniform variable :material-location-enter: **Parameter** `count` :    a length of the array :material-location-enter: **Parameter** `value` :    a float array  |
| [bindAttributeNi8v](#bindAttributeNi8v) | bind a int8 array to the current program object as attribute variable :material-location-enter: **Parameter** `location` :     a location of an attribute variable :material-location-enter: **Parameter** `data` :    an array to bind to the current program object :material-location-enter: **Parameter** `dim` :    a dimension of the array element :material-location-enter: **Parameter** `normalize` :    if true, data are converted to the range [0, 1]. otherwise, values will be converted to floats directly without normalization.  |
| [bindAttributeNu8v](#bindAttributeNu8v) | bind a uint8 array to the current program object as attribute variable :material-location-enter: **Parameter** `location` :     a location of an attribute variable :material-location-enter: **Parameter** `data` :    an array to bind to the current program object :material-location-enter: **Parameter** `dim` :    a dimension of the array element :material-location-enter: **Parameter** `normalize` :    if true, data are converted to the range [0, 1]. otherwise, values will be converted to floats directly without normalization.  |
| [bindAttributeNi32v](#bindAttributeNi32v) | bind a uint32 array to the current program object as attribute variable :material-location-enter: **Parameter** `location` :     a location of an attribute variable :material-location-enter: **Parameter** `data` :    an array to bind to the current program object :material-location-enter: **Parameter** `dim` :    a dimension of the array element :material-location-enter: **Parameter** `normalize` :    if true, data are converted to the range [0, 1]. otherwise, values will be converted to floats directly without normalization.  |
| [bindAttributeNu32v](#bindAttributeNu32v) | bind a int32 array to the current program object as attribute variable :material-location-enter: **Parameter** `location` :     a location of an attribute variable :material-location-enter: **Parameter** `data` :    an array to bind to the current program object :material-location-enter: **Parameter** `dim` :    a dimension of the array element :material-location-enter: **Parameter** `normalize` :    if true, data are converted to the range [0, 1]. otherwise, values will be converted to floats directly without normalization.  |
| [bindAttributeNfv](#bindAttributeNfv) | bind a float array to the current program object as attribute variable :material-location-enter: **Parameter** `location` :     a location of an attribute variable :material-location-enter: **Parameter** `data` :    an array to bind to the current program object :material-location-enter: **Parameter** `dim` :    a dimension of the array element  |
| [bindMatrices](#bindMatrices) | bind a projection matrices to the current program object as uniform variable  |
| [checkGLError](#checkGLError) | check if there has been any detectable error since the last call, or since the GL was initialized  |
| [~GLController](#_u007eGLController) | destructor  |
| [getInstance](#getInstance) | get singleton instance  |
| [getScreenSize](#getScreenSize) | get screen size [dp]  |
| [getScreenScale](#getScreenScale) | get screen scale  |
| [getScreenTexture](#getScreenTexture) | get screen texture  |
| [applyMatricesCpu](#applyMatricesCpu) | apply matrices to the vertices on cpu :material-location-enter: **Parameter** `vertices` :    an array of vertices to apply matrices :material-location-enter: **Parameter** `skipUVMatrix` :    whether to skip an affine transformation to convert screen coordinate to uv coordinate (default: true)  |
| [getBlendSettings](#getBlendSettings) | get current blend settings  |
| [prepareProgram](#prepareProgram) | prepare program :material-location-enter: **Parameter** `vertexShaderSource` :    a vertex shader source code :material-location-enter: **Parameter** `fragmentShaderSource` :    a fragment shader source code  |
| [preprocess](#preprocess) | preprocess for draw call  |
| [finalize](#finalize) | finalize drawing for this event loop  |
| [drawArrays](#drawArrays) | draw arrays with specified color :material-location-enter: **Parameter** `type` :    a primitive type :material-location-enter: **Parameter** `vertices` :    vertices of a lines or a polygons :material-location-enter: **Parameter** `colors` :    a color of the vertices :material-location-enter: **Parameter** `count` :    length of the vertices array  |
| [drawArrays](#drawArrays) | draw arrays :material-location-enter: **Parameter** `type` :    a primitive type :material-location-enter: **Parameter** `vertices` :    vertices of a lines or a polygons :material-location-enter: **Parameter** `count` :    length of the vertices array  |

## Variable Details

### blendSettings<a name="blendSettings"></a>

!!! variable "BlendSettings blendSettings"

    blend settings

### defaultFramebuffer<a name="defaultFramebuffer"></a>

!!! variable "int defaultFramebuffer"

    default bound framebuffer

### framebufferStack<a name="framebufferStack"></a>

!!! variable "vector&lt;Framebuffer&#42;&gt; framebufferStack"

    a stack of bound framebuffer

### glController<a name="glController"></a>

!!! variable "static unique_ptr&lt;GLController&gt; glController"

    singleton instance

### matrixStack<a name="matrixStack"></a>

!!! variable "vector&lt;AffineTransform&gt; matrixStack"

    a matrix stack to convert local coordinates to screen coordinates

### screenScale<a name="screenScale"></a>

!!! variable "float screenScale"

    screen scale

### screenSize<a name="screenSize"></a>

!!! variable "Size screenSize"

    screen size [dp]

### screenTexture<a name="screenTexture"></a>

!!! variable "unique_ptr&lt;Texture&gt; screenTexture"

    screen texture

### viewportMatrix<a name="viewportMatrix"></a>

!!! variable "AffineTransform viewportMatrix"

    a matrix to convert viewport points to uv coordinates

### viewportSize<a name="viewportSize"></a>

!!! variable "Size viewportSize"

    viewport size [px]

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

### applyMatricesCpu<a name="applyMatricesCpu"></a>

!!! function "vector&lt;Point&gt; applyMatricesCpu(const vector&lt;Point&gt;&amp; vertices, bool skipUVMatrix = true) const"

    apply matrices to the vertices on cpu
    :material-location-enter: **Parameter** `vertices`
    :    an array of vertices to apply matrices
    :material-location-enter: **Parameter** `skipUVMatrix`
    :    whether to skip an affine transformation to convert screen coordinate to
        uv coordinate (default: true)

### attachTexture<a name="attachTexture"></a>

!!! function "void attachTexture(const GLuint&amp; texture) const"

    attach texture to the framebuffer
    :material-location-enter: **Parameter** `texture`
    :    a texture to be attached to the framebuffer

### bindAttributeNfv<a name="bindAttributeNfv"></a>

!!! function "void bindAttributeNfv(int32_t location, const float&#42; data, uint32_t dim) const"

    bind a float array to the current program object as attribute variable
    :material-location-enter: **Parameter** `location`
    :     a location of an attribute variable
    :material-location-enter: **Parameter** `data`
    :    an array to bind to the current program object
    :material-location-enter: **Parameter** `dim`
    :    a dimension of the array element

### bindAttributeNi32v<a name="bindAttributeNi32v"></a>

!!! function "void bindAttributeNi32v( int32_t location, const int32_t&#42; data, uint32_t dim, bool normalize = false) const"

    bind a uint32 array to the current program object as attribute variable
    :material-location-enter: **Parameter** `location`
    :     a location of an attribute variable
    :material-location-enter: **Parameter** `data`
    :    an array to bind to the current program object
    :material-location-enter: **Parameter** `dim`
    :    a dimension of the array element
    :material-location-enter: **Parameter** `normalize`
    :    if true, data are converted to the range [0, 1]. otherwise, values will be
        converted to floats directly without normalization.

### bindAttributeNi8v<a name="bindAttributeNi8v"></a>

!!! function "void bindAttributeNi8v( int32_t location, const int8_t&#42; data, uint32_t dim, bool normalize = false) const"

    bind a int8 array to the current program object as attribute variable
    :material-location-enter: **Parameter** `location`
    :     a location of an attribute variable
    :material-location-enter: **Parameter** `data`
    :    an array to bind to the current program object
    :material-location-enter: **Parameter** `dim`
    :    a dimension of the array element
    :material-location-enter: **Parameter** `normalize`
    :    if true, data are converted to the range [0, 1]. otherwise, values will be
        converted to floats directly without normalization.

### bindAttributeNu32v<a name="bindAttributeNu32v"></a>

!!! function "void bindAttributeNu32v( int32_t location, const uint32_t&#42; data, uint32_t dim, bool normalize = false) const"

    bind a int32 array to the current program object as attribute variable
    :material-location-enter: **Parameter** `location`
    :     a location of an attribute variable
    :material-location-enter: **Parameter** `data`
    :    an array to bind to the current program object
    :material-location-enter: **Parameter** `dim`
    :    a dimension of the array element
    :material-location-enter: **Parameter** `normalize`
    :    if true, data are converted to the range [0, 1]. otherwise, values will be
        converted to floats directly without normalization.

### bindAttributeNu8v<a name="bindAttributeNu8v"></a>

!!! function "void bindAttributeNu8v( int32_t location, const uint8_t&#42; data, uint32_t dim, bool normalize = false) const"

    bind a uint8 array to the current program object as attribute variable
    :material-location-enter: **Parameter** `location`
    :     a location of an attribute variable
    :material-location-enter: **Parameter** `data`
    :    an array to bind to the current program object
    :material-location-enter: **Parameter** `dim`
    :    a dimension of the array element
    :material-location-enter: **Parameter** `normalize`
    :    if true, data are converted to the range [0, 1]. otherwise, values will be
        converted to floats directly without normalization.

### bindFramebuffer<a name="bindFramebuffer"></a>

!!! function "void bindFramebuffer(const Framebuffer&#42; const framebuffer) const"

    bind framebuffer
    :material-location-enter: **Parameter** `framebuffer`
    :    a framebuffer to bind. if `nullptr`, default framebuffer will be bound.

### bindMatrices<a name="bindMatrices"></a>

!!! function "void bindMatrices() const"

    bind a projection matrices to the current program object as uniform variable

### bindTexture<a name="bindTexture"></a>

!!! function "void bindTexture(const Texture&#42; const texture) const"

    bind texture
    :material-location-enter: **Parameter** `texture`
    :    a texture to bind. if `nullptr`, unbind texture.

### bindUniform1f<a name="bindUniform1f"></a>

!!! function "void bindUniform1f(int32_t location, float v0) const"

    bind float value to the current program object as uniform variable
    :material-location-enter: **Parameter** `location`
    :    a location of an uniform variable
    :material-location-enter: **Parameter** `v0`
    :    first float value

### bindUniform1fv<a name="bindUniform1fv"></a>

!!! function "void bindUniform1fv(int32_t location, int count, const float&#42; value) const"

    bind float array to the current program object as uniform variable
    :material-location-enter: **Parameter** `location`
    :    a location of an uniform variable
    :material-location-enter: **Parameter** `count`
    :    a length of the array
    :material-location-enter: **Parameter** `value`
    :    a float array

### bindUniform1i<a name="bindUniform1i"></a>

!!! function "void bindUniform1i(int32_t location, int v0) const"

    bind int value to the current program object as uniform variable
    :material-location-enter: **Parameter** `location`
    :    a location of an uniform variable
    :material-location-enter: **Parameter** `v0`
    :    first int value

### bindUniform2f<a name="bindUniform2f"></a>

!!! function "void bindUniform2f(int32_t location, float v0, float v1) const"

    bind 2-dimension float value to the current program object as uniform variable
    :material-location-enter: **Parameter** `location`
    :    a location of an uniform variable
    :material-location-enter: **Parameter** `v0`
    :    first float value
    :material-location-enter: **Parameter** `v1`
    :    second float value

### checkGLError<a name="checkGLError"></a>

!!! function "vector&lt;GLErrorType&gt; checkGLError() const"

    check if there has been any detectable error since the last call, or since the GL was
    initialized

### compileProgram<a name="compileProgram"></a>

!!! function "GLuint compileProgram(const char&#42; vertexShaderSource, const char&#42; fragmentShaderSource) const"

    compile program
    :material-location-enter: **Parameter** `vertexShaderSource`
    :    a vertex shader source code
    :material-location-enter: **Parameter** `fragmentShaderSource`
    :    a fragment shader source code

### compileShader<a name="compileShader"></a>

!!! function "GLuint compileShader(ShaderType type, const char&#42; shaderSource) const"

    compile shader
    :material-location-enter: **Parameter** `type`
    :    shader type (vertex shader or fragment shader)
    :material-location-enter: **Parameter** `shaderSource`
    :    shader source code

### createFramebuffer<a name="createFramebuffer"></a>

!!! function "void createFramebuffer(GLuint&#42; outFramebuffer) const"

    create framebuffer
    :material-location-exit: **Parameter** `outFramebuffer`
    :    created framebuffer

### createTexture<a name="createTexture"></a>

!!! function "void createTexture(int width, int height, GLuint&#42; outTexture) const"

    create texture
    :material-location-enter: **Parameter** `width`
    :    texture width to create
    :material-location-enter: **Parameter** `height`
    :    texture height to create
    :material-location-exit: **Parameter** `outTexture`
    :    created texture

### deleteFramebuffer<a name="deleteFramebuffer"></a>

!!! function "void deleteFramebuffer(GLuint&#42; framebuffer) const"

    delete framebuffer
    :material-location-enter: **Parameter** `framebuffer`
    :    a framebuffer to delete

### deleteProgram<a name="deleteProgram"></a>

!!! function "void deleteProgram(uint32_t program) const"

    delete program

### deleteTexture<a name="deleteTexture"></a>

!!! function "void deleteTexture(GLuint&#42; texture) const"

    delete texture
    :material-location-enter: **Parameter** `texture`
    :     a texture to delete

### drawArrays<a name="drawArrays"></a>

!!! function "void drawArrays(PrimitiveType type, const Point vertices[], const Color colors[], int count)"

    draw arrays with specified color
    :material-location-enter: **Parameter** `type`
    :    a primitive type
    :material-location-enter: **Parameter** `vertices`
    :    vertices of a lines or a polygons
    :material-location-enter: **Parameter** `colors`
    :    a color of the vertices
    :material-location-enter: **Parameter** `count`
    :    length of the vertices array

!!! function "void drawArrays(PrimitiveType type, const Point vertices[], int count)"

    draw arrays
    :material-location-enter: **Parameter** `type`
    :    a primitive type
    :material-location-enter: **Parameter** `vertices`
    :    vertices of a lines or a polygons
    :material-location-enter: **Parameter** `count`
    :    length of the vertices array

### finalize<a name="finalize"></a>

!!! function "void finalize()"

    finalize drawing for this event loop

### getAttributeLocation<a name="getAttributeLocation"></a>

!!! function "int32_t getAttributeLocation(uint32_t program, const char&#42; name) const"

    get attribute location

### getBlendSettings<a name="getBlendSettings"></a>

!!! function "BlendSettings getBlendSettings() const"

    get current blend settings

### getCurrentProgram<a name="getCurrentProgram"></a>

!!! function "uint32_t getCurrentProgram() const"

    get current program object

### getInstance<a name="getInstance"></a>

!!! function "static GLController&#42; getInstance()"

    get singleton instance

### getScreenScale<a name="getScreenScale"></a>

!!! function "float getScreenScale() const"

    get screen scale

### getScreenSize<a name="getScreenSize"></a>

!!! function "Size getScreenSize() const"

    get screen size [dp]

### getScreenTexture<a name="getScreenTexture"></a>

!!! function "Texture&#42; getScreenTexture() const"

    get screen texture

### getUniformLocation<a name="getUniformLocation"></a>

!!! function "int32_t getUniformLocation(uint32_t program, const char&#42; name) const"

    get uniform location

### initialize<a name="initialize"></a>

!!! function "void initialize()"

    initializer

### linkProgram<a name="linkProgram"></a>

!!! function "GLuint linkProgram(GLuint program) const"

    link program

### prepareProgram<a name="prepareProgram"></a>

!!! function "uint32_t prepareProgram(const char&#42; vertexShaderSource, const char&#42; fragmentShaderSource) const"

    prepare program
    :material-location-enter: **Parameter** `vertexShaderSource`
    :    a vertex shader source code
    :material-location-enter: **Parameter** `fragmentShaderSource`
    :    a fragment shader source code

### preprocess<a name="preprocess"></a>

!!! function "void preprocess()"

    preprocess for draw call

### setActiveTextureUnit<a name="setActiveTextureUnit"></a>

!!! function "void setActiveTextureUnit(uint32_t unit) const"

    set active texture unit
    :material-location-enter: **Parameter** `unit`
    :    a texture unit number to activate

### setBlendSettings<a name="setBlendSettings"></a>

!!! function "void setBlendSettings(BlendEquationType equation, BlendType factorSrc, BlendType factorDst)"

    set blend settings
    :material-location-enter: **Parameter** `equation`
    :    a blend equation
    :material-location-enter: **Parameter** `factorSrc`
    :    a blend factor for source
    :material-location-enter: **Parameter** `factorDst`
    :    a blend factor for destination

### setScreenScale<a name="setScreenScale"></a>

!!! function "void setScreenScale(float scale)"

    set screen scale

### setScreenSize<a name="setScreenSize"></a>

!!! function "void setScreenSize(int width, int height)"

    set screen size

### setTextureParameter<a name="setTextureParameter"></a>

!!! function "void setTextureParameter(TextureParameterNameType name, TextureParameterType param) const"

    set texture parameter
    :material-location-enter: **Parameter** `name`
    :    a name of the texture parameter
    :material-location-enter: **Parameter** `param`
    :    a parameter to set

### setViewport<a name="setViewport"></a>

!!! function "void setViewport(int width, int height)"

    set viewport
    :material-location-enter: **Parameter** `width`
    :    a width of the viewport
    :material-location-enter: **Parameter** `height`
    :    a height of the viewport

### useProgram<a name="useProgram"></a>

!!! function "void useProgram(uint32_t program) const"

    use program

### ~GLController<a name="_u007eGLController"></a>

!!! function "virtual ~GLController()"

    destructor
