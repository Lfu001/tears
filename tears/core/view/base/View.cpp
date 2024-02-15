//
//  View.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/19.
//  Copyright © 2023 tears team. All rights reserved.
//

#include <algorithm>
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
    computeChildSize();
    computeChildPosition();
    setIsDirtyLayout(false);
}

// draw the view
void View::draw() {
    if (!getIsVisible()) {    /// if the view is invisible
        return;
    }
    if (getIsDirtyLayout()) {    /// if the view needs layout calculation
        layout();
    }
    MatrixStackScope mss;
    AffineTransform* top = mss.getTopMatrix();
    top->translate(Size(position.x, position.y));

    drawMain();
    for (auto& c: children) {
        c->draw();
    }
}

/// main draw processing. call GLController::drawArrays() from this method.
void View::drawMain() {}

// compute and set a position of child views
void View::computeChildPosition() {
    if (layoutDirection == LayoutDirectionVertical) {    /// if it is vertical layout
        float y = 0.f;
        for (const auto& child: children) {
            if (!child->getIsVisible()) {    /// if child view is invisible
                continue;
            }

            switch (child->getAlignment()) {
                case AlignmentTopLeading:
                case AlignmentLeading:
                case AlignmentBottomLeading:
                    setX(0.f);
                    break;
                case AlignmentTop:
                case AlignmentCenter:
                case AlignmentBottom:
                    setX((getWidth() - child->getWidth()) / 2.f);
                    break;
                case AlignmentTopTrailing:
                case AlignmentTrailing:
                case AlignmentBottomTrailing:
                    setX(getWidth() - child->getWidth());
                    break;
                default:
                    tears_assert(false);
                    break;
            }
            child->setY(y);
            y += child->getHeight();
        }
    } else if (layoutDirection == LayoutDirectionHorizontal) {    /// if it is horizontal layout
        float x = 0.f;
        for (const auto& child: children) {
            if (!child->getIsVisible()) {    /// if child view is invisible
                continue;
            }

            child->setX(x);
            x += child->getWidth();
            switch (child->getAlignment()) {
                case AlignmentTopLeading:
                case AlignmentTop:
                case AlignmentTopTrailing:
                    setY(0.f);
                    break;
                case AlignmentLeading:
                case AlignmentCenter:
                case AlignmentTrailing:
                    setY((getHeight() - child->getHeight()) / 2.f);
                    break;
                case AlignmentBottomLeading:
                case AlignmentBottom:
                case AlignmentBottomTrailing:
                    setY(getHeight() - child->getHeight());
                    break;
                default:
                    tears_assert(false);
                    break;
            }
        }
    } else if (layoutDirection == LayoutDirectionZ) {    /// if it is z-axes aligned layout
        for (const auto& child: children) {
            if (!child->getIsVisible()) {                /// if child view is invisible
                continue;
            }

            switch (child->getAlignment()) {
                case AlignmentTopLeading:
                    setPosition(0.f, 0.f);
                    break;
                case AlignmentTop:
                    setPosition((getWidth() - child->getWidth()) / 2.f, 0.f);
                    break;
                case AlignmentTopTrailing:
                    setPosition(getWidth() - child->getWidth(), 0.f);
                    break;
                case AlignmentLeading:
                    setPosition(0.f, (getHeight() - child->getHeight()) / 2.f);
                    break;
                case AlignmentCenter:
                    setPosition(
                        (getWidth() - child->getWidth()) / 2.f,
                        (getHeight() - child->getHeight()) / 2.f);
                    break;
                case AlignmentTrailing:
                    setPosition(
                        getWidth() - child->getWidth(),
                        (getHeight() - child->getHeight()) / 2.f);
                    break;
                case AlignmentBottomLeading:
                    setPosition(0.f, getHeight() - child->getHeight());
                    break;
                case AlignmentBottom:
                    setPosition(
                        (getWidth() - child->getWidth()) / 2.f,
                        getHeight() - child->getHeight());
                    break;
                case AlignmentBottomTrailing:
                    setPosition(getWidth() - child->getWidth(), getHeight() - child->getHeight());
                    break;
                default:
                    tears_assert(false);
                    break;
            }
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
            child->setWidth(child->computeWidth(proposedWidth));
            widthFlags[i] = true;
        }
        if (!heightFlags[i]) {    /// if height is not computed yet
            child->setWidth(child->computeHeight(proposedHeight));
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
            float paddingHorizontal = child->getPadding(EdgeHorizontal);
            float borderHorizontal = child->getBorder(EdgeHorizontal);
            float width = map[ModifierWidth] + paddingHorizontal + borderHorizontal;
            child->setWidth(width);
            if (layoutDirection
                == LayoutDirectionHorizontal) {    /// if layout direction is horizontal
                outLayoutSpace.width = max(0.f, outLayoutSpace.width - width);
            }
            outWidthFlags[i] = true;
        }
        if (map.contains(ModifierHeight)) {    /// if height is specified
            float paddingVertical = child->getPadding(EdgeVertical);
            float borderVertical = child->getBorder(EdgeVertical);
            float height = map[ModifierHeight] + paddingVertical + borderVertical;
            child->setHeight(height);
            if (layoutDirection == LayoutDirectionVertical) {    /// if layout direction is vertical
                outLayoutSpace.height = max(0.f, outLayoutSpace.height - height);
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
void View::setSize(float aWidth, float aHeight) {
    if (getWidth() == aWidth && getHeight() == aHeight) {    /// if size is not changed
        return;
    }
    size.width = aWidth;
    size.height = aHeight;
    setIsDirtyLayout(true);
}

// set view width
void View::setWidth(float aWidth) {
    if (getWidth() == aWidth) {    /// if width is not changed
        return;
    }
    size.width = aWidth;
    setIsDirtyLayout(true);
}

// set view height
void View::setHeight(float aHeight) {
    if (getHeight() == aHeight) {    /// if height is not changed
        return;
    }
    size.height = aHeight;
    setIsDirtyLayout(true);
}

}    // namespace tears
