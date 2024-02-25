//
//  Capsule.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/23.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Capsule_hpp
#define Capsule_hpp

#include "view/shape/RoundedRectangle.hpp"

namespace tears {

/// a capsule shape
/// @ingroup shape
class Capsule: public RoundedRectangle {
public:
    /// default constructor
    Capsule();
    /// destructor
    virtual ~Capsule();

public:
    /// main drawing process
    virtual void drawMain() override;
};

}    // namespace tears

#endif /* Capsule_hpp */
