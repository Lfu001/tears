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

#include "math/Vector2D.hpp"
#include "utils/DebugUtil.hpp"
#include "view/base/LayoutDirectionType.hpp"
#include "view/base/Modifier.hpp"
#include "view/base/ViewFlag.hpp"

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

    /// compute and set a position of child views
    void computeChildPosition();
    /// compute and set a size of child views
    void computeChildSize();
    /// compute and set a size of child views if specified
    /// @param outWidthFlags an output flags for each child that represents whether width is already
    /// computed
    /// @param outHeightFlags an output flags for each child that represents whether height is
    /// already computed
    /// @param outLayoutSpace an output size represents available layout space remained
    void computeChildSizeIfSpecified(
        vector<bool>& outWidthFlags,
        vector<bool>& outHeightFlags,
        Vector2D& outLayoutSpace);
    /// respond the width computed from width range and the proposed width by parent
    /// @param proposedWidth a width proposed by parent
    /// @return a proposed width clamped between minimum width and maximum width
    float computeWidth(float proposedWidth);
    /// respond the height computed from height range and the proposed height by parent
    /// @param proposedHeight a height proposed by parent
    /// @return a proposed height clamped between minimum height and maximum height
    float computeHeight(float proposedHeight);

    /// set view position
    void setPosition(float aX, float aY);
    /// set view position x
    void setX(float aX);
    /// set view position y
    void setY(float aY);
    /// set view size
    void setSize(float aWidth, float aHeight);
    /// set view width
    void setWidth(float aWidth);
    /// set view height
    void setHeight(float aHeight);

protected:
    /// view position
    Vector2D position;
    /// view size
    Vector2D size;
    /// children views
    vector<unique_ptr<View>> children;
    /// layout direction (default: vertical)
    LayoutDirectionType layoutDirection = LayoutDirectionVertical;

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
