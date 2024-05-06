//
//  Framebuffer.hpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Framebuffer_hpp
#define Framebuffer_hpp

namespace tears {

class Texture;

/// a wrapper class of a GL frame buffer. consider using it via `FramebufferScope` class.
/// @ingroup gl
class Framebuffer {
protected:
    /// framebuffer name
    unsigned int name = 0;

protected:
    /// initializer
    void initialize();

public:
    /// default constructor
    Framebuffer();
    /// constructor (from texture)
    /// @param aTexture a texture to be attached to the frame buffer
    Framebuffer(const Texture* aTexture);
    /// destructor
    virtual ~Framebuffer();

public:
    /// attach texture
    void attachTexture(const Texture* texture) const;
    /// bind framebuffer
    void bind() const;
    /// unbind framebuffer. equivalent to binding default framebuffer.
    void unbind() const;
    /// get framebuffer name
    unsigned int getName() const { return name; }
};

}    // namespace tears

#endif /* Framebuffer_hpp */
