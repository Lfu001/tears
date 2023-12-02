//
//  View.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/19.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <vector>

#include "base/Modifier.hpp"
#include "base/ViewFlag.hpp"
#include "math/Vector2D.hpp"
#include "utils/DebugUtil.hpp"

namespace tears {

using namespace std;

/// represents part of the user interface and provide modifier to configure views
class View: public Modifier, public ViewFlag {
private:
    /// assignable view ID
    static int64_t nextViewId;
    /// view ID
    int64_t id;

private:
    /// assign view ID
    void assignViewId();
    /// add child view
    template<typename T>
    void addChild(T&& child) {
        static_assert(is_unique_ptr_v<std::decay_t<T>>, "Child type must be a std::unique_ptr");
        static_assert(
            std::is_base_of<View, typename std::remove_reference_t<T>::element_type>::value,
            "Child type must be a std::unique_ptr to View or its descendant");

        children.emplace_back(std::forward<T>(child));
    }

protected:
    /// view position
    Vector2D position;
    /// view size
    Vector2D size;
    /// children views
    vector<unique_ptr<View>> children;

public:
    /// default constructor
    View();
    /// constructor (with child views)
    /// by default, children will be ordered vertically
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    View(Views&&... aChildren) {
        assignViewId();
        (addChild(std::forward<Views>(aChildren)), ...);
    }
    /// destructor
    virtual ~View();

public:
    /// get view id
    int64_t getViewId() const { return id; }
    /// get view postion
    Vector2D getPosition() const { return position; }
    /// get view position x
    float getX() const { return position.getX(); }
    /// get view position y
    float getY() const { return position.getY(); }
    /// get view size
    Vector2D getSize() const { return size; }
    /// get view width
    float getWidth() const { return size.getWidth(); }
    /// get view height
    float getHeight() const { return size.getHeight(); }
};

}    // namespace tears

#endif /* View_hpp */
