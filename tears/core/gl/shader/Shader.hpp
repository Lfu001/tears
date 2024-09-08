//
//  Shader.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/28.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

namespace tears {
using namespace std;

class Color;
class GLController;
class Point;
class Shader;
class ShaderController;
class ShaderScope;
class Size;

/// a base class that wraps OpenGL shaders
/// @ingroup shader
class Shader {
    friend GLController;
    friend ShaderController;
    friend ShaderScope;
    friend unique_ptr<Shader>::deleter_type;

protected:
    /// OpenGL program object
    uint32_t programObject = 0;
    /// string hasher
    hash<string> hasher = hash<string>();
    /// vertex shader source hash
    uint32_t vertexHash = 0;
    /// fragment shader source hash
    uint32_t fragmentHash = 0;

protected:
    /// default constructor
    Shader();
    /// destructor
    virtual ~Shader();

protected:
    /// load shader
    virtual void loadShader() = 0;
    /// build program object
    /// @param vertexShaderSource a source code of vertex shader
    /// @param fragmentShaderSource a source code of fragment shader
    void buildProgram(const string& vertexShaderSource, const string& fragmentShaderSource);
    /// delete program
    void deleteProgram();
    /// get uniform variable location
    int32_t getUniformLocation(const char* name) const;
    /// get attribute variable location
    int32_t getAttributeLocation(const char* name) const;
    /// get program object
    uint32_t getProgramObject() const { return programObject; }
    /// bind an array of points to the attribute variable for the current program object
    /// @param name a name of the attribute variable
    /// @param points an array of vertices
    void bindAttributePoints(const char* name, const Point points[]) const;
    /// bind an array of colors to the attribute variable for the current program object
    /// @param name a name of the attribute variable
    /// @param colors an array of colors corresponding to vertices
    void bindAttributeColors(const char* name, const Color colors[]) const;
    /// bind a point to the uniform variable for the current program object.
    /// @note the point will be converted to the screen coordinates internally.
    /// @param name a name of the uniform variable
    /// @param point a point to pass to the uniform variable
    void bindUniformPoint(const char* name, Point point) const;
    /// bind a size to the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param size a size to pass to the uniform variable
    /// @param scale whether to scale the given size by screen scale
    void bindUniformSize(const char* name, Size size, bool scale = true) const;
    /// bind a texture unit to the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param unit a texture unit to pass to the uniform variable
    void bindUniformTexture(const char* name, int unit) const;
    /// bind an integer value to the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param value a value to pass to the uniform variable
    void bindUniformInteger(const char* name, int value) const;
    /// bind a float value to the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param value a value to pass to the uniform variable
    void bindUniformFloat(const char* name, float value) const;
    /// bind a float array to the uniform variable for the current program object
    /// @param name a name of the uniform variable
    /// @param count a length of the array
    /// @param array a value to pass to the uniform variable
    void bindUniformFloatArray(const char* name, int count, const float* array) const;
    /// bind a matrices to the uniform variables for the current program object
    void bindMatrices() const;
};

}    // namespace tears

#endif /* Shader_hpp */
