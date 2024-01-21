//
//  GLController.hpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef GLController_hpp
#define GLController_hpp

#include <memory>
#include <MetalANGLE/GLES2/gl2.h>
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
};

}    // namespace tears

#endif /* GLController_hpp */
