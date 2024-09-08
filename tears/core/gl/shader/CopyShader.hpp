//
//  CopyShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef CopyShader_hpp
#define CopyShader_hpp

#include "gl/shader/Shader.hpp"

namespace tears {

/// a shader to copy bound texture
/// @ingroup shader
class CopyShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;

public:
    /// default constructor
    CopyShader();
    /// destructor
    virtual ~CopyShader();

public:
    /// draw copy
    /// @param texSrc a texture to copy from
    /// @param texCoord an array of texture coordinates
    /// @param vertices an array of vertices
    /// @param count a length of the array
    void drawCopy(Texture* texSrc, const Point texCoord[], Point vertices[], int count) const;
};

}    // namespace tears

#endif /* CopyShader_hpp */
