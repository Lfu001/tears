//
//  Texture.hpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include "gl/TextureScope.hpp"
#include "math/Size.hpp"

namespace tears {

class Point;

/// a wrapper class of a GL texture
/// @ingroup gl
class Texture {
    friend TextureScope;

public:
    /// default texture coordinates
    static const Point DEFAULT_TEXTURE_COORD[4];

protected:
    /// texture name
    unsigned int name = 0;
    /// texture size [px]
    Size size;
    /// min filter parameter
    TextureParameterType minFilter = TextureParameterLinear;
    /// mag filter parameter
    TextureParameterType magFilter = TextureParameterLinear;
    /// wrap S parameter
    TextureParameterType wrapS = TextureParameterClampToEdge;
    /// wrap T parameter
    TextureParameterType wrapT = TextureParameterClampToEdge;

protected:
    /// set texture parameter
    void setTextureParameter(TextureParameterNameType name, TextureParameterType param);

public:
    /// constructor (from size)
    /// @param width a width of the texture [px]
    /// @param height a height of the texture [px]
    Texture(int width, int height);
    /// destructor
    virtual ~Texture();

public:
    /// get texture name
    unsigned int getName() const { return name; }
    /// get texture size
    Size getSize() const { return size; }
    /// get texture width
    float getWidth() const { return size.width; }
    /// get texture height
    float getHeight() const { return size.height; }
    /// get texture parameter
    TextureParameterType getTextureParameter(TextureParameterNameType name) const;
};

}    // namespace tears

#endif /* Texture_hpp */
