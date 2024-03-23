//
//  Texture.hpp
//  tears
//
//  Created by Lfu001 on 2024/03/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include "math/Size.hpp"

namespace tears {

/// a wrapper class of a GL texture
/// @ingroup gl
class Texture {
protected:
    /// texture name
    unsigned int name = 0;
    /// texture size [px]
    Size size;

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
};

}    // namespace tears

#endif /* Texture_hpp */
