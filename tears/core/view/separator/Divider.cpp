//
//  Divider.cpp
//  tears
//
//  Created by Lfu001 on 2024/09/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/BlendScope.hpp"
#include "gl/MatrixStackScope.hpp"
#include "Divider.hpp"

namespace tears {

/// The width of the divider line.
constexpr float LINE_WIDTH = 1.f;
/// The padding of the divider line aspects.
constexpr float PADDING_ASPECT = 1.f;
/// The padding of the divider line edges.
constexpr float PADDING_EDGE = 4.f;

// constructor
Divider::Divider() {
    setAlignment(AlignmentCenter);
}

// destructor
Divider::~Divider() {}

/// A handler called before this view is layed out.
void Divider::viewWillLayout() {
    LayoutDirectionType direction = parent->getLayoutDirection();
    if (direction == LayoutDirectionVertical) {
        setHeight(LINE_WIDTH);
        setWidthRatio(1.f);
        setPadding(EdgeVertical, PADDING_ASPECT);
        setPadding(EdgeHorizontal, PADDING_EDGE);
    } else if (direction == LayoutDirectionHorizontal) {
        setWidth(LINE_WIDTH);
        setHeightRatio(1.f);
        setPadding(EdgeVertical, PADDING_EDGE);
        setPadding(EdgeHorizontal, PADDING_ASPECT);
    } else {
        tears_assert(false);
    }
}

// main drawing process
void Divider::drawMain() {
    LayoutDirectionType direction = parent->getLayoutDirection();
    Point vertices[4];
    if (direction == LayoutDirectionVertical) {
        vertices[0] = Point(0.f, 0.f);
        vertices[1] = Point(0.f, LINE_WIDTH);
        vertices[2] = Point(getWidth(), 0.f);
        vertices[3] = Point(getWidth(), LINE_WIDTH);
    } else if (direction == LayoutDirectionHorizontal) {
        vertices[0] = Point(0.f, 0.f);
        vertices[1] = Point(0.f, getHeight());
        vertices[2] = Point(LINE_WIDTH, 0.f);
        vertices[3] = Point(LINE_WIDTH, getHeight());
    } else {
        tears_assert(false);
        return;
    }

    MatrixStackScope mss;
    AffineTransform* top = mss.getTopMatrix();
    top->translate(Size(position.x, position.y));
    BlendScope bs(BlendEquationAdd, BlendSrcAlpha, BlendOneMinusSrcAlpha);
    GLController* gl = GLController::getInstance();
    gl->drawArrays(PrimitiveTriangleStrip, vertices, color, 4);
}

// Set the color of the divider.
Divider& Divider::setColor(Color aColor) {
    color[0] = aColor;
    color[1] = aColor;
    color[2] = aColor;
    color[3] = aColor;
    return *this;
}

// set offset x and y
Modifier& Divider::setOffset(float x, float y) {
    tears_assert(false);
    return *this;
}

// set offset x
Modifier& Divider::setOffsetX(float x) {
    tears_assert(false);
    return *this;
}

// set offset y
Modifier& Divider::setOffsetY(float y) {
    tears_assert(false);
    return *this;
}

// set size
Modifier& Divider::setSize(float width, float height) {
    tears_assert(false);
    return *this;
}

// set width
Modifier& Divider::setWidth(float width) {
    return Modifier::setWidth(width);
}

// set height
Modifier& Divider::setHeight(float height) {
    return Modifier::setHeight(height);
}

// set width range (ignored if width is specified)
Modifier& Divider::setWidthRange(float min, float max) {
    tears_assert(false);
    return *this;
}

// set height range (ignored if height is specified)
Modifier& Divider::setHeightRange(float min, float max) {
    tears_assert(false);
    return *this;
}

// set minimum width (ignored if width is specified)
Modifier& Divider::setMinWidth(float min) {
    tears_assert(false);
    return *this;
}

// set minimum height (ignored if height is specified)
Modifier& Divider::setMinHeight(float min) {
    tears_assert(false);
    return *this;
}

// set maximum width (ignored if width is specified)
Modifier& Divider::setMaxWidth(float max) {
    tears_assert(false);
    return *this;
}

// set maximum height (ignored if height is specified)
Modifier& Divider::setMaxHeight(float max) {
    tears_assert(false);
    return *this;
}

// set width ratio (ignored if width is specified)
Modifier& Divider::setWidthRatio(float ratio) {
    return Modifier::setWidthRatio(ratio);
}

// set height ratio (ignored if height is specified)
Modifier& Divider::setHeightRatio(float ratio) {
    return Modifier::setHeightRatio(ratio);
}

// set layout priority (the higher the value, the higher the priority)
Modifier& Divider::setLayoutPriority(float priority) {
    tears_assert(false);
    return *this;
}

// set alignment
Modifier& Divider::setAlignment(AlignmentType alignment) {
    return Modifier::setAlignment(alignment);
}

// set padding
Modifier& Divider::setPadding(EdgeType edge, float val) {
    return Modifier::setPadding(edge, val);
}

// set border
Modifier& Divider::setBorder(EdgeType edge, float val) {
    tears_assert(false);
    return *this;
}

}    // namespace tears
