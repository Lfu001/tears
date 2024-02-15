//
//  Transformable.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/15.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Transformable_h
#define Transformable_h

namespace tears {

class AffineTransform;

/// a type that can be transformed by affine matrix
template<typename T>
class Transformable {
public:
    /// apply transforms
    virtual T applyTransform(AffineTransform affine) = 0;
};

}    // namespace tears

#endif /* Transformable_h */
