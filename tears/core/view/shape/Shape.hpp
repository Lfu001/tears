//
//  Shape.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include "gl/Color.hpp"
#include "view/base/View.hpp"

namespace tears {

class Texture;

/// a base class of all shapes
/// @ingroup shape
class Shape: public View {
protected:
    /// background color [0]=top-leading, [1]=bottom-leading, [2]=top-trailing, [3]=bottom-trailing
    Color backgroundColor[4] = {Color::ORANGE, Color::ORANGE, Color::ORANGE, Color::ORANGE};
    /// the standard deviation of the gaussian function used for blurring.
    int blurSigma = 0;

protected:
    /// get vertex shader source that supports color vertex
    const char* getVertexShaderSource() const;
    /// check if blurring is enabled
    bool needBlurring() const;
    /// prepare a blurred texture of the view background if blurring is enabled.
    unique_ptr<Texture> prepareBlurredTexture() const;

public:
    /// default constructor
    Shape();
    /// destructor
    virtual ~Shape();

public:
    Shape& setBackgroundColor(Color color, EdgeType edge = EdgeAll);
    /// set blur sigma
    /// @param sigma a standard deviation of the gaussian function. Must be larger than or equal to
    /// 0. 0 means no blurring.
    Shape& setBlurSigma(float sigma);
};

}    // namespace tears

#endif /* Shape_hpp */
