//
//  GLController.cpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/Framebuffer.hpp"
#include "gl/MatrixStackScope.hpp"
#include "gl/Texture.hpp"
#include "gl/shader/CopyShader.hpp"
#include "gl/shader/ShaderController.hpp"
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
GLController::~GLController() {}

// initializer
void GLController::initialize() {
    glEnable(GL_BLEND);
    glBlendFunc(BlendSrcAlpha, BlendOneMinusSrcAlpha);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFramebuffer);
}

// get singleton instance
GLController* GLController::getInstance() {
    if (!glController) {    /// if singleton instance is not constructed yet
        glController.reset(new GLController());
    }
    return glController.get();
}

// check if there has been any detectable error since the last call, or since the GL was initialized
vector<GLErrorType> GLController::checkGLError() const {
    vector<GLErrorType> err;
    while (true) {
        GLErrorType status = (GLErrorType)glGetError();
        err.push_back(status);
        if (status == GLErrorNone)
            break;
    };
    tears_assert(err[0] == GLErrorNone);
    return err;
}

// compile shader
GLuint GLController::compileShader(ShaderType type, const char* shaderSource) const {
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

    checkGLError();

    return shader;
}

// compile program
GLuint GLController::compileProgram(
    const char* vertexShaderSource,
    const char* fragmentShaderSource) const {
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

    checkGLError();

    program = linkProgram(program);
    return program;
}

// link program
GLuint GLController::linkProgram(GLuint program) const {
    glLinkProgram(program);
    if (checkGLError()[0] != GLErrorNone) {    /// if error occurred on program linking
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
uint32_t GLController::prepareProgram(
    const char* vertexShaderSource,
    const char* fragmentShaderSource) const {
    if (!vertexShaderSource || !fragmentShaderSource) {
        tears_assert(false);
        return 0;
    }
    uint32_t program = compileProgram(vertexShaderSource, fragmentShaderSource);
    checkGLError();
    return program;
}

// use program
void GLController::useProgram(uint32_t program) const {
    glUseProgram(program);
    checkGLError();
}

// delete program
void GLController::deleteProgram(uint32_t program) const {
    glDeleteProgram(program);
    checkGLError();
}

// get current program object
uint32_t GLController::getCurrentProgram() const {
    ShaderController* sc = ShaderController::getInstance();
    const Shader* shader = sc->getCurrentShader();
    tears_assert(shader);
    return shader->getProgramObject();
}

// get uniform location
int32_t GLController::getUniformLocation(uint32_t program, const char* name) const {
    /// call after the program successfully linked
    int32_t location = glGetUniformLocation(program, name);
    checkGLError();
    return location;
}

// get attribute location
int32_t GLController::getAttributeLocation(uint32_t program, const char* name) const {
    /// call after the program successfully linked
    int32_t location = glGetAttribLocation(program, name);
    checkGLError();
    return location;
}

// bind int value to the current program object as uniform variable
void GLController::bindUniform1i(int32_t location, int v0) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    glUniform1i(location, v0);
    checkGLError();
}

// bind float value to the current program object as uniform variable
void GLController::bindUniform1f(int32_t location, float v0) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    glUniform1f(location, v0);
    checkGLError();
}

// bind 2-dimension float value to the current program object as uniform variable
void GLController::bindUniform2f(int32_t location, float v0, float v1) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    glUniform2f(location, v0, v1);
    checkGLError();
}

// bind a int8 array to the current program object as attribute variable
void GLController::bindAttributeNi8v(
    int32_t location,
    const int8_t* data,
    uint32_t dim,
    bool normalize /* = false */) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    tears_assert((1 <= dim && dim <= 4) || (dim == GL_RGBA && normalize));
    uint8_t norm = (normalize) ? GL_TRUE : GL_FALSE;
    glVertexAttribPointer(location, dim, GL_BYTE, norm, 0, data);
    checkGLError();
    glEnableVertexAttribArray(location);
    checkGLError();
}

// bind a uint8 array to the current program object as attribute variable
void GLController::bindAttributeNu8v(
    int32_t location,
    const uint8_t* data,
    uint32_t dim,
    bool normalize /* = false */) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    tears_assert((1 <= dim && dim <= 4) || (dim == GL_RGBA && normalize));
    uint8_t norm = (normalize) ? GL_TRUE : GL_FALSE;
    glVertexAttribPointer(location, dim, GL_UNSIGNED_BYTE, norm, 0, data);
    checkGLError();
    glEnableVertexAttribArray(location);
    checkGLError();
}

// bind a uint32 array to the current program object as attribute variable
void GLController::bindAttributeNi32v(
    int32_t location,
    const int32_t* data,
    uint32_t dim,
    bool normalize /* = false */) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    tears_assert((1 <= dim && dim <= 4) || (dim == GL_RGBA && normalize));
    uint8_t norm = (normalize) ? GL_TRUE : GL_FALSE;
    glVertexAttribPointer(location, dim, GL_UNSIGNED_INT, norm, 0, data);
    checkGLError();
    glEnableVertexAttribArray(location);
    checkGLError();
}

// bind a int32 array to the current program object as attribute variable
void GLController::bindAttributeNu32v(
    int32_t location,
    const uint32_t* data,
    uint32_t dim,
    bool normalize /* = false */) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    tears_assert((1 <= dim && dim <= 4) || (dim == GL_RGBA && normalize));
    uint8_t norm = (normalize) ? GL_TRUE : GL_FALSE;
    glVertexAttribPointer(location, dim, GL_INT, norm, 0, data);
    checkGLError();
    glEnableVertexAttribArray(location);
    checkGLError();
}

// bind a float array to the current program object as attribute variable
void GLController::bindAttributeNfv(int32_t location, const float* data, uint32_t dim) const {
    /// call after the program successfully linked
    tears_assert(location >= 0);
    tears_assert(1 <= dim && dim <= 4);
    glVertexAttribPointer(location, dim, GL_FLOAT, GL_FALSE, 0, data);
    checkGLError();
    glEnableVertexAttribArray(location);
    checkGLError();
}

// bind a projection matrices to the current program object as uniform variable
void GLController::bindMatrices() const {
    uint32_t program = getCurrentProgram();

    unique_ptr<float[]> mvpMat = matrixStack.back().flatten();
    int32_t mvpMatLocation = getUniformLocation(program, "uMatrixMVP");
    tears_assert(mvpMatLocation >= 0);
    glUniformMatrix3fv(mvpMatLocation, 1, GL_FALSE, mvpMat.get());

    unique_ptr<float[]> uMat = viewportMatrix.flatten();
    int32_t uMatLocation = getUniformLocation(program, "uMatrixU");
    tears_assert(uMatLocation >= 0);
    glUniformMatrix3fv(uMatLocation, 1, GL_FALSE, uMat.get());
}

// set viewport
void GLController::setViewport() const {
    Size screenTexSize = screenTexture->getSize();
    int w = (int)screenTexSize.width;
    int h = (int)screenTexSize.height;
    glViewport(0, 0, w, h);
    tears_printf("Viewport set to (%d, %d)\n", w, h);

    checkGLError();
}

// set screen size
void GLController::setScreenSize(int width, int height) {
    if (width == screenSize.width && height == screenSize.height) {    /// if size is not changed
        return;
    }

    screenSize = Size(width / screenScale, height / screenScale);
    viewportMatrix = AffineTransform();
    viewportMatrix.scale(Size(2.f / width, 2.f / height));
    viewportMatrix.translate(Size(-1.f, -1.f));
    viewportMatrix.reflectY();

    screenTexture = nullptr;
    screenTexture = make_unique<Texture>(width, height);
}

// set screen scale
void GLController::setScreenScale(float scale) {
    screenScale = scale;
}

// create texture
void GLController::createTexture(int width, int height, GLuint* outTexture) const {
    glGenTextures(1, outTexture);
    tears_printf("create texture: %d\n", *outTexture);
    glBindTexture(GL_TEXTURE_2D, *outTexture);
    tears_printf("bind texture: %d\n", *outTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    tears_printf("allocate texture: %d\n", *outTexture);
    glBindTexture(GL_TEXTURE_2D, 0);
    tears_printf("bind default texture\n");

    checkGLError();
}

// bind texture
void GLController::bindTexture(const Texture* const texture) const {
    if (texture) {    /// if texture is specified
        glBindTexture(GL_TEXTURE_2D, texture->getName());
        tears_printf("bind texture: %d\n", texture->getName());
    } else {
        glBindTexture(GL_TEXTURE_2D, 0);
        tears_printf("unbind texture\n");
    }

    checkGLError();
}

// delete texture
void GLController::deleteTexture(GLuint* texture) const {
    glDeleteTextures(1, texture);
    tears_printf("delete texture: %d\n", *texture);
    *texture = 0;

    checkGLError();
}

// create framebuffer
void GLController::createFramebuffer(GLuint* outFramebuffer) const {
    glGenFramebuffers(1, outFramebuffer);
    tears_printf("create framebuffer: %d\n", *outFramebuffer);

    checkGLError();
}

// attach texture to the framebuffer
void GLController::attachTexture(const GLuint& texture) const {
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
    tears_printf("attach texture %d to bound framebuffer\n", texture);

    checkGLError();
}

// bind framebuffer
void GLController::bindFramebuffer(const Framebuffer* const framebuffer) const {
    if (framebuffer) {    /// if framebuffer is specified
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->getName());
        tears_printf("bind framebuffer: %d\n", framebuffer->getName());
    } else {
        glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)defaultFramebuffer);
        tears_printf("bind default framebuffer\n");
    }

    checkGLError();
}

// delete framebuffer
void GLController::deleteFramebuffer(GLuint* framebuffer) const {
    glDeleteFramebuffers(1, framebuffer);
    tears_printf("delete framebuffer: %d\n", *framebuffer);
    framebuffer = 0;

    checkGLError();
}

// preprocess for draw call
void GLController::preprocess() {
    setViewport();
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    checkGLError();
}

// finalize drawing for this event loop
void GLController::finalize() {
    ShaderController* sc = ShaderController::getInstance();
    CopyShader* shader = (CopyShader*)sc->createShader(ShaderCopy);

    glActiveTexture(GL_TEXTURE0);
    bindTexture(screenTexture.get());
    CallbackScope cbs([this]() {
        bindTexture(nullptr);
    });

    MatrixStackScope mss;
    mss.getTopMatrix()->setIdentity();

    CallbackScope cbs2([]() {
        glBlendFunc(BlendSrcAlpha, BlendOneMinusSrcAlpha);
    });
    glBlendFunc(BlendOne, BlendZero);

    Point vertices[4] = {
        Point(0.f, 0.f),
        Point(0.f, screenSize.height),
        Point(screenSize.width, 0.f),
        Point(screenSize.width, screenSize.height)};
    shader->drawCopy(vertices, 4);
}

// draw arrays with specified color
void GLController::drawArrays(PrimitiveType type, Point vertices[], Color colors[], int count) {
    uint32_t program = getCurrentProgram();
    uint32_t location = getAttributeLocation(program, "aColor");
    bindAttributeNu8v(location, (uint8_t*)colors, 4, true);

    drawArrays(type, vertices, count);
}

// draw arrays
void GLController::drawArrays(PrimitiveType type, Point vertices[], int count) {
    uint32_t program = getCurrentProgram();
    uint32_t location = getAttributeLocation(program, "aPosition");
    bindAttributeNfv(location, (float*)vertices, 2);

    MatrixStackScope mss;
    AffineTransform* affine = mss.getTopMatrix();
    affine->scale(Size(screenScale, screenScale));
    bindMatrices();

    glDrawArrays(type, 0, count);
}

}    // namespace tears
