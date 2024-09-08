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
    virtual Modifier& setOffset(float x, float y);
    /// set offset x
    virtual Modifier& setOffsetX(float x);
    /// set offset y
    virtual Modifier& setOffsetY(float y);

    /// set size
    virtual Modifier& setSize(float width, float height);
    /// set width
    virtual Modifier& setWidth(float width);
    /// set height
    virtual Modifier& setHeight(float height);
    /// set width range (ignored if width is specified)
    virtual Modifier& setWidthRange(float min, float max);
    /// set height range (ignored if height is specified)
    virtual Modifier& setHeightRange(float min, float max);
    /// set minimum width (ignored if width is specified)
    virtual Modifier& setMinWidth(float min);
    /// set minimum height (ignored if height is specified)
    virtual Modifier& setMinHeight(float min);
    /// set maximum width (ignored if width is specified)
    virtual Modifier& setMaxWidth(float max);
    /// set maximum height (ignored if height is specified)
    virtual Modifier& setMaxHeight(float max);
    /// set width ratio (ignored if width is specified)
    virtual Modifier& setWidthRatio(float ratio);
    /// set height ratio (ignored if height is specified)
    virtual Modifier& setHeightRatio(float ratio);

    /// set layout priority (the higher the value, the higher the priority)
    virtual Modifier& setLayoutPriority(float priority);

    /// set alignment
    virtual Modifier& setAlignment(AlignmentType alignment);

    /// set padding
    virtual Modifier& setPadding(EdgeType edge, float val);
    /// set border
    virtual Modifier& setBorder(EdgeType edge, float val);
};

}    // namespace tears

#endif /* Modifier_hpp */
