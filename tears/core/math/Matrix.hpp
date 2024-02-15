//
//  Matrix.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <functional>
#include "math/Size.hpp"

namespace tears {

using namespace std;

/// a 3x3 matrix
class Matrix {
protected:
    /// elements of  the matrix
    float elements[3][3] = {};

protected:
    /// compute callback function for each element then assign it to result matrix
    /// `result[i][j] = callback(lhs[i][j], rhs[i][j])`
    /// @param lhs left operand
    /// @param rhs right operand
    /// @param callback a function that computes a value from lhs and rhs
    Matrix computeForEach(
        const Matrix& lhs,
        const Matrix& rhs,
        function<float(float, float)> callback) const;
    /// compute callback function for each element and scalar, then assign it to result matrix
    /// `result[i][j] = callback(lhs[i][j], scalar)`
    /// @param lhs left operand
    /// @param scalar right operand
    /// @param callback a function that computes a value from lhs and rhs
    Matrix computeForEach(const Matrix& lhs, float scalar, function<float(float, float)> callback)
        const;

public:
    /// default constructor
    Matrix();
    /// constructor from arrays
    /// @param matrix 3x3 arrays of arrays
    explicit Matrix(float matrix[3][3]);
    /// destructor
    virtual ~Matrix();
    /// copy constructor
    Matrix(const Matrix& other);
    /// copy assignment operator
    void operator=(const Matrix& other);

public:
    /// subscript operator (non-const)
    float* operator[](int index) { return elements[index]; }
    /// subscript operator (const)
    const float* operator[](int index) const { return elements[index]; }
    /// multiply matrices
    Matrix operator*(const Matrix& rhs) const;
    /// add element wise
    Matrix add(const Matrix& rhs) const;
    /// subtract element wise
    Matrix subtract(const Matrix& rhs) const;
    /// multiply element wise
    Matrix multiply(const Matrix& rhs) const;
    /// divide element wise
    Matrix divide(const Matrix& rhs) const;
    /// add scalar
    Matrix operator+(float scalar) const;
    /// subtract scalar
    Matrix operator-(float scalar) const;
    /// multiply by scalar
    Matrix operator*(float scalar) const;
    /// divide by scalar
    Matrix operator/(float scalar) const;
    /// equal operator
    bool operator==(const Matrix& rhs) const;

    /// get identity matrix
    static Matrix getIdentity();
    /// set identity matrix
    void setIdentity();
    /// set given matrix
    void setMatrix(const Matrix& matrix);
};

}    // namespace tears

#endif /* Matrix_hpp */
