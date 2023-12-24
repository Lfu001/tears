//
//  HStack.hpp
//  tears
//
//  Created by Lfu001 on 2023/12/17.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef HStack_hpp
#define HStack_hpp

#include "Container.hpp"

namespace tears {

/// A view that arranges its subviews in a horizontal line
class HStack: public Container {
protected:
    /// default constructor
    HStack() = delete;
    /// initializer
    void initialize();

public:
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    HStack(Views&&... aChildren): Container(forward<Views>(aChildren)...) {
        initialize();
    }
    /// destructor
    virtual ~HStack();
};

}    // namespace tears

#endif /* HStack_hpp */
