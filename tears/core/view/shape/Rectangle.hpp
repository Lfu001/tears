//
//  Rectangle.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/24.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "view/shape/Shape.hpp"

namespace tears {

/// a rectangle shape
class Rectangle: public Shape {
public:
    /// default constructor
    Rectangle();
    /// destructor
    virtual ~Rectangle();

public:
    /// main drawing process. call GLController::drawArrays() from this method.
    virtual void drawMain() override;
};

}    // namespace tears

#endif /* Rectangle_hpp */
