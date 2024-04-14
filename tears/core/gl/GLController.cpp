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
#include "gl/Framebuffer.hpp"
#include "gl/MatrixStackScope.hpp"
#include "gl/Texture.hpp"
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

    checkGLError();

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

    checkGLError();

    program = linkProgram(program);
    return program;
}

// link program
GLuint GLController::linkProgram(GLuint program) {
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
void GLController::prepareProgram(
    const char* vertexShaderSource,
    const char* fragmentShaderSource) {
    if (!vertexShaderSource || !fragmentShaderSource) {
        tears_assert(false);
        return;
    }
    programObject = make_unique<GLuint>(compileProgram(vertexShaderSource, fragmentShaderSource));
    glUseProgram(*programObject);

    checkGLError();
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
    int w = (int)screenSize.width;
    int h = (int)screenSize.height;
    glViewport(0, 0, w, h);
    tears_printf("Viewport set to (%d, %d)\n", w, h);

    checkGLError();
}

// set attributes for default vertex shader
void GLController::setDefaultMatrixAttributes() const {
    unique_ptr<float[]> mvpMat = matrixStack.back().flatten();
    GLint mvpMatLocation = glGetUniformLocation(*programObject, "uMatrixMVP");
    tears_assert(mvpMatLocation >= 0);
    glUniformMatrix3fv(mvpMatLocation, 1, GL_FALSE, mvpMat.get());

    unique_ptr<float[]> uMat = viewportMatrix.flatten();
    GLint uMatLocation = glGetUniformLocation(*programObject, "uMatrixU");
    tears_assert(uMatLocation >= 0);
    glUniformMatrix3fv(uMatLocation, 1, GL_FALSE, uMat.get());
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

// specify a vector of points as the value of the attribute variable for the current program object
unique_ptr<float[]> GLController::bindAttributePoints(const char* name, Point points[], int count)
    const {
    /// flatten the array of Point
    auto v = make_unique<float[]>(count * 2);
    for (int i = 0; i < count; i++) {
        Point* t = &points[i];
        v[2 * i] = t->x;
        v[2 * i + 1] = t->y;
    }

    GLint posLocation = glGetAttribLocation(*programObject, name);
    tears_assert(posLocation >= 0);
    glVertexAttribPointer(posLocation, 2, GL_FLOAT, GL_FALSE, 0, v.get());
    checkGLError();
    glEnableVertexAttribArray(posLocation);
    checkGLError();
    return v;
}

// specify a vector of colors as the value of the attribute variable for the current program object
unique_ptr<float[]> GLController::bindAttributeColors(const char* name, Color colors[], int count)
    const {
    /// flatten the array of Color
    auto v = make_unique<float[]>(count * 4);
    for (int i = 0; i < count; i++) {
        Color* c = &colors[i];
        v[4 * i] = (float)c->red / 255.f;
        v[4 * i + 1] = (float)c->green / 255.f;
        v[4 * i + 2] = (float)c->blue / 255.f;
        v[4 * i + 3] = (float)c->alpha / 255.f;
    }

    GLint colLocation = glGetAttribLocation(*programObject, name);
    tears_assert(colLocation >= 0);
    glVertexAttribPointer(colLocation, 4, GL_FLOAT, GL_FALSE, 0, v.get());
    checkGLError();
    glEnableVertexAttribArray(colLocation);
    checkGLError();
    return v;
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

    checkGLError();
}

// specify a size as the value of the uniform variable for the current program object
void GLController::bindUniformSize(const char* name, Size size) const {
    GLint uniLocation = glGetUniformLocation(*programObject, name);
    /// program have to be compiled before adding uniform variable
    tears_assert(uniLocation >= 0);
    glUniform2f(uniLocation, size.width * screenScale, size.height * screenScale);

    checkGLError();
}

// specify a float value as the value of the uniform variable for the current program object
void GLController::bindUniformFloat(const char* name, float value) const {
    GLint uniLocation = glGetUniformLocation(*programObject, name);
    /// program have to be compiled before adding uniform variable
    tears_assert(uniLocation >= 0);
    glUniform1f(uniLocation, value);

    checkGLError();
}

// specify a int value as the value of the uniform variable for the current program object
void GLController::bindUniformInt(const char* name, int value) const {
    GLint uniLocation = glGetUniformLocation(*programObject, name);
    /// program have to be compiled before adding uniform variable
    tears_assert(uniLocation >= 0);
    glUniform1i(uniLocation, value);

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
    const char* vs = "attribute vec2 aTexCoord;"
                     "varying vec2 vTexCoord;"
                     "uniform mat3 uMatrixMVP;"
                     "uniform mat3 uMatrixU;"
                     "void main() {"
                     "    gl_Position = vec4(vec3(aTexCoord, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
                     "    vTexCoord = aTexCoord;"
                     "}";
    const char* fs = "precision highp float;"
                     "uniform sampler2D uTexture;"
                     "varying vec2 vTexCoord;"
                     "void main(void){"
                     "    gl_FragColor = texture2D(uTexture, vTexCoord);"
                     "}";
    prepareProgram(vs, fs);

    float texCoord[] = {0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0};
    GLint posLocation = glGetAttribLocation(*programObject, "aTexCoord");
    tears_assert(posLocation >= 0);
    glVertexAttribPointer(posLocation, 2, GL_FLOAT, GL_FALSE, 0, texCoord);
    glEnableVertexAttribArray(posLocation);

    glActiveTexture(GL_TEXTURE0);
    bindTexture(screenTexture.get());
    CallbackScope cbs([this]() {
        bindTexture(nullptr);
    });
    bindUniformInt("uTexture", 0);

    MatrixStackScope mss;
    mss.getTopMatrix()->setIdentity();
    AffineTransform vMatBackup = viewportMatrix;
    CallbackScope cbs2([this, vMatBackup]() {
        viewportMatrix = vMatBackup;
    });
    viewportMatrix = AffineTransform();
    viewportMatrix.scale(Size(2.f, 2.f));
    viewportMatrix.translate(Size(-1.f, -1.f));
    setDefaultMatrixAttributes();

    CallbackScope cbs3([]() {
        glBlendFunc(BlendSrcAlpha, BlendOneMinusSrcAlpha);
    });
    glBlendFunc(BlendOne, BlendZero);

    glDrawArrays(PrimitiveTriangleStrip, 0, 4);
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

    unique_ptr<float[]> v = bindAttributePoints("aPosition", vertices, count);

    MatrixStackScope mss;
    AffineTransform* affine = mss.getTopMatrix();
    affine->scale(Size(screenScale, screenScale));
    setDefaultMatrixAttributes();

    glDrawArrays(type, 0, count);
}

}    // namespace tears
