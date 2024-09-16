//
//  Divider.hpp
//  tears
//
//  Created by Lfu001 on 2024/09/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Divider_hpp
#define Divider_hpp

#include "gl/Color.hpp"
#include "view/base/View.hpp"

namespace tears {

/// A visual element that can be used to separate other content.
/// @ingroup separator
class Divider: public View {
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

protected:
    /// A color of the divider. The default value is `Color::GRAY`.
    Color color[4] = {Color::GRAY, Color::GRAY, Color::GRAY, Color::GRAY};

protected:
    /// A handler called before this view is layed out.
    virtual void viewWillLayout() override;
    /// main drawing process
    virtual void drawMain() override;

public:
    /// constructor
    Divider();
    /// destructor
    ~Divider();

public:
    /// Set the color of the divider.
    Divider& setColor(Color aColor);
};

}    // namespace tears

#endif /* Divider_hpp */
