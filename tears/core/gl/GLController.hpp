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

class MatrixStackScope;
class Texture;

/// A singleton class that manage GL states and provide drawer.
/// @ingroup gl
class GLController {
    friend MatrixStackScope;
    friend Texture;

protected:
    /// singleton instance
    static unique_ptr<GLController> glController;
    /// screen size
    Size screenSize;
    /// screen texture
    unique_ptr<Texture> screenTexture;
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
    /// @param[out] texture created texture
    void createTexture(int width, int height, GLuint* texture) const;
    /// delete texture
    /// @param texture  a texture to delete
    void deleteTexture(GLuint* texture) const;
    /// compile shader
    /// @param type shader type (vertex shader or fragment shader)
    /// @param shaderSource shader source code
    static GLuint compileShader(ShaderType type, const char* shaderSource);
    /// compile program
    /// @param vertexShaderSource a vertex shader source code
    /// @param fragmentShaderSource a fragment shader source code
    static GLuint compileProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    /// link program
    static GLuint linkProgram(GLuint program);
    /// build basic fragment shader source code
    /// @param color a color to draw
    /// @return a fragment shader source code
    string buildBasicFragmentShaderSource(Color color) const;

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
    /// preprocess for draw call
    void preprocess();
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
