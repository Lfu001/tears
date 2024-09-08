//
//  EllipseShader.hpp
//  tears
//
//  Created by Lfu001 on 2024/05/01.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef EllipseShader_hpp
#define EllipseShader_hpp

#include "gl/shader/Shader.hpp"

namespace tears {
using namespace std;

/// a shader to draw ellipse shape
/// @ingroup shader
class EllipseShader: public Shader {
protected:
    /// load shader
    virtual void loadShader() override;

public:
    /// default constructor
    EllipseShader();
    /// destructor
    virtual ~EllipseShader();

public:
    /// draw ellipse
    /// @param center a center of the ellipse
    /// @param semiAxisX a semi axis in x-direction of the ellipse
    /// @param semiAxisY a semi axis in y-direction of the ellipse
    /// @param textureSrc a texture to draw inside the shape. if nullptr, transparent texture will
    /// be drawn.
    /// @param texCoordSrc an array of texture coordinates
    /// @param vertices an array of vertices
    /// @param colors an array of colors
    /// @param count a length of the array
    void drawEllipse(
        Point center,
        float semiAxisX,
        float semiAxisY,
        Texture* textureSrc,
        const Point texCoordSrc[],
        Point vertices[],
        Color colors[],
        int count) const;
};

}    // namespace tears

#endif /* EllipseShader_hpp */
