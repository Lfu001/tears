//
//  RoundedRectangleShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/05/01.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef RoundedRectangleShader_hpp
#define RoundedRectangleShader_hpp

#include "gl/shader/Shader.hpp"

namespace tears {

/// a shader to draw rounded rectangle shape
/// @ingroup shader
class RoundedRectangleShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;

public:
    /// default constructor
    RoundedRectangleShader();
    /// destructor
    virtual ~RoundedRectangleShader();

public:
    /// draw rounded rectangle
    /// @param center a center of the rounded rectangle
    /// @param cornerRadius a radius of the corner
    /// @param halfSize a half size of the rectangle
    /// @param textureSrc a texture to draw inside the shape. if nullptr, transparent texture will
    /// be drawn.
    /// @param texCoordSrc an array of texture coordinates
    /// @param vertices an array of vertices
    /// @param colors an array of colors
    /// @param count a length of the array
    void drawRoundedRectangle(
        Point center,
        float cornerRadius,
        Size halfSize,
        Texture* textureSrc,
        const Point texCoordSrc[],
        Point vertices[],
        Color colors[],
        int count) const;
};

}    // namespace tears

#endif /* RoundedRectangleShader_hpp */
