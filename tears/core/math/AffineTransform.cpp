//
//  AffineTransform.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/15.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "AffineTransform.hpp"

namespace tears {

constexpr float PI = 3.141592653589793;

// default constructor
AffineTransform::AffineTransform() {
    setIdentity();
}

// destructor
AffineTransform::~AffineTransform() {}

// translate
AffineTransform AffineTransform::translate(const AffineTransform& matrix, Size offset) {
    Matrix translateMat = getIdentity();
    translateMat[0][2] = offset.width;
    translateMat[1][2] = offset.height;
    Matrix res = translateMat * matrix;
    return *(AffineTransform*)(&res);
}

// translate inplace
void AffineTransform::translate(Size offset) {
    Matrix res = translate(*this, offset);
    setMatrix(res);
}

// scale
AffineTransform AffineTransform::scale(const AffineTransform& matrix, Size factor) {
    Matrix scaleMat = getIdentity();
    scaleMat[0][0] = factor.width;
    scaleMat[1][1] = factor.height;
    Matrix res = scaleMat * matrix;
    return *(AffineTransform*)(&res);
}

// scale inplace
void AffineTransform::scale(Size factor) {
    Matrix res = scale(*this, factor);
    setMatrix(res);
}

// rotate
AffineTransform AffineTransform::rotate(const AffineTransform& matrix, float angle) {
    Matrix rotateMat = getIdentity();
    float radian = PI / 180.f * angle;
    float sine = sinf(radian);
    rotateMat[0][0] = rotateMat[1][1] = cosf(radian);
    rotateMat[0][1] = -sine;
    rotateMat[1][0] = sine;
    Matrix res = rotateMat * matrix;
    return *(AffineTransform*)(&res);
}

// rotate inplace
void AffineTransform::rotate(float angle) {
    Matrix res = rotate(*this, angle);
    setMatrix(res);
}

// reflect about the line y=0
AffineTransform AffineTransform::reflectX(const AffineTransform& matrix) {
    Matrix reflectXMat = getIdentity();
    reflectXMat[0][0] = -1.f;
    Matrix res = reflectXMat * matrix;
    return *(AffineTransform*)(&res);
}

// reflect about the line y=0 inplace
void AffineTransform::reflectX() {
    Matrix res = reflectX(*this);
    setMatrix(res);
}

// reflect about the line x=0
AffineTransform AffineTransform::reflectY(const AffineTransform& matrix) {
    Matrix reflectYMat = getIdentity();
    reflectYMat[1][1] = -1.f;
    Matrix res = reflectYMat * matrix;
    return *(AffineTransform*)(&res);
}

// reflect about the line x=0 inplace
void AffineTransform::reflectY() {
    Matrix res = reflectY(*this);
    setMatrix(res);
}

}    // namespace tears
