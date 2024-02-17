//
//  Circle.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include "view/shape/Shape.hpp"

namespace tears {

/// a circle shape
class Circle: public Shape {
public:
    /// default constructor
    Circle();
    /// destructor
    virtual ~Circle();

public:
    /// main drawing process. call GLController::drawArrays() from this method.
    virtual void drawMain() override;
};

}    // namespace tears

#endif /* Circle_hpp */
