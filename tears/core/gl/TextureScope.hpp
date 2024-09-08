//
//  TextureScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/05/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef TextureScope_hpp
#define TextureScope_hpp

#include <cstdint>

namespace tears {

/// texture parameter names
/// @ingroup gl
enum TextureParameterNameType : uint32_t {
    /// min filter
    TextureParameterNameMinFilter,
    /// mag filter
    TextureParameterNameMagFilter,
    /// wrap S
    TextureParameterNameWrapS,
    /// wrap T
    TextureParameterNameWrapT,
};

/// texture parameters
/// @ingroup gl
enum TextureParameterType : int32_t {
    /// [min/ mag filter]nearest neighbor
    TextureParameterNearest,
    /// [min/mag filter] bilinear interpolation
    TextureParameterLinear,
    /// [wrapS/wrapT] clamp to edge
    TextureParameterClampToEdge,
    /// [wrapS/wrapT] repeat
    TextureParameterRepeat,
    /// [wrapS/wrapT] mirrored repeat
    TextureParameterMirroredRepeat,
};

class Texture;

/// a class that bind and set texture parameters
/// @ingroup gl
class TextureScope {
protected:
    /// current texture unit
    static int currentTextureUnit;
    /// a texture to be controlled
    Texture* targetTexture = nullptr;
    /// a backup of min filter
    TextureParameterType backupMinFilter;
    /// a backup of mag filter
    TextureParameterType backupMagFilter;
    /// a backup of wrap S
    TextureParameterType backupWrapS;
    /// a backup of wrap T
    TextureParameterType backupWrapT;

protected:
    /// default constructor
    TextureScope() = delete;
    /// copy constructor
    TextureScope(const TextureScope&) = delete;
    /// move constructor
    TextureScope(TextureScope&&) = delete;
    /// copy assignment operator
    TextureScope& operator=(const TextureScope&) = delete;
    /// move assignment operator
    TextureScope& operator=(TextureScope&&) = delete;

public:
    /// constructor (min, mag, wrapS, wrapT)
    TextureScope(
        Texture* texture,
        TextureParameterType minFilter,
        TextureParameterType magFilter,
        TextureParameterType wrapS,
        TextureParameterType wrapT);
    /// constructor (min-mag, wrapS-wrapT)
    TextureScope(Texture* texture, TextureParameterType minMagFilter, TextureParameterType wrapST);
    /// destructor
    virtual ~TextureScope();

public:
    /// get current texture unit
    int getCurrentTextureUnit() { return currentTextureUnit; }
};

}    // namespace tears

#endif /* TextureScope_hpp */
