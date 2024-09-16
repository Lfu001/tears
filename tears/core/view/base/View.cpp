//
//  View.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/19.
//  Copyright © 2023 tears team. All rights reserved.
//

#include <algorithm>
#include "gl/GLController.hpp"
#include "gl/MatrixStackScope.hpp"
#include "math/AffineTransform.hpp"
#include "View.hpp"

namespace tears {

using namespace std;

// assignable view ID (initial value)
int64_t View::nextViewId = 0x0;

// default constructor
View::View() {
    assignViewId();
}

// destructor
View::~View() {}

// assign view ID
void View::assignViewId() {
    id = nextViewId;
    nextViewId++;
}

// layout the view
void View::layout() {
    for (const auto& c: children) {
        if (c) {
            c->viewWillLayout();
        }
    }

    computeChildSize();
    computeChildPosition();
    setIsDirtyLayout(false);

    for (const auto& c: children) {
        if (c) {
            c->viewDidLayout();
        }
    }
}

// draw the view
void View::draw() {
    if (!getIsVisible()) {    /// if the view is invisible
        return;
    }
    if (getIsDirtyLayout()) {    /// if the view needs layout calculation
        layout();
    }
    drawMain();

    MatrixStackScope mss;
    AffineTransform* top = mss.getTopMatrix();
    top->translate(Size(position.x, position.y));
    for (auto& c: children) {
        c->draw();
    }
}

// main drawing process. call GLController::drawArrays() from this method.
void View::drawMain() {}

// get the vertices of the view
vector<Point> View::getVertices() const {
    vector<Point> v(4);
    float x2 = position.x + size.width;
    float y2 = position.y + size.height;
    v[0] = position;
    v[1] = Point(position.x, y2);
    v[2] = Point(x2, position.y);
    v[3] = Point(x2, y2);
    return v;
}

// get the texture coordinates of the view in the screen texture
vector<Point> View::getTexCoord() const {
    // convert local view coordinates to screen coordinates
    MatrixStackScope mss;
    AffineTransform* mat = mss.getTopMatrix();
    GLController* gl = GLController::getInstance();
    float screenScale = gl->getScreenScale();
    mat->scale(Size(screenScale, screenScale));
    vector<Point> res = gl->applyMatricesCpu(getVertices());

    // convert screen coordinates to texture coordinates
    AffineTransform uvMat;
    Size screenSize = gl->getScreenSize();
    float w = screenSize.width * screenScale;
    float h = screenSize.height * screenScale;
    uvMat.scale(Size(1.f / w, 1.f / h));
    for (auto& p: res) {
        p = p.applyTransform(uvMat);
    }
    iter_swap(res.begin(), res.begin() + 1);
    iter_swap(res.begin() + 2, res.begin() + 3);

    return res;
}

// compute and set a position of child views
void View::computeChildPosition() {
    if (layoutDirection == LayoutDirectionVertical) {    /// if it is vertical layout
        float hSum = 0.f;
        for (const auto& child: children) {
            if (child->getIsVisible()) {    /// if child view is visible
                hSum += child->getInnerHeight();
            }
        }
        float y = (size.height - hSum) / 2.f;

        for (const auto& child: children) {
            if (!child->getIsVisible()) {    /// if child view is invisible
                continue;
            }

            float offsetX = child->getOffsetX();
            switch (child->getAlignment()) {
                case AlignmentTopLeading:
                case AlignmentLeading:
                case AlignmentBottomLeading:
                    child->setX(0.f + offsetX);
                    break;
                case AlignmentTop:
                case AlignmentCenter:
                case AlignmentBottom:
                    child->setX((getWidth() - child->getWidth()) / 2.f + offsetX);
                    break;
                case AlignmentTopTrailing:
                case AlignmentTrailing:
                case AlignmentBottomTrailing:
                    child->setX(getWidth() - child->getWidth() + offsetX);
                    break;
                default:
                    tears_assert(false);
                    break;
            }
            y += child->getPadding(EdgeTop) + child->getBorder(EdgeTop);
            child->setY(y + child->getOffsetY());
            y += child->getHeight() + child->getPadding(EdgeBottom) + child->getBorder(EdgeBottom);
        }
    } else if (layoutDirection == LayoutDirectionHorizontal) {    /// if it is horizontal layout
        float wSum = 0.f;
        for (const auto& child: children) {
            if (child->getIsVisible()) {    /// if child view is visible
                wSum += child->getInnerWidth();
            }
        }
        float x = (size.width - wSum) / 2.f;

        for (const auto& child: children) {
            if (!child->getIsVisible()) {    /// if child view is invisible
                continue;
            }

            x += child->getPadding(EdgeLeading) + child->getBorder(EdgeLeading);
            child->setX(x + child->getOffsetX());
            x += child->getWidth() + child->getPadding(EdgeTrailing)
                 + child->getBorder(EdgeTrailing);
            float offsetY = child->getOffsetY();
            switch (child->getAlignment()) {
                case AlignmentTopLeading:
                case AlignmentTop:
                case AlignmentTopTrailing:
                    child->setY(0.f + offsetY);
                    break;
                case AlignmentLeading:
                case AlignmentCenter:
                case AlignmentTrailing:
                    child->setY((getHeight() - child->getHeight()) / 2.f + offsetY);
                    break;
                case AlignmentBottomLeading:
                case AlignmentBottom:
                case AlignmentBottomTrailing:
                    child->setY(getHeight() - child->getHeight() + offsetY);
                    break;
                default:
                    tears_assert(false);
                    break;
            }
        }
    } else if (layoutDirection == LayoutDirectionZ) {    /// if it is z-axes aligned layout
        for (const auto& child: children) {
            if (!child->getIsVisible()) {    /// if child view is invisible
                continue;
            }

            float x = 0.f;
            float y = 0.f;
            switch (child->getAlignment()) {
                case AlignmentTopLeading:
                    x = 0.f;
                    y = 0.f;
                    break;
                case AlignmentTop:
                    x = (getWidth() - child->getWidth()) / 2.f;
                    y = 0.f;
                    break;
                case AlignmentTopTrailing:
                    x = getWidth() - child->getWidth();
                    y = 0.f;
                    break;
                case AlignmentLeading:
                    x = 0.f;
                    y = (getHeight() - child->getHeight()) / 2.f;
                    break;
                case AlignmentCenter:
                    x = (getWidth() - child->getWidth()) / 2.f;
                    y = (getHeight() - child->getHeight()) / 2.f;
                    break;
                case AlignmentTrailing:
                    x = getWidth() - child->getWidth();
                    y = (getHeight() - child->getHeight()) / 2.f;
                    break;
                case AlignmentBottomLeading:
                    x = 0.f;
                    y = getHeight() - child->getHeight();
                    break;
                case AlignmentBottom:
                    x = (getWidth() - child->getWidth()) / 2.f;
                    y = getHeight() - child->getHeight();
                    break;
                case AlignmentBottomTrailing:
                    x = getWidth() - child->getWidth();
                    y = getHeight() - child->getHeight();
                    break;
                default:
                    tears_assert(false);
                    x = 0.f;
                    y = 0.f;
                    break;
            }
            child->setPosition(x + child->getOffsetX(), y + child->getOffsetY());
        }
    } else {
        tears_assert(false);
    }
}

// compute a size of the child views
void View::computeChildSize() {
    vector<bool> widthFlags(children.size(), false), heightFlags(children.size(), false);
    Size layoutSpace = size;

    computeChildSizeIfSpecified(widthFlags, heightFlags, layoutSpace);

    auto reverseFlag = [](bool flag) {
        return !flag;
    };
    int widthUnspecifiedCount = (int)count_if(widthFlags.begin(), widthFlags.end(), reverseFlag);
    int heightUnspecifiedCount = (int)count_if(heightFlags.begin(), heightFlags.end(), reverseFlag);
    if (widthUnspecifiedCount == 0 && heightUnspecifiedCount == 0) {
        /// if all the components size is computed and set
        return;
    }
    Size proposedSize =
        computeProposingSize(layoutSpace, widthUnspecifiedCount, heightUnspecifiedCount);
    float proposedWidth = proposedSize.width;
    float proposedHeight = proposedSize.height;

    /// if width range or height range is specified
    for (int i = 0; i < children.size(); i++) {
        auto& child = children[i];
        if (!child->getIsVisible()) {    /// if child view is invisible
            widthFlags[i] = true;
            heightFlags[i] = true;
            continue;
        }

        if (!widthFlags[i]) {    /// if width is not computed yet
            child->setWidthInternal(child->computeWidth(proposedWidth));
            widthFlags[i] = true;
        }
        if (!heightFlags[i]) {    /// if height is not computed yet
            child->setHeightInternal(child->computeHeight(proposedHeight));
            heightFlags[i] = true;
        }
    }
    tears_assert((int)count_if(widthFlags.begin(), widthFlags.end(), reverseFlag) == 0);
    tears_assert((int)count_if(heightFlags.begin(), heightFlags.end(), reverseFlag) == 0);
}

// set a size of child views if specified
void View::computeChildSizeIfSpecified(
    vector<bool>& outWidthFlags,
    vector<bool>& outHeightFlags,
    Size& outLayoutSpace) {
    for (int i = 0; i < children.size(); i++) {
        auto& child = children[i];
        if (!child->getIsVisible()) {    /// if child view is invisible
            outWidthFlags[i] = true;
            outHeightFlags[i] = true;
            continue;
        }

        unordered_map<ModifierType, float>& map = child->modifierMap;

        if (map.contains(ModifierWidth)) {    /// if width is specified
            float width = map[ModifierWidth];
            ;
            child->setWidthInternal(width);
            if (layoutDirection
                == LayoutDirectionHorizontal) {    /// if layout direction is horizontal
                float paddingHorizontal = child->getPadding(EdgeHorizontal);
                float borderHorizontal = child->getBorder(EdgeHorizontal);
                outLayoutSpace.width =
                    max(0.f, outLayoutSpace.width - width - paddingHorizontal - borderHorizontal);
            }
            outWidthFlags[i] = true;
        }
        if (map.contains(ModifierHeight)) {    /// if height is specified
            float height = map[ModifierHeight];
            child->setHeightInternal(height);
            if (layoutDirection == LayoutDirectionVertical) {    /// if layout direction is vertical
                float paddingVertical = child->getPadding(EdgeVertical);
                float borderVertical = child->getBorder(EdgeVertical);
                outLayoutSpace.height =
                    max(0.f, outLayoutSpace.height - height - paddingVertical - borderVertical);
            }
            outHeightFlags[i] = true;
        }
    }
}

// compute size to be proposed to child views
Size View::computeProposingSize(const Size& layoutSpace, int widthCount, int heightCount) const {
    float proposedWidth = (widthCount == 0) ? 0.f : layoutSpace.width / widthCount;
    float proposedHeight = (heightCount == 0) ? 0.f : layoutSpace.height / heightCount;
    if (layoutDirection == LayoutDirectionVertical) {
        proposedWidth = getWidth();
    } else if (layoutDirection == LayoutDirectionHorizontal) {
        proposedHeight = getHeight();
    } else if (layoutDirection == LayoutDirectionZ) {
        proposedWidth = getWidth();
        proposedHeight = getHeight();
    } else {
        tears_assert(false);
    }
    return Size(proposedWidth, proposedHeight);
}

// respond the width computed from width range and the proposed width by parent
float View::computeWidth(float proposedWidth) {
    float minWidth = modifierMap.contains(ModifierMinWidth) ? modifierMap[ModifierMinWidth] : 0.f;
    float maxWidth = modifierMap.contains(ModifierMaxWidth) ? modifierMap[ModifierMaxWidth]
                                                            : numeric_limits<float>::max();
    tears_assert(minWidth <= maxWidth);
    float paddingHorizontal = getPadding(EdgeHorizontal);
    float borderHorizontal = getBorder(EdgeHorizontal);
    float width = proposedWidth - paddingHorizontal - borderHorizontal;
    return max(minWidth, min(width, maxWidth));
}

// respond the height computed from height range and the proposed height by parent
float View::computeHeight(float proposedHeight) {
    float minHeight =
        modifierMap.contains(ModifierMinHeight) ? modifierMap[ModifierMinHeight] : 0.f;
    float maxHeight = modifierMap.contains(ModifierMaxHeight) ? modifierMap[ModifierMaxHeight]
                                                              : numeric_limits<float>::max();
    tears_assert(minHeight <= maxHeight);
    float paddingVertical = getPadding(EdgeVertical);
    float borderVertical = getBorder(EdgeVertical);
    float height = proposedHeight - paddingVertical - borderVertical;
    return max(minHeight, min(height, maxHeight));
}

// set view position
void View::setPosition(float aX, float aY) {
    if (getX() == aX && getY() == aY) {    /// if position is not changed
        return;
    }
    position.x = aX;
    position.y = aY;
    setIsDirtyLayout(true);
}

// set view position x
void View::setX(float aX) {
    if (getX() == aX) {    /// if position x is not changed
        return;
    }
    position.x = aX;
    setIsDirtyLayout(true);
}

// set view position y
void View::setY(float aY) {
    if (getY() == aY) {    /// if position y is not changed
        return;
    }
    position.y = aY;
    setIsDirtyLayout(true);
}

// set view size
void View::setSizeInternal(float aWidth, float aHeight) {
    if (getWidth() == aWidth && getHeight() == aHeight) {    /// if size is not changed
        return;
    }
    size.width = aWidth;
    size.height = aHeight;
    setIsDirtyLayout(true);
}

// set view width
void View::setWidthInternal(float aWidth) {
    if (getWidth() == aWidth) {    /// if width is not changed
        return;
    }
    size.width = aWidth;
    setIsDirtyLayout(true);
}

// set view height
void View::setHeightInternal(float aHeight) {
    if (getHeight() == aHeight) {    /// if height is not changed
        return;
    }
    size.height = aHeight;
    setIsDirtyLayout(true);
}

}    // namespace tears
