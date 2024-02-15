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

/// An object that defines the properties associated with a hardware-based display
class Scene {
protected:
    /// scene size
    Size size;
    /// child views
    vector<unique_ptr<View>> children;
    /// app engine (no ownership)
    TearsEngine* engine;

protected:
    /// default constructor
    Scene() = delete;

protected:
    /// add child view
    template<typename T>
    void addChild(T&& child) {
        static_assert(is_unique_ptr_v<std::decay_t<T>>, "Child type must be a std::unique_ptr");
        static_assert(
            std::is_base_of<View, typename std::remove_reference_t<T>::element_type>::value,
            "Child type must be a std::unique_ptr to View or its descendant");

        children.emplace_back(std::forward<T>(child));
    }

public:
    /// constructor
    Scene(TearsEngine* aEngine);
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    Scene(Views&&... aChildren) {
        (addChild(std::forward<Views>(aChildren)), ...);
    }
    /// destructor
    virtual ~Scene();

public:
    /// render the scene
    virtual void render();
    /// get scene size
    Size getSize() const { return size; }
    /// set scene size
    void setSize(float x, float y) { size = Size(x, y); }
    /// set scene size by Vector2D
    void setSize(Size aSize) { size = aSize; }
};

}    // namespace tears

#endif /* Scene_hpp */
