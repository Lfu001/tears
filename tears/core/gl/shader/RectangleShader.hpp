//
//  RectangleShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/07/14.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef RectangleShader_hpp
#define RectangleShader_hpp

#include "gl/shader/Shader.hpp"

class Texture;

namespace tears {

/// a shader to draw rectangle shape
/// @ingroup shader
class RectangleShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;

public:
    /// default constructor
    RectangleShader();
    /// destructor
    virtual ~RectangleShader();

    /// draw rectangle
    /// @param textureSrc a texture to draw inside the shape. if nullptr, transparent texture will
    /// be drawn
    /// @param texCoordSrc an array of texture coordinates
    /// @param vertices an array of vertices
    /// @param colors an array of colors
    /// @param count a length of the array
    void drawRectangle(
        Texture* textureSrc,
        const Point texCoordSrc[],
        Point vertices[],
        Color colors[],
        int count) const;
};

}    // namespace tears

#endif /* RectangleShader_hpp */
