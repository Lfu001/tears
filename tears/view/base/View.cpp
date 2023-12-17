//
//  View.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/19.
//  Copyright © 2023 tears team. All rights reserved.
//

#include <algorithm>

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

// compute and set a position of child views
void View::computeChildPosition() {
    if (layoutDirection == LayoutDirectionVertical) {    /// if it is vertical layout
        float y = 0.f;
        for (auto& child: children) {
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
        for (auto& child: children) {
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
    } else {
        tears_assert(false);
    }
}

// compute a size of the child views
void View::computeChildSize() {
    vector<bool> widthFlags(children.size(), false), heightFlags(children.size(), false);
    Vector2D layoutSpace = size;

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
    float proposedWidth =
        (widthUnspecifiedCount == 0) ? 0.f : layoutSpace.getWidth() / widthUnspecifiedCount;
    float proposedHeight =
        (heightUnspecifiedCount == 0) ? 0.f : layoutSpace.getHeight() / heightUnspecifiedCount;
    if (layoutDirection == LayoutDirectionVertical) {
        proposedWidth = layoutSpace.getWidth();
    } else if (layoutDirection == LayoutDirectionVertical) {
        proposedHeight = layoutSpace.getHeight();
    } else {
        tears_assert(false);
    }

    /// if width range or height range is specified
    for (int i = 0; i < children.size(); i++) {
        auto& child = children[i];
        if (!child->getIsVisible()) {    /// if child view is invisible
            widthFlags[i] = true;
            heightFlags[i] = true;
            continue;
        }

        if (!widthFlags[i]) {    /// if width is not computed yet
            child->size.setWidth(child->computeWidth(proposedWidth));
            widthFlags[i] = true;
        }
        if (!heightFlags[i]) {    /// if height is not computed yet
            child->size.setWidth(child->computeHeight(proposedHeight));
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
    Vector2D& outLayoutSpace) {
    for (int i = 0; i < children.size(); i++) {
        auto& child = children[i];
        if (!child->getIsVisible()) {    /// if child view is invisible
            outWidthFlags[i] = true;
            outHeightFlags[i] = true;
            continue;
        }

        unordered_map<ModifierType, float>& map = child->modifierMap;

        float paddingHorizontal = child->getPadding(EdgeHorizontal);
        float borderHorizontal = child->getBorder(EdgeHorizontal);
        if (map.contains(ModifierWidth)) {    /// if width is specified
            float width = map[ModifierWidth] + paddingHorizontal + borderHorizontal;
            child->size.setWidth(width);
            outLayoutSpace.setWidth(max(0.f, outLayoutSpace.getWidth() - width));
            outWidthFlags[i] = true;
        } else if (layoutDirection == LayoutDirectionVertical) {
            /// if width is unspecified and layout direction is vertical
            child->size.setWidth(outLayoutSpace.getWidth() - paddingHorizontal - borderHorizontal);
            outWidthFlags[i] = true;
        }
        float paddingVertical = child->getPadding(EdgeVertical);
        float borderVertical = child->getBorder(EdgeVertical);
        if (map.contains(ModifierHeight)) {    /// if height is specified
            float height = map[ModifierHeight] + paddingVertical + borderVertical;
            child->size.setHeight(height);
            outLayoutSpace.setHeight(max(0.f, outLayoutSpace.getHeight() - height));
            outHeightFlags[i] = true;
        } else if (layoutDirection == LayoutDirectionHorizontal) {
            /// if height is unspecified and layout direction is horizontal
            child->size.setHeight(outLayoutSpace.getHeight() - paddingVertical - borderVertical);
            outHeightFlags[i] = true;
        }
    }
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
    position.setX(aX);
    position.setY(aY);
    setIsDirtyLayout(true);
}

// set view position x
void View::setX(float aX) {
    if (getX() == aX) {    /// if position x is not changed
        return;
    }
    position.setX(aX);
    setIsDirtyLayout(true);
}

// set view position y
void View::setY(float aY) {
    if (getY() == aY) {    /// if position y is not changed
        return;
    }
    position.setY(aY);
    setIsDirtyLayout(true);
}

// set view size
void View::setSize(float aWidth, float aHeight) {
    if (getWidth() == aWidth && getHeight() == aHeight) {    /// if size is not changed
        return;
    }
    size.setWidth(aWidth);
    size.setHeight(aHeight);
    setIsDirtyLayout(true);
}

// set view width
void View::setWidth(float aWidth) {
    if (getWidth() == aWidth) {    /// if width is not changed
        return;
    }
    size.setWidth(aWidth);
    setIsDirtyLayout(true);
}

// set view height
void View::setHeight(float aHeight) {
    if (getHeight() == aHeight) {    /// if height is not changed
        return;
    }
    size.setHeight(aHeight);
    setIsDirtyLayout(true);
}

}    // namespace tears
