//
//  Matrix.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "utils/DebugUtil.hpp"
#include "Matrix.hpp"

namespace tears {

constexpr float PI = 3.141592653589793;

// default constructor
Matrix::Matrix() {}

/// constructor from arrays
Matrix::Matrix(float matrix[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            elements[row][col] = matrix[row][col];
        }
    }
}

// destructor
Matrix::~Matrix() {}

/// compute callback function for each element and assign it to result matrix
Matrix Matrix::computeForEach(
    const Matrix& lhs,
    const Matrix& rhs,
    function<float(float, float)> callback) const {
    Matrix res;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            res[row][col] = callback(lhs[row][col], rhs[row][col]);
        }
    }
    return res;
}

/// compute callback function for each element and scalar, then assign it to result matrix
Matrix Matrix::computeForEach(
    const Matrix& lhs,
    float scalar,
    function<float(float, float)> callback) const {
    Matrix res;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            res[row][col] = callback(lhs[row][col], scalar);
        }
    }
    return res;
}

// multiply
Matrix Matrix::operator*(const Matrix& rhs) const {
    Matrix res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float s = 0.f;
            for (int k = 0; k < 3; k++) {
                s += elements[i][k] * rhs[k][j];
            }
            res[i][j] = s;
        }
    }
    return res;
}

// add element wise
Matrix Matrix::add(const Matrix& rhs) const {
    return computeForEach(*this, rhs, [](float left, float right) {
        return left + right;
    });
}

// subtract element wise
Matrix Matrix::subtract(const Matrix& rhs) const {
    return computeForEach(*this, rhs, [](float left, float right) {
        return left - right;
    });
}

// multiply element wise
Matrix Matrix::multiply(const Matrix& rhs) const {
    return computeForEach(*this, rhs, [](float left, float right) {
        return left * right;
    });
}

// divide element wise
Matrix Matrix::divide(const Matrix& rhs) const {
    return computeForEach(*this, rhs, [](float left, float right) {
        if (right == 0.f) {    /// zero division
            tears_assert(false);
            return (left >= 0.f) ? numeric_limits<float>::max() : numeric_limits<float>::lowest();
        }
        return left / right;
    });
}

// add scalar
Matrix Matrix::operator+(float scalar) const {
    return computeForEach(*this, scalar, [](float left, float right) {
        return left + right;
    });
}

// subtract scalar
Matrix Matrix::operator-(float scalar) const {
    return computeForEach(*this, scalar, [](float left, float right) {
        return left - right;
    });
}

// multiply by scalar
Matrix Matrix::operator*(float scalar) const {
    return computeForEach(*this, scalar, [](float left, float right) {
        return left * right;
    });
}

// divide by scalar
Matrix Matrix::operator/(float scalar) const {
    return computeForEach(*this, scalar, [](float left, float right) {
        if (right == 0.f) {    /// zero division
            tears_assert(false);
            return (left >= 0.f) ? numeric_limits<float>::max() : numeric_limits<float>::lowest();
        }
        return left / right;
    });
}

// equal operator
bool Matrix::operator==(const Matrix& rhs) const {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (elements[row][col] != rhs[row][col]) {
                return false;
            }
        }
    }
    return true;
}

// get identity matrix
Matrix Matrix::getIdentity() {
    Matrix res;
    for (int i = 0; i < 3; i++) {
        res[i][i] = 1.f;
    }
    return res;
}

// set identity matrix
void Matrix::setIdentity() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                elements[i][j] = 1.f;
            } else {
                elements[i][j] = 0.f;
            }
        }
    }
}

// translate
Matrix Matrix::translate(const Matrix& matrix, Vector2D offset) {
    Matrix translateMat = getIdentity();
    translateMat[0][2] = offset.x;
    translateMat[1][2] = offset.y;
    return translateMat * matrix;
}

// translate inplace
void Matrix::translate(Vector2D offset) {
    Matrix res = translate(*this, offset);
    *this = res;
}

// scale
Matrix Matrix::scale(const Matrix& matrix, Vector2D factor) {
    Matrix scaleMat = getIdentity();
    scaleMat[0][0] = factor.x;
    scaleMat[1][1] = factor.y;
    return scaleMat * matrix;
}

// scale inplace
void Matrix::scale(Vector2D factor) {
    Matrix res = scale(*this, factor);
    *this = res;
}

/// rotate
Matrix Matrix::rotate(const Matrix& matrix, float angle) {
    Matrix rotateMat = getIdentity();
    float radian = PI / 180.f * angle;
    float sine = sinf(radian);
    rotateMat[0][0] = rotateMat[1][1] = cosf(radian);
    rotateMat[0][1] = -sine;
    rotateMat[1][0] = sine;
    return rotateMat * matrix;
}

// rotate inplace
void Matrix::rotate(float angle) {
    Matrix res = rotate(*this, angle);
    *this = res;
}

}    // namespace tears
