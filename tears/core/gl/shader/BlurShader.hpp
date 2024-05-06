//
//  BlurShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/05/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef BlurShader_hpp
#define BlurShader_hpp

#include "gl/shader/Shader.hpp"

namespace tears {

/// a shader to blur texture
/// @ingroup shader
class BlurShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;
    /// calculate kernel weights of the gaussian blur
    /// @param strength the strength of the blur
    vector<float> calculateKernelWeights(int strength) const;

public:
    /// default constructor
    BlurShader();
    /// destructor
    virtual ~BlurShader();

public:
    /// draw blurred texture
    /// @param strength the strength of the blur
    /// @param textureSrc a texture to blur
    /// @param texCoordSrc an array of texture coordinates of the source texture
    /// @param bboxSizeSrc a size [px] of the bbox to be blurred
    /// @param vertices an array of vertices
    /// @param count the number of elements in the array
    void drawBlur(
        int strength,
        Texture* textureSrc,
        const Point texCoordSrc[],
        Size bboxSizeSrc,
        const Point vertices[],
        int count) const;
};

}    // namespace tears

#endif /* BlurShader_hpp */
