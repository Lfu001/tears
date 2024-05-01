//
//  CopyShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/04/30.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "gl/shader/ShaderScope.hpp"
#include "CopyShader.hpp"

namespace tears {

// default constructor
CopyShader::CopyShader() {}

// destructor
CopyShader::~CopyShader() {}

// load shader
void CopyShader::loadShader() {
    stringstream vs;
    vs << "attribute vec2 aPosition;"
       << "attribute vec2 aTexCoord;"
       << "varying vec2 vTexCoord;"
       << "uniform mat3 uMatrixMVP;"
       << "uniform mat3 uMatrixU;"
       << "void main() {"
       << "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
       << "    vTexCoord = aTexCoord;"
       << "}";

    stringstream fs;
    fs << "precision highp float;"
       << "uniform sampler2D uTexture;"
       << "varying vec2 vTexCoord;"
       << "void main(void){"
       << "    gl_FragColor = texture2D(uTexture, vTexCoord);"
       << "}";

    buildProgram(vs.str(), fs.str());
}

// draw copy
void CopyShader::drawCopy(Point vertices[], int count) const {
    ShaderScope ss(this);

    const Point* texCoord = Texture::DEFAULT_TEXTURE_COORD;
    bindAttributePoints("aTexCoord", texCoord);
    bindUniformTexture("uTexture", 0);

    GLController* gl = GLController::getInstance();
    gl->drawArrays(PrimitiveTriangleStrip, vertices, count);
}

}    // namespace tears
