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

class Container: public View {
protected:
    /// default container
    Container() = delete;

public:
    /// constructor (with child views)
    /// by default, children will be ordered vertically
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    Container(Views&&... aChildren): View(forward<Views>(aChildren)...) {}
    /// destructor
    virtual ~Container();
};

}    // namespace tears

#endif /* Container_hpp */
