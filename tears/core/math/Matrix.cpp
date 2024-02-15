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

// copy constructor
Matrix::Matrix(const Matrix& other) {
    setMatrix(other);
}

// copy assignment operator
void Matrix::operator=(const Matrix& other) {
    setMatrix(other);
}

// compute callback function for each element and assign it to result matrix
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

// compute callback function for each element and scalar, then assign it to result matrix
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

// set given matrix
void Matrix::setMatrix(const Matrix& matrix) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            elements[row][col] = matrix[row][col];
        }
    }
}

}    // namespace tears
