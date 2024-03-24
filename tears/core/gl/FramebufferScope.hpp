//
//  FramebufferScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef FramebufferScope_hpp
#define FramebufferScope_hpp

#include <memory>

namespace tears {

using namespace std;

class Framebuffer;
class Texture;

/// a scope class that create, bind, delete framebuffer
/// @ingroup gl
class FramebufferScope {
protected:
    /// current framebuffer
    unique_ptr<Framebuffer> framebuffer;

public:
    /// constructor (from texture)
    /// @param texture a texture to be attached to the framebuffer
    FramebufferScope(const Texture& texture);
    /// destructor
    virtual ~FramebufferScope();
};

}    // namespace tears

#endif /* FramebufferScope_hpp */
