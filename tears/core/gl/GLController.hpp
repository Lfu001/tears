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
enum ShaderType : uint32_t {
    /// vertex shader
    ShaderVertex = GL_VERTEX_SHADER,
    /// fragment shader
    ShaderFragmet = GL_FRAGMENT_SHADER,
};

/// a type of the GL primitives
enum PrimitiveType : uint32_t {
    PrimitivePoints = GL_POINTS,
    PrimitiveLines = GL_LINES,
    PrimitiveLineLoop = GL_LINE_LOOP,
    PrimitiveLineStrip = GL_LINE_STRIP,
    PrimitiveTriangles = GL_TRIANGLES,
    PrimitiveTriangleStrip = GL_TRIANGLE_STRIP,
    PrimitiveTriangleFan = GL_TRIANGLE_FAN,
};

/// a type of the blend factor
enum BlendType : uint32_t {
    BlendZero = GL_ZERO,
    BlendOne = GL_ONE,
    BlendSrcAlpha = GL_SRC_ALPHA,
    BlendOneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
    BlendDstAlpha = GL_DST_ALPHA,
    BlendOneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
};

class MatrixStackScope;

/// A singleton class that manage GL states and provide drawer.
class GLController {
    friend MatrixStackScope;

protected:
    /// singleton instance
    static unique_ptr<GLController> glController;
    /// view size
    Size viewSize;
    /// program object
    unique_ptr<GLuint> programObject;
    /// a matrix to convert viewport points to uv coordinates
    AffineTransform viewportMatrix;
    /// a matrix stack to convert local coordinates to global
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
    /// prepare program
    /// @param vertexShaderSource a vertex shader source code
    /// @param fragmentShaderSource a fragment shader source code
    void prepareProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    /// get default vertex shader source code
    /// @return a default vertex shader source code
    const char* getDefaultVertexShaderSource();
    /// build basic fragment shader source code
    /// @param color a color to draw
    /// @return a fragment shader source code
    string buildBasicFragmentShaderSource(Color color) const;

public:
    /// destructor
    virtual ~GLController();
    /// get singleton instance
    static GLController* getInstance();
    /// set view size
    void setViewSize(int x, int y);
    /// get screen scale
    float getScreenScale() const { return screenScale; }
    /// set screen scale
    void setScreenScale(float scale);
    /// preprocess for draw call
    void preprocess();
    /// draw arrays with specified color
    /// @param vertices vertices of a lines or a polygons
    /// @param count length of the vertices array
    /// @param color a color of the primitive
    void drawArrays(PrimitiveType type, Point vertices[], int count, Color color);
    /// draw arrays. call `prepareProgram()` before this method is called.
    /// @param vertices vertices of a lines or a polygons
    /// @param count length of the vertices array
    void drawArrays(PrimitiveType type, Point vertices[], int count);
};

}    // namespace tears

#endif /* GLController_hpp */
