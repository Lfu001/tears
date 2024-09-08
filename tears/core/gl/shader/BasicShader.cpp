//
//  BasicShader.cpp
//  tears
//
//  Created by Lfu001 on 2024/04/28.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <sstream>
#include "BasicShader.hpp"

namespace tears {

// default constructor
BasicShader::BasicShader() {}

// destructor
BasicShader::~BasicShader() {}

// load shader
void BasicShader::loadShader() {
    stringstream vs;
    vs << "uniform mat3 uMatrixMVP;"
       << "uniform mat3 uMatrixU;"
       << "attribute vec2 aPosition;"
       << "attribute vec4 aColor;"
       << "varying vec4 vColor;"
       << "void main() {"
       << "    gl_Position = vec4(vec3(aPosition, 1.0) * uMatrixMVP * uMatrixU, 1.0);"
       << "    vColor = aColor;"
       << "}";

    stringstream fs;
    fs << "precision highp float;"
       << "varying vec4 vColor;"
       << "void main() {"
       << "    gl_FragColor = vColor;"
       << "}";

    buildProgram(vs.str(), fs.str());
}

}    // namespace tears
