//
//  Container.hpp
//  tears
//
//  Created by Lfu001 on 2023/12/17.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include "view/base/View.hpp"

namespace tears {

using namespace std;

/// A view interface that arranges its subviews in a line
class Container: public View {
protected:
    /// default container
    Container() = delete;

public:
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    Container(Views&&... aChildren): View(std::forward<Views>(aChildren)...) {}
    /// destructor
    virtual ~Container();
};

}    // namespace tears

#endif /* Container_hpp */
