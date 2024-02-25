//
//  Ellipse.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Ellipse_hpp
#define Ellipse_hpp

#include "view/shape/Shape.hpp"

namespace tears {

/// a ellipse shape
/// @ingroup shape 
class Ellipse: public Shape {
public:
    /// default constructor
    Ellipse();
    /// destructor
    virtual ~Ellipse();

public:
    /// main drawing process
    virtual void drawMain() override;
};

}    // namespace tears

#endif /* Ellipse_hpp */
