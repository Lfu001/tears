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
#include "math/Vector2D.hpp"

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

/// A singleton class that manage GL states and provide drawer.
class GLController {
protected:
    /// singleton instance
    static unique_ptr<GLController> glController;
    /// view size
    Vector2D viewSize;
    /// program object. call glDeleteProgram() before deletion.
    unique_ptr<GLint> programObeject;

protected:
    /// default constructor
    GLController();
    /// copy constuctor
    GLController(const GLController& gl) = delete;
    /// copy assignment operator
    GLController& operator=(const GLController& gl) = delete;
    /// move constructor
    GLController(GLController&& gl) = delete;
    /// move assignment operator
    GLController& operator=(GLController&& gl) = delete;

protected:
    /// initializer
    void initialize() const;
    /// set viewport
    void setViewport() const;
    /// compile shader
    /// @param type shader type (vertex shader or fragment shader)
    /// @param shaderSource shader source code
    static GLuint compileShader(ShaderType type, const char* shaderSource);
    /// compile program
    static GLuint compileProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    /// link program
    static GLuint linkProgram(GLuint program);
    /// set default shader source
    void setDefaultShaderSource();

public:
    /// destructor
    virtual ~GLController();
    /// get singleton instance
    static GLController* getInstance();
    /// set view size
    void setViewSize(int x, int y);
    /// draw components
    void draw();
    /// draw arrays
    /// @param vertices vertices of a lines or a polygons
    /// @param count length of the vertices array
    void drawArrays(PrimitiveType type, Vector2D vertices[], int count) const;
};

}    // namespace tears

#endif /* GLController_hpp */
