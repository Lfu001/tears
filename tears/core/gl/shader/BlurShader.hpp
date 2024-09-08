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

class Interval;

/// a shader to blur texture
///
/// reference: https://drafts.fxtf.org/filter-effects/#feGaussianBlurElement
///
/// @ingroup shader
class BlurShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;
    /// calculate kernel size [px]
    /// @param sigma a standard deviation
    /// @return a kernel size rounded to the nearest integer
    int calculateKernelSize(float sigma) const;
    /// 1D box blur
    /// @param isVertical a flag to indicate the direction of the box blur
    /// @param kernelInterval a kernel interval [px]. The current pixel coordinate corresponds to 0.
    /// @param overwriteDst a flag to force overwrite the destination texture
    /// @param textureSrc a source texture
    /// @param texCoordSrc an array of texture coordinates
    /// @param textureDst a destination texture
    /// @param vertices an array of vertices
    /// @param count the number of elements in the vertices
    void boxBlur1D(
        bool isVertical,
        Interval kernelInterval,
        bool overwriteDst,
        Texture* textureSrc,
        const Point texCoordSrc[],
        Texture* textureDst,
        const Point vertices[],
        int count);

public:
    /// default constructor
    BlurShader();
    /// destructor
    virtual ~BlurShader();

public:
    /// draw blurred texture.
    /// @param sigma the standard deviation of the gaussian fuction
    /// @param textureSrc a texture to blur
    /// @param texCoordSrc an array of texture coordinates of the source texture
    /// @param bboxSizeSrc a size [px] of the bbox to be blurred
    /// @param textureDst a destination texture where the blurred result is drawn
    /// @param vertices an array of vertices
    /// @param count the number of elements in vertices
    void drawBlur(
        float sigma,
        Texture* textureSrc,
        const Point texCoordSrc[],
        Size bboxSizeSrc,
        Texture* textureDst,
        const Point vertices[],
        int count);
};

}    // namespace tears

#endif /* BlurShader_hpp */
