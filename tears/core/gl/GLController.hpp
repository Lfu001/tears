//
//  GLController.hpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef GLController_hpp
#define GLController_hpp

#include <MetalANGLE/GLES2/gl2.h>
#include <memory>
#include "gl/Color.hpp"
#include "math/AffineTransform.hpp"
#include "math/Point.hpp"

namespace tears {

using namespace std;

/// a type of the shader
/// @ingroup gl
enum ShaderType : uint32_t {
    /// vertex shader
    ShaderVertex = GL_VERTEX_SHADER,
    /// fragment shader
    ShaderFragmet = GL_FRAGMENT_SHADER,
};

/// a type of the GL primitives
/// @ingroup gl
enum PrimitiveType : uint32_t {
    /// points
    PrimitivePoints = GL_POINTS,
    /// lines
    PrimitiveLines = GL_LINES,
    /// line loop
    PrimitiveLineLoop = GL_LINE_LOOP,
    /// line strip
    PrimitiveLineStrip = GL_LINE_STRIP,
    /// triangles
    PrimitiveTriangles = GL_TRIANGLES,
    /// triangle strip
    PrimitiveTriangleStrip = GL_TRIANGLE_STRIP,
    /// triangle fan
    PrimitiveTriangleFan = GL_TRIANGLE_FAN,
};

/// a type of the blend factor
/// @ingroup gl
enum BlendType : uint32_t {
    /// $0$
    BlendZero = GL_ZERO,
    /// $1$
    BlendOne = GL_ONE,
    /// $src_{\alpha}$
    BlendSrcAlpha = GL_SRC_ALPHA,
    /// $1 - src_{\alpha}$
    BlendOneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
    /// $dst_{\alpha}$
    BlendDstAlpha = GL_DST_ALPHA,
    /// $1 - dst_{\alpha}$
    BlendOneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
};

/// a error type of the gl
/// @ingroup gl
enum GLErrorType : uint32_t {
    /// No error has been recorded. The value of this symbolic constant is guaranteed to be 0.
    GLErrorNone = GL_NO_ERROR,
    /// An unacceptable value is specified for an enumerated argument. The offending command is
    /// ignored and has no other side effect than to set the error flag.
    GLErrorInvalidEnum = GL_INVALID_ENUM,
    /// A numeric argument is out of range. The offending command is ignored and has no other side
    /// effect than to set the error flag.
    GLErrorInvalidValue = GL_INVALID_VALUE,
    /// The specified operation is not allowed in the current state. The offending command is
    /// ignored and has no other side effect than to set the error flag.
    GLErrorInvalidOperation = GL_INVALID_OPERATION,
    /// The command is trying to render to or read from the framebuffer while the currently bound
    /// framebuffer is not framebuffer complete (i.e. the return value from glCheckFramebufferStatus
    /// is not GL_FRAMEBUFFER_COMPLETE). The offending command is ignored and has no other side
    /// effect than to set the error flag.
    GLErrorInvalidFramebufferOperation = GL_INVALID_OPERATION,
    /// There is not enough memory left to execute the command. The state of the GL is undefined,
    /// except for the state of the error flags, after this error is recorded.
    GLErrorOutOfMemory = GL_OUT_OF_MEMORY,
};

enum TextureParameterNameType : uint32_t;
enum TextureParameterType : int32_t;

class Framebuffer;
class FramebufferScope;
class MatrixStackScope;
class Shader;
class ShaderController;
class ShaderScope;
class TearsEngine;
class Texture;
class TextureScope;

/// A singleton class that manage GL states and provide drawer.
/// @ingroup gl
class GLController {
    friend Framebuffer;
    friend FramebufferScope;
    friend MatrixStackScope;
    friend Shader;
    friend ShaderController;
    friend ShaderScope;
    friend TearsEngine;
    friend Texture;
    friend TextureScope;

protected:
    /// singleton instance
    static unique_ptr<GLController> glController;
    /// screen size [dp]
    Size screenSize;
    /// screen texture
    unique_ptr<Texture> screenTexture;
    /// a stack of bound framebuffer
    vector<Framebuffer*> framebufferStack;
    /// default bound framebuffer
    int defaultFramebuffer;
    /// a matrix to convert viewport points to uv coordinates
    AffineTransform viewportMatrix;
    /// a matrix stack to convert local coordinates to screen coordinates
    vector<AffineTransform> matrixStack;
    /// screen scale
    float screenScale = 1.f;

protected:
    /// default constructor
    GLController();
    /// copy constructor
    GLController(const GLController& gl) = delete;
    /// copy assignment operator
    GLController& operator=(const GLController& gl) = delete;
    /// move constructor
    GLController(GLController&& gl) = delete;
    /// move assignment operator
    GLController& operator=(GLController&& gl) = delete;

protected:
    /// initializer
    void initialize();
    /// set screen size
    void setScreenSize(int width, int height);
    /// set screen scale
    void setScreenScale(float scale);
    /// set viewport
    void setViewport() const;
    /// create texture
    /// @param width texture width to create
    /// @param height texture height to create
    /// @param[out] outTexture created texture
    void createTexture(int width, int height, GLuint* outTexture) const;
    /// bind texture
    /// @param texture a texture to bind. if `nullptr`, unbind texture.
    void bindTexture(const Texture* const texture) const;
    /// set active texture unit
    /// @param unit a texture unit number to activate
    void setActiveTextureUnit(uint32_t unit) const;
    /// set texture parameter
    /// @param name a name of the texture parameter
    /// @param param a parameter to set
    void setTextureParameter(TextureParameterNameType name, TextureParameterType param) const;
    /// delete texture
    /// @param texture  a texture to delete
    void deleteTexture(GLuint* texture) const;
    /// create framebuffer
    /// @param[out] outFramebuffer created framebuffer
    void createFramebuffer(GLuint* outFramebuffer) const;
    /// attach texture to the framebuffer
    /// @param texture a texture to be attached to the framebuffer
    void attachTexture(const GLuint& texture) const;
    /// bind framebuffer
    /// @param framebuffer a framebuffer to bind. if `nullptr`, default framebuffer will be bound.
    void bindFramebuffer(const Framebuffer* const framebuffer) const;
    /// delete framebuffer
    /// @param framebuffer a framebuffer to delete
    void deleteFramebuffer(GLuint* framebuffer) const;
    /// compile shader
    /// @param type shader type (vertex shader or fragment shader)
    /// @param shaderSource shader source code
    GLuint compileShader(ShaderType type, const char* shaderSource) const;
    /// compile program
    /// @param vertexShaderSource a vertex shader source code
    /// @param fragmentShaderSource a fragment shader source code
    GLuint compileProgram(const char* vertexShaderSource, const char* fragmentShaderSource) const;
    /// link program
    GLuint linkProgram(GLuint program) const;
    /// use program
    void useProgram(uint32_t program) const;
    /// delete program
    void deleteProgram(uint32_t program) const;
    /// get current program object
    uint32_t getCurrentProgram() const;
    /// get uniform location
    int32_t getUniformLocation(uint32_t program, const char* name) const;
    /// get attribute location
    int32_t getAttributeLocation(uint32_t program, const char* name) const;
    /// bind int value to the current program object as uniform variable
    /// @param location a location of an uniform variable
    /// @param v0 first int value
    void bindUniform1i(int32_t location, int v0) const;
    /// bind float value to the current program object as uniform variable
    /// @param location a location of an uniform variable
    /// @param v0 first float value
    void bindUniform1f(int32_t location, float v0) const;
    /// bind 2-dimension float value to the current program object as uniform variable
    /// @param location a location of an uniform variable
    /// @param v0 first float value
    /// @param v1 second float value
    void bindUniform2f(int32_t location, float v0, float v1) const;
    /// bind a int8 array to the current program object as attribute variable
    /// @param location  a location of an attribute variable
    /// @param data an array to bind to the current program object
    /// @param dim a dimension of the array element
    /// @param normalize if true, data are converted to the range [0, 1]. otherwise, values will be
    /// converted to floats directly without normalization.
    void bindAttributeNi8v(
        int32_t location,
        const int8_t* data,
        uint32_t dim,
        bool normalize = false) const;
    /// bind a uint8 array to the current program object as attribute variable
    /// @param location  a location of an attribute variable
    /// @param data an array to bind to the current program object
    /// @param dim a dimension of the array element
    /// @param normalize if true, data are converted to the range [0, 1]. otherwise, values will be
    /// converted to floats directly without normalization.
    void bindAttributeNu8v(
        int32_t location,
        const uint8_t* data,
        uint32_t dim,
        bool normalize = false) const;
    /// bind a uint32 array to the current program object as attribute variable
    /// @param location  a location of an attribute variable
    /// @param data an array to bind to the current program object
    /// @param dim a dimension of the array element
    /// @param normalize if true, data are converted to the range [0, 1]. otherwise, values will be
    /// converted to floats directly without normalization.
    void bindAttributeNi32v(
        int32_t location,
        const int32_t* data,
        uint32_t dim,
        bool normalize = false) const;
    /// bind a int32 array to the current program object as attribute variable
    /// @param location  a location of an attribute variable
    /// @param data an array to bind to the current program object
    /// @param dim a dimension of the array element
    /// @param normalize if true, data are converted to the range [0, 1]. otherwise, values will be
    /// converted to floats directly without normalization.
    void bindAttributeNu32v(
        int32_t location,
        const uint32_t* data,
        uint32_t dim,
        bool normalize = false) const;
    /// bind a float array to the current program object as attribute variable
    /// @param location  a location of an attribute variable
    /// @param data an array to bind to the current program object
    /// @param dim a dimension of the array element
    void bindAttributeNfv(int32_t location, const float* data, uint32_t dim) const;
    /// bind a projection matrices to the current program object as uniform variable
    void bindMatrices() const;
    /// check if there has been any detectable error since the last call, or since the GL was
    /// initialized
    vector<GLErrorType> checkGLError() const;

public:
    /// destructor
    virtual ~GLController();
    /// get singleton instance
    static GLController* getInstance();
    /// get screen size [dp]
    Size getScreenSize() const { return screenSize; }
    /// get screen scale
    float getScreenScale() const { return screenScale; }
    /// prepare program
    /// @param vertexShaderSource a vertex shader source code
    /// @param fragmentShaderSource a fragment shader source code
    uint32_t prepareProgram(const char* vertexShaderSource, const char* fragmentShaderSource) const;
    /// preprocess for draw call
    void preprocess();
    /// finalize drawing for this event loop
    void finalize();
    /// draw arrays with specified color
    /// @param type a primitive type
    /// @param vertices vertices of a lines or a polygons
    /// @param colors a color of the vertices
    /// @param count length of the vertices array
    void drawArrays(PrimitiveType type, Point vertices[], Color colors[], int count);
    /// draw arrays
    /// @param type a primitive type
    /// @param vertices vertices of a lines or a polygons
    /// @param count length of the vertices array
    void drawArrays(PrimitiveType type, Point vertices[], int count);
};

}    // namespace tears

#endif /* GLController_hpp */
