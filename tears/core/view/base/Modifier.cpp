//
//  Modifier.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "math/Point.hpp"
#include "utils/DebugUtil.hpp"
#include "Modifier.hpp"

namespace tears {

// constructor
Modifier::Modifier() {
    modifierMap.reserve(ModifierTypeCount);
}

// destructor
Modifier::~Modifier() {}

// get offset x and y
Point Modifier::getOffset() {
    Point p(0.0, 0.0);
    if (modifierMap.contains(ModifierOffsetX)) {    /// if offset x is specified
        p.x = modifierMap[ModifierOffsetX];
    }
    if (modifierMap.contains(ModifierOffsetY)) {    /// if offset y is specified
        p.y = modifierMap[ModifierOffsetY];
    }
    return p;
}

// set offset x and y
Modifier& Modifier::setOffset(float x, float y) {
    modifierMap[ModifierOffsetX] = x;
    modifierMap[ModifierOffsetY] = y;
    return *this;
}

// get offset x
float Modifier::getOffsetX() {
    if (modifierMap.contains(ModifierOffsetX)) {    /// if offset x is specified
        return modifierMap[ModifierOffsetX];
    } else {
        return 0.f;
    }
}

// set offset x
Modifier& Modifier::setOffsetX(float x) {
    modifierMap[ModifierOffsetX] = x;
    return *this;
}

// get offset y
float Modifier::getOffsetY() {
    if (modifierMap.contains(ModifierOffsetY)) {
        return modifierMap[ModifierOffsetY];
    } else {
        return 0.f;
    }
}

// set offset y
Modifier& Modifier::setOffsetY(float y) {
    modifierMap[ModifierOffsetY] = y;
    return *this;
}

// set size
Modifier& Modifier::setSize(float width, float height) {
    modifierMap[ModifierWidth] = width;
    modifierMap[ModifierHeight] = height;
    return *this;
}

// set width
Modifier& Modifier::setWidth(float width) {
    modifierMap[ModifierWidth] = width;
    return *this;
}

// set height
Modifier& Modifier::setHeight(float height) {
    modifierMap[ModifierHeight] = height;
    return *this;
}

// set width range (ignored if width is specified)
Modifier& Modifier::setWidthRange(float min, float max) {
    modifierMap[ModifierMinWidth] = min;
    modifierMap[ModifierMaxWidth] = max;
    return *this;
}

// set height range (ignored if height is specified)
Modifier& Modifier::setHeightRange(float min, float max) {
    modifierMap[ModifierMinHeight] = min;
    modifierMap[ModifierMaxHeight] = max;
    return *this;
}

// set minimum width (ignored if width is specified)
Modifier& Modifier::setMinWidth(float min) {
    modifierMap[ModifierMinWidth] = min;
    return *this;
}

// set minimum height (ignored if height is specified)
Modifier& Modifier::setMinHeight(float min) {
    modifierMap[ModifierMinHeight] = min;
    return *this;
}

// set maximum width (ignored if width is specified)
Modifier& Modifier::setMaxWidth(float max) {
    modifierMap[ModifierMaxWidth] = max;
    return *this;
}
// set maximum height (ignored if height is specified)
Modifier& Modifier::setMaxHeight(float max) {
    modifierMap[ModifierMaxHeight] = max;
    return *this;
}

// set width ratio (ignored if width is specified)
Modifier& Modifier::setWidthRatio(float ratio) {
    modifierMap[ModifierWidthRatio] = ratio;
    return *this;
}

// set height ratio (ignored if height is specified)
Modifier& Modifier::setHeightRatio(float ratio) {
    modifierMap[ModifierHeightRatio] = ratio;
    return *this;
}

// set layout priority (the higher the value, the higher the priority)
Modifier& Modifier::setLayoutPriority(float priority) {
    modifierMap[ModifierLayoutPriority] = priority;
    return *this;
}

// get alignment
AlignmentType Modifier::getAlignment() {
    if (modifierMap.contains(ModifierAlignment)) {    /// if alignment is specified
        return (AlignmentType)(int)modifierMap[ModifierAlignment];
    } else {
        return AlignmentCenter;
    }
}

// set alignment
Modifier& Modifier::setAlignment(AlignmentType alignment) {
    modifierMap[ModifierAlignment] = (float)alignment;
    return *this;
}

// get padding
float Modifier::getPadding(EdgeType edge) {
    switch (edge) {
        case EdgeTop:
            return modifierMap.contains(ModifierPaddingTop) ? modifierMap[ModifierPaddingTop] : 0.f;
        case EdgeBottom:
            return modifierMap.contains(ModifierPaddingBottom) ? modifierMap[ModifierPaddingBottom]
                                                               : 0.f;
        case EdgeLeading:
            return modifierMap.contains(ModifierPaddingLeading)
                       ? modifierMap[ModifierPaddingLeading]
                       : 0.f;
        case EdgeTrailing:
            return modifierMap.contains(ModifierPaddingTrailing)
                       ? modifierMap[ModifierPaddingTrailing]
                       : 0.f;
        case EdgeVertical:
            return (modifierMap.contains(ModifierPaddingTop) ? modifierMap[ModifierPaddingTop]
                                                             : 0.f)
                   + (modifierMap.contains(ModifierPaddingBottom)
                          ? modifierMap[ModifierPaddingBottom]
                          : 0.f);
        case EdgeHorizontal:
            return (modifierMap.contains(ModifierPaddingLeading)
                        ? modifierMap[ModifierPaddingLeading]
                        : 0.f)
                   + (modifierMap.contains(ModifierPaddingTrailing)
                          ? modifierMap[ModifierPaddingTrailing]
                          : 0.f);
        default:
            tears_assert(false);
            return 0.f;
    }
}

// set padding
Modifier& Modifier::setPadding(EdgeType edge, float val) {
    switch (edge) {
        case EdgeAll:
            modifierMap[ModifierPaddingTop] = val;
            modifierMap[ModifierPaddingBottom] = val;
            modifierMap[ModifierPaddingLeading] = val;
            modifierMap[ModifierPaddingTrailing] = val;
            break;
        case EdgeTop:
            modifierMap[ModifierPaddingTop] = val;
            break;
        case EdgeBottom:
            modifierMap[ModifierPaddingBottom] = val;
            break;
        case EdgeLeading:
            modifierMap[ModifierPaddingLeading] = val;
            break;
        case EdgeTrailing:
            modifierMap[ModifierPaddingTrailing] = val;
            break;
        case EdgeVertical:
            modifierMap[ModifierPaddingTop] = val;
            modifierMap[ModifierPaddingBottom] = val;
            break;
        case EdgeHorizontal:
            modifierMap[ModifierPaddingLeading] = val;
            modifierMap[ModifierPaddingTrailing] = val;
            break;
        default:
            tears_assert(false);
            break;
    }
    return *this;
}

// get border
float Modifier::getBorder(EdgeType edge) {
    switch (edge) {
        case EdgeTop:
            return modifierMap.contains(ModifierBorderTop) ? modifierMap[ModifierBorderTop] : 0.f;
        case EdgeBottom:
            return modifierMap.contains(ModifierBorderBottom) ? modifierMap[ModifierBorderBottom]
                                                              : 0.f;
        case EdgeLeading:
            return modifierMap.contains(ModifierBorderLeading) ? modifierMap[ModifierBorderLeading]
                                                               : 0.f;
        case EdgeTrailing:
            return modifierMap.contains(ModifierBorderTrailing)
                       ? modifierMap[ModifierBorderTrailing]
                       : 0.f;
        case EdgeVertical:
            return (modifierMap.contains(ModifierBorderTop) ? modifierMap[ModifierBorderTop] : 0.f)
                   + (modifierMap.contains(ModifierBorderBottom) ? modifierMap[ModifierBorderBottom]
                                                                 : 0.f);
        case EdgeHorizontal:
            return (modifierMap.contains(ModifierBorderLeading) ? modifierMap[ModifierBorderLeading]
                                                                : 0.f)
                   + (modifierMap.contains(ModifierBorderTrailing)
                          ? modifierMap[ModifierBorderTrailing]
                          : 0.f);
        default:
            tears_assert(false);
            return 0.f;
    }
}

// set border
Modifier& Modifier::setBorder(EdgeType edge, float val) {
    switch (edge) {
        case EdgeAll:
            modifierMap[ModifierBorderTop] = val;
            modifierMap[ModifierBorderBottom] = val;
            modifierMap[ModifierBorderLeading] = val;
            modifierMap[ModifierBorderTrailing] = val;
            break;
        case EdgeTop:
            modifierMap[ModifierBorderTop] = val;
            break;
        case EdgeBottom:
            modifierMap[ModifierBorderBottom] = val;
            break;
        case EdgeLeading:
            modifierMap[ModifierBorderLeading] = val;
            break;
        case EdgeTrailing:
            modifierMap[ModifierBorderTrailing] = val;
            break;
        case EdgeVertical:
            modifierMap[ModifierBorderTop] = val;
            modifierMap[ModifierBorderBottom] = val;
            break;
        case EdgeHorizontal:
            modifierMap[ModifierBorderLeading] = val;
            modifierMap[ModifierBorderTrailing] = val;
            break;
        default:
            tears_assert(false);
            break;
    }
    return *this;
}

}    // namespace tears
