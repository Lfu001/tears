//
//  GLController.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <cstring>
#include <sstream>
#include <vector>
#include "gl/MatrixStackScope.hpp"
#include "utils/CallbackScope.hpp"
#include "utils/DebugUtil.hpp"
#include "GLController.hpp"

namespace tears {

using namespace std;

// singleton instance
unique_ptr<GLController> GLController::glController = nullptr;

// constructor
GLController::GLController() {
    initialize();
}

// destructor
GLController::~GLController() {
    try {
        if (programObject) {
            glDeleteProgram(*programObject);
        }
    } catch (exception e) {}
}

// initializer
void GLController::initialize() {
    glEnable(GL_BLEND);
    glBlendFunc(BlendSrcAlpha, BlendOneMinusSrcAlpha);
}

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

// prepare program
void GLController::prepareProgram(
    const char* vertexShaderSource,
    const char* fragmentShaderSource) {
    if (!vertexShaderSource || !fragmentShaderSource) {
        tears_assert(false);
        return;
    }
    programObject = make_unique<GLuint>(compileProgram(vertexShaderSource, fragmentShaderSource));
    glUseProgram(*programObject);
}

// get default vertex shader source
const char* GLController::getDefaultVertexShaderSource() {
    const char* src = "uniform mat3 uMatrixMVP;"
                      "uniform mat3 uMatrixU;"
                      "attribute vec2 aPosition;"
                      "void main() {"
                      "   gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
                      "}";
    return src;
}

// build fragment shader source code
string GLController::buildBasicFragmentShaderSource(Color color) const {
    stringstream ss;
    ss << "precision highp float;"
       << "void main() {"
       << "    gl_FragColor = vec4(" + to_string(color.red / 255.f) + ", "
              + to_string(color.green / 255.f) + ", " + to_string(color.blue / 255.f) + ", "
              + to_string(color.alpha / 255.f) + ");"
       << "}";
    return ss.str();
}

// set viewport
void GLController::setViewport() const {
    glViewport(0, 0, screenSize.width, screenSize.height);
}

// set screen size
void GLController::setScreenSize(int width, int height) {
    if (width == screenSize.width && height == screenSize.height) {    /// if size is not changed
        return;
    }

    screenSize = Size(width, height);
    viewportMatrix = AffineTransform();
    viewportMatrix.scale(Size(2.f / width, 2.f / height));
    viewportMatrix.translate(Size(-1.f, -1.f));
    viewportMatrix.reflectY();

    if (screenTexture > 0) {    /// if unnecessary screen texture is reserved
        glDeleteTextures(1, &screenTexture);
        screenTexture = 0;
    }
    createTexture(width, height, &screenTexture);
}

// set screen scale
void GLController::setScreenScale(float scale) {
    screenScale = scale;
}

// create texture
void GLController::createTexture(int width, int height, GLuint* texture) const {
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// specify a point as the value of the uniform variable for the current program object
void GLController::bindUniformPoint(const char* name, Point point) const {
    GLint uniLocation = glGetUniformLocation(*programObject, name);
    /// program have to be compiled before adding uniform variable
    tears_assert(uniLocation >= 0);
    MatrixStackScope mss;
    AffineTransform* affine = mss.getTopMatrix();
    affine->scale(Size(screenScale, screenScale));
    Point t = point.applyTransform(matrixStack.back());
    glUniform2f(uniLocation, t.x, screenSize.height - t.y);
}

// specify a size as the value of the uniform variable for the current program object
void GLController::bindUniformSize(const char* name, Size size) const {
    GLint uniLocation = glGetUniformLocation(*programObject, name);
    /// program have to be compiled before adding uniform variable
    tears_assert(uniLocation >= 0);
    glUniform2f(uniLocation, size.width * screenScale, size.height * screenScale);
}

// specify a float value as the value of the uniform variable for the current program object
void GLController::bindUniformFloat(const char* name, float value) const {
    GLint uniLocation = glGetUniformLocation(*programObject, name);
    /// program have to be compiled before adding uniform variable
    tears_assert(uniLocation >= 0);
    glUniform1f(uniLocation, value);
}

// preprocess for draw call
void GLController::preprocess() {
    setViewport();
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// draw arrays by basic shader with specified color
void GLController::drawArrays(PrimitiveType type, Point vertices[], int count, Color color) {
    const char* vs = getDefaultVertexShaderSource();
    unique_ptr<char[]> fsOwn;
    string f = buildBasicFragmentShaderSource(color);
    fsOwn = make_unique<char[]>(f.size() + 1);
    strcpy(fsOwn.get(), f.c_str());
    prepareProgram(vs, fsOwn.get());

    drawArrays(type, vertices, count);
}

// draw arrays
void GLController::drawArrays(PrimitiveType type, Point vertices[], int count) {
    tears_assert(programObject);
    CallbackScope cs([this]() {
        if (programObject) {
            glDeleteProgram(*programObject.get());
            programObject = nullptr;
        }
    });

    /// transform array of Points into 1D array
    float v[count * 2];
    for (int i = 0; i < count; i++) {
        Point* t = &vertices[i];
        v[2 * i] = t->x;
        v[2 * i + 1] = t->y;
    }

    GLint posLocation = glGetAttribLocation(*programObject, "aPosition");
    tears_assert(posLocation >= 0);
    glVertexAttribPointer(posLocation, 2, GL_FLOAT, GL_FALSE, 0, v);
    glEnableVertexAttribArray(posLocation);

    MatrixStackScope mss;
    AffineTransform* affine = mss.getTopMatrix();
    affine->scale(Size(screenScale, screenScale));
    unique_ptr<float[]> mvpMat = matrixStack.back().flatten();
    GLint mvpMatLocation = glGetUniformLocation(*programObject, "uMatrixMVP");
    tears_assert(mvpMatLocation >= 0);
    glUniformMatrix3fv(mvpMatLocation, 1, GL_FALSE, mvpMat.get());

    unique_ptr<float[]> uMat = viewportMatrix.flatten();
    GLint uMatLocation = glGetUniformLocation(*programObject, "uMatrixU");
    tears_assert(uMatLocation >= 0);
    glUniformMatrix3fv(uMatLocation, 1, GL_FALSE, uMat.get());

    glDrawArrays(type, 0, count);
}

}    // namespace tears
