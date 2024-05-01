//
//  Shader.cpp
//  tears
//
//  Created by Lfu001 on 2024/04/28.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <functional>
#include "gl/GLController.hpp"
#include "gl/MatrixStackScope.hpp"
#include "Shader.hpp"

namespace tears {
using namespace std;

// default constructor
Shader::Shader() {}

// destructor
Shader::~Shader() {
    try {
        deleteProgram();
    } catch (...) {}
}

// build program object
void Shader::buildProgram(const string& vertexShaderSource, const string& fragmentShaderSource) {
    uint32_t newVHash = (uint32_t)hasher(vertexShaderSource);
    uint32_t newFHash = (uint32_t)hasher(fragmentShaderSource);
    if (newVHash == vertexHash && newFHash == fragmentHash) {    /// if shader source is not changed
        return;
    }
    if (programObject > 0) {    /// if previous created program object is no more needed
        deleteProgram();
    }
    vertexHash = newVHash;
    fragmentHash = newFHash;
    GLController* gl = GLController::getInstance();
    programObject = gl->prepareProgram(vertexShaderSource.c_str(), fragmentShaderSource.c_str());
}

// delete program
void Shader::deleteProgram() {
    GLController* gl = GLController::getInstance();
    gl->deleteProgram(programObject);
    programObject = 0;
}

// get uniform variable location
int32_t Shader::getUniformLocation(const char* name) const {
    GLController* gl = GLController::getInstance();
    return gl->getUniformLocation(programObject, name);
}

// get attribute variable location
int32_t Shader::getAttributeLocation(const char* name) const {
    GLController* gl = GLController::getInstance();
    return gl->getAttributeLocation(programObject, name);
}

// bind an array of points to the attribute variable for the current program object
void Shader::bindAttributePoints(const char* name, const Point points[]) const {
    GLController* gl = GLController::getInstance();
    int32_t location = gl->getAttributeLocation(programObject, name);
    gl->bindAttributeNfv(location, (float*)points, 2);
}

// bind an array of colors to the attribute variable for the current program object
void Shader::bindAttributeColors(const char* name, const Color colors[]) const {
    GLController* gl = GLController::getInstance();
    int32_t location = gl->getAttributeLocation(programObject, name);
    gl->bindAttributeNu8v(location, (uint8_t*)colors, 4, true);
}

// bind a point to the uniform variable for the current program object
void Shader::bindUniformPoint(const char* name, Point point) const {
    GLController* gl = GLController::getInstance();

    MatrixStackScope mss;
    AffineTransform* affine = mss.getTopMatrix();
    float screenScale = gl->getScreenScale();
    affine->scale(Size(screenScale, screenScale));
    Point t = point.applyTransform(*affine);

    int32_t location = gl->getUniformLocation(programObject, name);
    int screenHeight = (int)roundf(gl->getScreenSize().height * screenScale);
    gl->bindUniform2f(location, t.x, screenHeight - t.y);
}

// bind a size to the uniform variable for the current program object
void Shader::bindUniformSize(const char* name, Size size) const {
    GLController* gl = GLController::getInstance();
    int32_t location = gl->getUniformLocation(programObject, name);
    float screenScale = gl->getScreenScale();
    gl->bindUniform2f(location, size.width * screenScale, size.height * screenScale);
}

// bind a texture unit to the uniform variable for the current program object
void Shader::bindUniformTexture(const char* name, int unit) const {
    GLController* gl = GLController::getInstance();
    int32_t location = gl->getUniformLocation(programObject, name);
    gl->bindUniform1i(location, unit);
}

// bind a value to the uniform variable for the current program object
void Shader::bindUniformValue(const char* name, float value) const {
    GLController* gl = GLController::getInstance();
    int32_t location = gl->getUniformLocation(programObject, name);
    gl->bindUniform1f(location, value);
}

// bind a matrices to the uniform variables for the current program object
void Shader::bindMatrices() const {
    GLController* gl = GLController::getInstance();
    gl->bindMatrices();
}

}    // namespace tears
