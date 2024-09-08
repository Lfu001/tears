//
//  ShaderScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef ShaderScope_hpp
#define ShaderScope_hpp

#include "gl/MatrixStackScope.hpp"

namespace tears {

class Shader;

/// a class that set current shader program
/// @ingroup shader
class ShaderScope {
protected:
    /// matrix stack scope to set screen scale
    MatrixStackScope matrixStackScope;

public:
    /// constructor
    ShaderScope(const Shader* shader);
    /// destructor
    virtual ~ShaderScope();
};

}    // namespace tears

#endif /* ShaderScope_hpp */
