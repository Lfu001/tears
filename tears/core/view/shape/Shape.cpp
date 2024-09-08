//
//  Shape.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/16.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/BlendScope.hpp"
#include "gl/FramebufferScope.hpp"
#include "gl/Texture.hpp"
#include "gl/shader/BlurShader.hpp"
#include "gl/shader/ShaderController.hpp"
#include "gl/shader/ShaderScope.hpp"
#include "Shape.hpp"

namespace tears {

/// a minimum value of the blur sigma
constexpr float MIN_BLUR_SIGMA = 0;

// default constructor
Shape::Shape() {}

// destructor
Shape::~Shape() {}

// get vertex shader source that supports color vertex
const char* Shape::getVertexShaderSource() const {
    const char* src = "uniform mat3 uMatrixMVP;"
                      "uniform mat3 uMatrixU;"
                      "attribute vec2 aPosition;"
                      "attribute vec4 aColor;"
                      "varying vec4 vColor;"
                      "void main() {"
                      "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
                      "    vColor = aColor;"
                      "}";
    return src;
}

// check if blurring is enabled
bool Shape::needBlurring() const {
    bool isTransparent = backgroundColor[0].alpha < 255 || backgroundColor[1].alpha < 255
                         || backgroundColor[2].alpha < 255 || backgroundColor[3].alpha < 255;
    return blurSigma > 0 && isTransparent;
}

// create a texture for the blurred background
Texture* Shape::createBlurredTexture() {
    GLController* gl = GLController::getInstance();
    float screenScale = gl->getScreenScale();
    int width = (int)(getWidth() * screenScale);
    int height = (int)(getHeight() * screenScale);
    if (!textureBlurred || textureBlurred->getWidth() != width
        || textureBlurred->getHeight() != height) {
        textureBlurred = make_unique<Texture>(width, height);
    }
    return textureBlurred.get();
}

// prepare a blurred texture of the view background if blurring is enabled.
Texture* Shape::prepareBlurredTexture() {
    GLController* gl = GLController::getInstance();
    float screenScale = gl->getScreenScale();
    int width = (int)(getWidth() * screenScale);
    int height = (int)(getHeight() * screenScale);

    vector<Point> texCoordSrc = getTexCoord();
    Point texVertices[] = {
        Point(0.f, 0.f),
        Point(0.f, height),
        Point(width, 0.f),
        Point(width, height)};
    Texture* texSrc = gl->getScreenTexture();
    const Point* texCoord = texCoordSrc.data();
    Texture* texBlurred = createBlurredTexture();

    ShaderController* sc = ShaderController::getInstance();
    BlurShader* shader = (BlurShader*)sc->createShader(ShaderBlur);
    ShaderScope ss(shader);
    BlendScope bs(BlendEquationAdd, BlendOne, BlendZero);

    shader->drawBlur(blurSigma, texSrc, texCoord, Size(width, height), texBlurred, texVertices, 4);

    return texBlurred;
}

// set background color
Shape& Shape::setBackgroundColor(Color color, EdgeType edge /* = EdgeAll */) {
    switch (edge) {
        case EdgeAll:
            backgroundColor[0] = color;
            backgroundColor[1] = color;
            backgroundColor[2] = color;
            backgroundColor[3] = color;
            break;
        case EdgeTop:
            backgroundColor[0] = color;
            backgroundColor[2] = color;
            break;
        case EdgeBottom:
            backgroundColor[1] = color;
            backgroundColor[3] = color;
            break;
        case EdgeLeading:
            backgroundColor[0] = color;
            backgroundColor[1] = color;
            break;
        case EdgeTrailing:
            backgroundColor[2] = color;
            backgroundColor[3] = color;
            break;
        case EdgeTopLeading:
            backgroundColor[0] = color;
            break;
        case EdgeBottomLeading:
            backgroundColor[1] = color;
            break;
        case EdgeTopTrailing:
            backgroundColor[2] = color;
            break;
        case EdgeBottomTrailing:
            backgroundColor[3] = color;
            break;
        default:
            tears_assert(false);
    }
    return *this;
}

// set blur sigma
Shape& Shape::setBlurSigma(float sigma) {
    if (MIN_BLUR_SIGMA <= sigma) {    // if the specified sigma is in the correct range
        blurSigma = sigma;
    } else {
        tears_assert(false);
        // clamp to available range edge
        blurSigma = fmaxf(MIN_BLUR_SIGMA, sigma);
    }
    return *this;
}

}    // namespace tears
