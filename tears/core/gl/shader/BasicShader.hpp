//
//  BasicShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/28.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef BasicShader_hpp
#define BasicShader_hpp

#include "gl/shader/Shader.hpp"

namespace tears {

/// a basic shader for drawing view
/// @ingroup shader
class BasicShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;

public:
    /// default constructor
    BasicShader();
    /// destructor
    virtual ~BasicShader();
};

}    // namespace tears

#endif /* BasicShader_hpp */
