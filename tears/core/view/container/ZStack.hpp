//
//  ZStack.hpp
//  tears
//
//  Created by Lfu001 on 2023/12/24.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef ZStack_hpp
#define ZStack_hpp

#include "Container.hpp"

namespace tears {

using namespace std;

/// A view that overlays its subviews, aligning them in both axes
class ZStack: public Container {
protected:
    /// default constructor
    ZStack() = delete;
    /// initializer
    void initialize();

public:
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    ZStack(Views&&... aChildren): Container(std::forward<Views>(aChildren)...) {
        initialize();
    }
    /// destructor
    virtual ~ZStack();
};

}    // namespace tears

#endif /* ZStack_hpp */
