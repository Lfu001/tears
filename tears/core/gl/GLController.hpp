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

class Framebuffer;
class FramebufferScope;
class MatrixStackScope;
class TearsEngine;
class Texture;

/// A singleton class that manage GL states and provide drawer.
/// @ingroup gl
class GLController {
    friend Framebuffer;
    friend FramebufferScope;
    friend MatrixStackScope;
    friend TearsEngine;
    friend Texture;

protected:
    /// singleton instance
    static unique_ptr<GLController> glController;
    /// screen size
    Size screenSize;
    /// screen texture
    unique_ptr<Texture> screenTexture;
    /// a stack of bound framebuffer
    vector<Framebuffer*> framebufferStack;
    /// default bound framebuffer
    int defaultFramebuffer;
    /// program object
    unique_ptr<GLuint> programObject;
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
    GLuint compileShader(ShaderType type, const char* shaderSource);
    /// compile program
    /// @param vertexShaderSource a vertex shader source code
    /// @param fragmentShaderSource a fragment shader source code
    GLuint compileProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    /// link program
    GLuint linkProgram(GLuint program);
    /// build basic fragment shader source code
    /// @param color a color to draw
    /// @return a fragment shader source code
    string buildBasicFragmentShaderSource(Color color) const;
    /// set attributes for default vertex shader
    void setDefaultMatrixAttributes() const;
    /// check if there has been any detectable error since the last call, or since the GL was
    /// initialized
    vector<GLErrorType> checkGLError() const;

public:
    /// destructor
    virtual ~GLController();
    /// get singleton instance
    static GLController* getInstance();
    /// set screen size
    void setScreenSize(int width, int height);
    /// get screen scale
    float getScreenScale() const { return screenScale; }
    /// set screen scale
    void setScreenScale(float scale);
    /// get default vertex shader source code
    /// @return a default vertex shader source code
    const char* getDefaultVertexShaderSource();
    /// prepare program
    /// @param vertexShaderSource a vertex shader source code
    /// @param fragmentShaderSource a fragment shader source code
    void prepareProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    /// specify a vector of points as the value of the attribute variable for the current program
    /// object
    /// @warning hold the returned value until calling drawArrays(), otherwise the attributes might
    /// be disabled.
    /// @param name a name of the attribute variable
    /// @param points an array of vertices
    /// @param count length of the `points`
    unique_ptr<float[]> bindAttributePoints(const char* name, Point points[], int count) const;
    /// specify a vector of colors as the value of the attribute variable for the current program
    /// object
    /// @warning hold the returned value until calling drawArrays(), otherwise the attributes might
    /// be disabled.
    /// @param name a name of the attribute variable
    /// @param colors an array of colors corresponding to vertices
    /// @param count length of the `colors`
    unique_ptr<float[]> bindAttributeColors(const char* name, Color colors[], int count) const;
    /// specify a point as the value of the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param point a point to pass to the uniform variable
    void bindUniformPoint(const char* name, Point point) const;
    /// specify a size as the value of the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param size a size to pass to the uniform variable
    void bindUniformSize(const char* name, Size size) const;
    /// specify a float value as the value of the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param value a float value to pass to the uniform variable
    void bindUniformFloat(const char* name, float value) const;
    /// specify a int value as the value of the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param value a int value to pass to the uniform variable
    void bindUniformInt(const char* name, int value) const;
    /// preprocess for draw call
    void preprocess();
    /// finalize drawing for this event loop
    void finalize();
    /// draw arrays by basic shader with specified color
    /// @param type a primitive type
    /// @param vertices vertices of a lines or a polygons
    /// @param count length of the vertices array
    /// @param color a color of the primitive
    void drawArrays(PrimitiveType type, Point vertices[], int count, Color color);
    /// draw arrays.
    ///!!! note
    ///    call `prepareProgram()` before calling this method.
    /// @param type a primitive type
    /// @param vertices vertices of a lines or a polygons
    /// @param count length of the vertices array
    void drawArrays(PrimitiveType type, Point vertices[], int count);
};

}    // namespace tears

#endif /* GLController_hpp */
