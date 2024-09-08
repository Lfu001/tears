//
//  Size.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/15.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Size_hpp
#define Size_hpp

namespace tears {

class AffineTransform;

/// A structure that contains width and height values
/// @ingroup math
struct Size {
public:
    /// a width
    float width = 0.f;
    /// a height
    float height = 0.f;

public:
    /// default constructor
    Size();
    /// constructor from width and height
    Size(float aWidth, float aHeight);
    /// destructor
    ~Size();

public:
    /// apply transforms
    Size applyTransform(AffineTransform affine);
};

static_assert(sizeof(Size) == sizeof(float) * 2);
}    // namespace tears

#endif /* Size_hpp */
