//
//  Scene.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/03.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <vector>
#include "math/Point.hpp"
#include "math/Size.hpp"
#include "view/base/View.hpp"

namespace tears {

using namespace std;

class TearsEngine;

/// a root class of the View tree
class Scene: public View {
protected:
    /// app engine (no ownership)
    TearsEngine* engine;

protected:
    /// default constructor
    Scene() = delete;

public:
    /// constructor
    Scene(TearsEngine* aEngine, Size screenSize);
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    Scene(Views&&... aChildren): View(aChildren...) {}
    /// destructor
    virtual ~Scene();

public:
    /// render the scene
    virtual void render();
    /// get scene size
    Size getSize() const { return size; }
    /// set scene size
    void setSize(float x, float y);
    /// set scene size by Vector2D
    void setSize(Size aSize);
};

}    // namespace tears

#endif /* Scene_hpp */
