//
//  Modifier.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "utils/DebugUtil.hpp"
#include "Modifier.hpp"

namespace tears {

// constructor
Modifier::Modifier() {
    modifierMap.reserve(ModifierTypeCount);
}

// destructor
Modifier::~Modifier() {}

// set offset x and y
Modifier& Modifier::setOffset(float x, float y) {
    modifierMap[ModifierOffsetX] = x;
    modifierMap[ModifierOffsetY] = y;
    return *this;
}

// set offset x
Modifier& Modifier::setOffsetX(float x) {
    modifierMap[ModifierOffsetX] = x;
    return *this;
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

// set alignment
Modifier& Modifier::setAlignment(AlignmentType alignment) {
    modifierMap[ModifierAlignment] = (float)alignment;
    return *this;
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
