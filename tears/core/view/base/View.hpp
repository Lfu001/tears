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
#include "math/Point.hpp"
#include "math/Size.hpp"
#include "utils/DebugUtil.hpp"
#include "view/base/LayoutDirectionType.hpp"
#include "view/base/Modifier.hpp"
#include "view/base/ViewFlag.hpp"

namespace tears {

using namespace std;

class Scene;

/// represents part of the user interface and provide modifier to configure views
/// @ingroup view
class View: public Modifier, public ViewFlag {
    friend Scene;

private:
    /// assignable view ID
    static int64_t nextViewId;
    /// view ID
    int64_t id;

private:
    /// assign view ID
    void assignViewId();

    /// compute and set a position of child views
    void computeChildPosition();
    /// compute and set a size of child views
    void computeChildSize();
    /// compute and set a size of child views if specified
    /// @param[out] outWidthFlags an output flags for each child that represents whether width is
    /// already computed
    /// @param[out] outHeightFlags an output flags for each child that represents whether height is
    /// already computed
    /// @param[out] outLayoutSpace an output size represents available layout space remained
    void computeChildSizeIfSpecified(
        vector<bool>& outWidthFlags,
        vector<bool>& outHeightFlags,
        Size& outLayoutSpace);
    /// compute size to be proposed to child views
    /// @param layoutSpace a space that can be used to layout children
    /// @param widthCount the number of children which width is not computed yet
    /// @param heightCount the number of children which height is not computed yet
    Size computeProposingSize(const Size& layoutSpace, int widthCount, int heightCount) const;
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
    void setSizeInternal(float aWidth, float aHeight);
    /// set view width
    void setWidthInternal(float aWidth);
    /// set view height
    void setHeightInternal(float aHeight);
    /// layout the view
    virtual void layout();
    /// calculate layout if needed, and draw this view and the children
    void draw();

protected:
    /// view position
    Point position;
    /// view size
    Size size;
    /// children views
    vector<unique_ptr<View>> children;
    /// layout direction (default: vertical)
    LayoutDirectionType layoutDirection = LayoutDirectionVertical;

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
    /// main drawing process
    ///!!! info
    ///    call GLController::drawArrays() from this method.
    virtual void drawMain();
    /// get the vertices of the view
    vector<Point> getVertices() const;
    /// get the texture coordinates of the view in the screen texture
    vector<Point> getTexCoord() const;

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
    Point getPosition() const { return position; }
    /// get view position x
    float getX() const { return position.x; }
    /// get view position y
    float getY() const { return position.y; }
    /// get view size
    Size getSize() const { return size; }
    /// get view width
    float getWidth() const { return size.width; }
    /// get view height
    float getHeight() const { return size.height; }
};

}    // namespace tears

#endif /* View_hpp */
