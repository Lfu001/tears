//
//  Shape.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include "gl/Color.hpp"
#include "view/base/View.hpp"

namespace tears {

/// a base class of all shapes
/// @ingroup shape
class Shape: public View {
protected:
    /// a fill color
    Color fillColor = Color::ORANGE;

public:
    /// default constructor
    Shape();
    /// destructor
    virtual ~Shape();

public:
    /// fill the shape with specified color
    Shape& fill(Color color);
};

}    // namespace tears

#endif /* Shape_hpp */
