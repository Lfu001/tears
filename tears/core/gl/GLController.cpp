//
//  GLController.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include <vector>
#include "utils/DebugUtil.hpp"
#include "GLController.hpp"

namespace tears {

using namespace std;

/// default source for vertex shader
constexpr const char* VERTEX_SHADER_DEFAULT_SORUCE = R"(
attribute vec4 aPosition;
void main() {
    gl_Position = aPosition;
}
)";
/// default source for fragment shader
constexpr const char* FRAGMENT_SHADER_DEFAULT_SORUCE = R"(
precision highp float;
void main() {
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
)";

// singleton instance
unique_ptr<GLController> GLController::glController = nullptr;

// constructor
GLController::GLController() {}

// destructor
GLController::~GLController() {
    try {
        if (programObeject) {
            glDeleteProgram(*programObeject);
        }
    } catch (exception e) {}
}

// initializer
void GLController::initialize() const {}

// get singleton instance
GLController* GLController::getInstance() {
    if (!glController) {    /// if singleton instance is not constructed yet
        glController.reset(new GLController());
    }
    return glController.get();
}

// compile shader
GLuint GLController::compileShader(ShaderType type, const char* shaderSource) {
    GLuint shader = glCreateShader(type);

    const char* sourceArray[1] = {shaderSource};
    glShaderSource(shader, 1, sourceArray, nullptr);
    glCompileShader(shader);

    GLint compileResult;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

    if (compileResult == 0) {    /// if compilation failed
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength > 1) {    /// if there is an error message from shader compiler
            vector<GLchar> infoLog(infoLogLength);
            glGetShaderInfoLog(shader, static_cast<GLsizei>(infoLog.size()), nullptr, &infoLog[0]);
            tears_printf("shader compilation failed: %s\n", &infoLog[0]);
        } else {
            tears_printf("shader compilation failed. <Empty log message>\n");
        }
        tears_assert(false);
        glDeleteShader(shader);
        shader = 0;
    }

    return shader;
}

// compile program
GLuint GLController::compileProgram(
    const char* vertexShaderSource,
    const char* fragmentShaderSource) {
    GLuint vs = compileShader(ShaderVertex, vertexShaderSource);
    GLuint fs = compileShader(ShaderFragmet, fragmentShaderSource);

    if (vs == 0 || fs == 0) {    /// if vertex shader or fragment shader failed to compile
        glDeleteShader(fs);
        glDeleteShader(vs);
        return 0;
    }

    GLuint program = glCreateProgram();

    glAttachShader(program, vs);
    glDeleteShader(vs);

    glAttachShader(program, fs);
    glDeleteShader(fs);

    program = linkProgram(program);
    return program;
}

// link program
GLuint GLController::linkProgram(GLuint program) {
    glLinkProgram(program);
    if (glGetError() != GL_NO_ERROR) {    /// if error occred on program linking
        tears_assert(false);
        return 0;
    }

    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == 0) {    /// if program linking failed
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 1) {    /// if there is an error message from linker
            vector<GLchar> infoLog(infoLogLength);
            glGetProgramInfoLog(
                program,
                static_cast<GLsizei>(infoLog.size()),
                nullptr,
                &infoLog[0]);
            tears_printf("program link failed: %s\n", &infoLog[0]);
        } else {
            tears_printf("program link failed. <Empty log message>");
        }
        tears_assert(false);
        glDeleteProgram(program);
        return 0;
    }

    return program;
}

// set default shader source
void GLController::setDefaultShaderSource() {
    //    vertexSource.reset(&VERTEX_SHADER_DEFAULT_SORUCE);
}

// set viewport
void GLController::setViewport() const {
    glViewport(0, 0, viewSize.getWidth(), viewSize.getHeight());
}

// set view size
void GLController::setViewSize(int x, int y) {
    viewSize = Vector2D(x, y);
}

// draw components
void GLController::draw() {
    setViewport();
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    if (!programObeject) {    /// if program is not set yet
        programObeject = make_unique<GLint>(
            compileProgram(VERTEX_SHADER_DEFAULT_SORUCE, FRAGMENT_SHADER_DEFAULT_SORUCE));
    }
    glUseProgram(*programObeject);
    GLfloat vertices[] = {
        0.0f,
        0.5f,
        0.0f,
        -0.5f,
        -0.5f,
        0.0f,
        0.5f,
        -0.5f,
        0.0f,
    };
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

}    // namespace tears
