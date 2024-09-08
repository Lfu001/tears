//
//  Spacer.hpp
//  tears
//
//  Created by Lfu001 on 2024/09/08.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Spacer_hpp
#define Spacer_hpp

#include "view/base/View.hpp"

namespace tears {

/// A flexible space that expands along the major axis of its containing layout.
/// @ingroup separator
class Spacer: public View {
private:
    /// set offset x and y
    virtual Modifier& setOffset(float x, float y) override;
    /// set offset x
    virtual Modifier& setOffsetX(float x) override;
    /// set offset y
    virtual Modifier& setOffsetY(float y) override;

    /// set size
    virtual Modifier& setSize(float width, float height) override;
    /// set width
    virtual Modifier& setWidth(float width) override;
    /// set height
    virtual Modifier& setHeight(float height) override;
    /// set width range (ignored if width is specified)
    virtual Modifier& setWidthRange(float min, float max) override;
    /// set height range (ignored if height is specified)
    virtual Modifier& setHeightRange(float min, float max) override;
    /// set minimum width (ignored if width is specified)
    virtual Modifier& setMinWidth(float min) override;
    /// set minimum height (ignored if height is specified)
    virtual Modifier& setMinHeight(float min) override;
    /// set maximum width (ignored if width is specified)
    virtual Modifier& setMaxWidth(float max) override;
    /// set maximum height (ignored if height is specified)
    virtual Modifier& setMaxHeight(float max) override;
    /// set width ratio (ignored if width is specified)
    virtual Modifier& setWidthRatio(float ratio) override;
    /// set height ratio (ignored if height is specified)
    virtual Modifier& setHeightRatio(float ratio) override;

    /// set layout priority (the higher the value, the higher the priority)
    virtual Modifier& setLayoutPriority(float priority) override;

    /// set alignment
    virtual Modifier& setAlignment(AlignmentType alignment) override;

    /// set padding
    virtual Modifier& setPadding(EdgeType edge, float val) override;
    /// set border
    virtual Modifier& setBorder(EdgeType edge, float val) override;

public:
    /// constructor
    Spacer();
    /// destructor
    virtual ~Spacer();
};

}    // namespace tears

#endif /* Spacer_hpp */
