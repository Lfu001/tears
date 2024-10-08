//
//  VStack.hpp
//  tears
//
//  Created by Lfu001 on 2023/12/17.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef VStack_hpp
#define VStack_hpp

#include "Container.hpp"

namespace tears {

using namespace std;

/// A view that arranges its subviews in a vertical line
/// @ingroup container 
class VStack: public Container {
protected:
    /// default constructor
    VStack() = delete;
    /// initializer
    void initialize();

public:
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    VStack(Views&&... aChildren): Container(std::forward<Views>(aChildren)...) {
        initialize();
    }
    /// destructor
    virtual ~VStack();
};

}    // namespace tears

#endif /* VStack_hpp */
