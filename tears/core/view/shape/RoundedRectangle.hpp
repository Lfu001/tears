//
//  RoundedRectangle.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef RoundedRectangle_hpp
#define RoundedRectangle_hpp

#include "view/shape/Shape.hpp"

namespace tears {

/// a rectangular shape with rounded corners
/// @ingroup shape 
class RoundedRectangle: public Shape {
protected:
    /// corner radius (default: 24)
    float cornerRadius = 24.f;

public:
    /// default constructor
    RoundedRectangle();
    /// constructor from corner radius
    /// @param radius a corner radius
    RoundedRectangle(float radius);
    /// destructor
    virtual ~RoundedRectangle();

public:
    /// main drawing process
    virtual void drawMain() override;
    /// set corner radius
    void setCornerRadius(float radius) { cornerRadius = radius; }
};

}    // namespace tears

#endif /* RoundedRectangle_hpp */
