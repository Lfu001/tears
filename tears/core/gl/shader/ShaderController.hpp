//
//  ShaderController.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/28.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef ShaderController_hpp
#define ShaderController_hpp

#include <unordered_map>
#include <vector>

namespace tears {
using namespace std;

/// all shaders
/// @ingroup shader
enum ShaderObjectType : int32_t {
    /// basic shader
    ShaderBasic,
    /// copy shader
    ShaderCopy,
    /// circle shader
    ShaderCircle,
    /// ellipse shader
    ShaderEllipse,
    /// rectangle shader
    ShaderRectangle,
    /// rounded rectangle shader
    ShaderRoundedRectangle,
    /// blur shader
    ShaderBlur,
};

class GLController;
class Shader;
class ShaderScope;

/// a singleton class that manages shaders
/// @ingroup shader
class ShaderController {
    friend GLController;
    friend ShaderScope;
    friend unique_ptr<ShaderController>::deleter_type;

protected:
    /// singleton instance
    static unique_ptr<ShaderController> controller;
    /// a created shaders
    unordered_map<ShaderObjectType, unique_ptr<Shader>> shaderMap;
    /// shader stack
    vector<const Shader*> shaderStack;

protected:
    /// default constructor
    ShaderController();
    /// destructor
    virtual ~ShaderController();
    /// copy constructor
    ShaderController(const ShaderController&) = delete;
    /// move constructor
    ShaderController(ShaderController&&) = delete;
    /// copy assignment operator
    ShaderController& operator=(const ShaderController&) = delete;
    /// move assignment operator
    ShaderController& operator=(ShaderController&&) = delete;

protected:
    /// get current shader
    const Shader* getCurrentShader() const;
    /// push shader to stack
    void pushShader(const Shader* shader);
    /// pop shader from stack
    void popShader();
    /// use shader
    void useShader(const Shader* shader) const;

public:
    /// get singleton instance
    static ShaderController* getInstance();
    /// create shader
    Shader* createShader(ShaderObjectType shaderObjectType);
};

}    // namespace tears

#endif /* ShaderController_hpp */
