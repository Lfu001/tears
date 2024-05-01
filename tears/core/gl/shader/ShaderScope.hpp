//
//  ShaderScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef ShaderScope_hpp
#define ShaderScope_hpp

namespace tears {

class Shader;

/// a class that set current shader program
/// @ingroup shader
class ShaderScope {
public:
    /// constructor
    ShaderScope(const Shader* shader);
    /// destructor
    virtual ~ShaderScope();
};

}    // namespace tears

#endif /* ShaderScope_hpp */
