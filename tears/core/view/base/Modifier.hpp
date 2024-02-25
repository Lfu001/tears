//
//  Modifier.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef Modifier_hpp
#define Modifier_hpp

#include <unordered_map>
#include "view/base/AlignmentType.hpp"
#include "view/base/EdgeType.hpp"

namespace tears {

using namespace std;

/// Modifier types.
/// DO NOT explicitly assign value to any member since ModifierTypeCount member represents the
/// number of the enum members.
/// @ingroup view
enum ModifierType {
    /// offset x
    ModifierOffsetX,
    /// offset y
    ModifierOffsetY,

    /// width
    ModifierWidth,
    /// height
    ModifierHeight,
    /// minimum width (ignored if width is specified)
    ModifierMinWidth,
    /// minimum height (ignored if absolute height is specified)
    ModifierMinHeight,
    /// maximum width (ignored if width is specified)
    ModifierMaxWidth,
    /// maximum height (ignored if absolute height is specified)
    ModifierMaxHeight,
    /// width ratio (ignored if width is specified)
    ModifierWidthRatio,
    /// height ratio (ignored if absolute height is specified)
    ModifierHeightRatio,

    /// layout priority (the higher the value, the higher the priority)
    ModifierLayoutPriority,

    /// alignment
    ModifierAlignment,

    /// padding (top)
    ModifierPaddingTop,
    /// padding (bottom)
    ModifierPaddingBottom,
    /// padding (leading)
    ModifierPaddingLeading,
    /// padding (trailing)
    ModifierPaddingTrailing,

    /// border (top)
    ModifierBorderTop,
    /// border (bottom)
    ModifierBorderBottom,
    /// border (leading)
    ModifierBorderLeading,
    /// border (trailing)
    ModifierBorderTrailing,

    /// The number of modifier types.
    /// This member MUST be placed in the last position of the enum declaration.
    /// DO NOT insert new member below.
    ModifierTypeCount,
};

/// modifier collections for View
/// @ingroup view/base 
class Modifier {
protected:
    /// specified modifiers
    unordered_map<ModifierType, float> modifierMap;

protected:
    /// get offset x and y
    Point getOffset();
    /// get offset x
    float getOffsetX();
    /// get offset y
    float getOffsetY();

    /// get alignment
    AlignmentType getAlignment();

    /// get padding
    /// @param edge top, bottom, leading, trailing, vertical or horizontal
    float getPadding(EdgeType edge);
    /// get border
    /// @param edge top, bottom, leading, trailing, vertical or horizontal
    float getBorder(EdgeType edge);

public:
    /// constructor
    Modifier();
    /// destructor
    virtual ~Modifier();

public:
    /// set offset x and y
    Modifier& setOffset(float x, float y);
    /// set offset x
    Modifier& setOffsetX(float x);
    /// set offset y
    Modifier& setOffsetY(float y);

    /// set size
    Modifier& setSize(float width, float height);
    /// set width
    Modifier& setWidth(float width);
    /// set height
    Modifier& setHeight(float height);
    /// set width range (ignored if width is specified)
    Modifier& setWidthRange(float min, float max);
    /// set height range (ignored if height is specified)
    Modifier& setHeightRange(float min, float max);
    /// set minimum width (ignored if width is specified)
    Modifier& setMinWidth(float min);
    /// set minimum height (ignored if height is specified)
    Modifier& setMinHeight(float min);
    /// set maximum width (ignored if width is specified)
    Modifier& setMaxWidth(float max);
    /// set maximum height (ignored if height is specified)
    Modifier& setMaxHeight(float max);
    /// set width ratio (ignored if width is specified)
    Modifier& setWidthRatio(float ratio);
    /// set height ratio (ignored if height is specified)
    Modifier& setHeightRatio(float ratio);

    /// set layout priority (the higher the value, the higher the priority)
    Modifier& setLayoutPriority(float priority);

    /// set alignment
    Modifier& setAlignment(AlignmentType alignment);

    /// set padding
    Modifier& setPadding(EdgeType edge, float val);
    /// set border
    Modifier& setBorder(EdgeType edge, float val);
};

}    // namespace tears

#endif /* Modifier_hpp */
