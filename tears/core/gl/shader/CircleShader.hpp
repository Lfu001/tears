//
//  CircleShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef CircleShader_hpp
#define CircleShader_hpp

#include "gl/shader/Shader.hpp"

namespace tears {

/// a shader to draw circle shape
/// @ingroup shader
class CircleShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;

public:
    /// default constructor
    CircleShader();
    /// destructor
    virtual ~CircleShader();

public:
    /// draw circle
    /// @param center a center of the circle
    /// @param radius a radius of the circle
    /// @param vertices an array of vertices
    /// @param textureSrc a texture to draw inside the shape. if nullptr, transparent texture will
    /// be drawn.
    /// @param texCoordSrc an array of texture coordinates
    /// @param colors an array of colors
    /// @param count a length of the array
    void drawCircle(
        Point center,
        float radius,
        const Point vertices[],
        Texture* textureSrc,
        const Point texCoordSrc[],
        const Color colors[],
        int count) const;
};

}    // namespace tears

#endif /* CircleShader_hpp */
