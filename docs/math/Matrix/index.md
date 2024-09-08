---
title: Matrix
description: a 3x3 matrix 
generator: doxide
---


# Matrix

**class Matrix**

a 3x3 matrix

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | copy assignment operator  |
| [operator[]](#operator_u005b_u005d) | subscript operator (non-const)  |
| [operator[]](#operator_u005b_u005d) | subscript operator (const)  |
| [operator*](#operator_u002a) | multiply matrices  |
| [operator+](#operator_u002b) | add scalar  |
| [operator-](#operator_u002d) | subtract scalar  |
| [operator*](#operator_u002a) | multiply by scalar  |
| [operator/](#operator_u002f) | divide by scalar  |
| [operator==](#operator_u003d_u003d) | equal operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [computeForEach](#computeForEach) | elements of  the matrix compute callback function for each element then assign it to result matrix `result[i][j] = callback(lhs[i][j], rhs[i][j])` :material-location-enter: **Parameter** `lhs` :    left operand :material-location-enter: **Parameter** `rhs` :    right operand :material-location-enter: **Parameter** `callback` :    a function that computes a value from lhs and rhs  |
| [computeForEach](#computeForEach) | compute callback function for each element and scalar, then assign it to result matrix `result[i][j] = callback(lhs[i][j], scalar)` :material-location-enter: **Parameter** `lhs` :    left operand :material-location-enter: **Parameter** `scalar` :    right operand :material-location-enter: **Parameter** `callback` :    a function that computes a value from lhs and rhs  |
| [Matrix](#Matrix) | default constructor  |
| [Matrix](#Matrix) | constructor from arrays :material-location-enter: **Parameter** `matrix` :    3x3 arrays of arrays  |
| [~Matrix](#_u007eMatrix) | destructor  |
| [Matrix](#Matrix) | copy constructor  |
| [add](#add) | add element wise  |
| [subtract](#subtract) | subtract element wise  |
| [multiply](#multiply) | multiply element wise  |
| [divide](#divide) | divide element wise  |
| [getIdentity](#getIdentity) | get identity matrix  |
| [setIdentity](#setIdentity) | set identity matrix  |
| [setMatrix](#setMatrix) | set given matrix  |
| [flatten](#flatten) | convert matrix to 1D array  |

## Operator Details

### operator*<a name="operator_u002a"></a>

!!! function "Matrix operator&#42;(const Matrix&amp; rhs) const"

    multiply matrices

!!! function "Matrix operator&#42;(float scalar) const"

    multiply by scalar

### operator+<a name="operator_u002b"></a>

!!! function "Matrix operator+(float scalar) const"

    add scalar

### operator-<a name="operator_u002d"></a>

!!! function "Matrix operator-(float scalar) const"

    subtract scalar

### operator/<a name="operator_u002f"></a>

!!! function "Matrix operator/(float scalar) const"

    divide by scalar

### operator=<a name="operator_u003d"></a>

!!! function "void operator=(const Matrix&amp; other)"

    copy assignment operator

### operator==<a name="operator_u003d_u003d"></a>

!!! function "bool operator==(const Matrix&amp; rhs) const"

    equal operator

### operator[]<a name="operator_u005b_u005d"></a>

!!! function "float&#42; operator[](int index)"

    subscript operator (non-const)

!!! function "const float&#42; operator[](int index) const"

    subscript operator (const)

## Function Details

### Matrix<a name="Matrix"></a>

!!! function "Matrix()"

    default constructor

!!! function "explicit Matrix(float matrix[3][3])"

    constructor from arrays
    :material-location-enter: **Parameter** `matrix`
    :    3x3 arrays of arrays

!!! function "Matrix(const Matrix&amp; other)"

    copy constructor

### add<a name="add"></a>

!!! function "Matrix add(const Matrix&amp; rhs) const"

    add element wise

### computeForEach<a name="computeForEach"></a>

!!! function "Matrix computeForEach( const Matrix&amp; lhs, const Matrix&amp; rhs, function&lt;float(float, float)&gt; callback) const"

    elements of  the matrix
    compute callback function for each element then assign it to result matrix
    `result[i][j] = callback(lhs[i][j], rhs[i][j])`
    :material-location-enter: **Parameter** `lhs`
    :    left operand
    :material-location-enter: **Parameter** `rhs`
    :    right operand
    :material-location-enter: **Parameter** `callback`
    :    a function that computes a value from lhs and rhs

!!! function "Matrix computeForEach(const Matrix&amp; lhs, float scalar, function&lt;float(float, float)&gt; callback) const"

    compute callback function for each element and scalar, then assign it to result matrix
    `result[i][j] = callback(lhs[i][j], scalar)`
    :material-location-enter: **Parameter** `lhs`
    :    left operand
    :material-location-enter: **Parameter** `scalar`
    :    right operand
    :material-location-enter: **Parameter** `callback`
    :    a function that computes a value from lhs and rhs

### divide<a name="divide"></a>

!!! function "Matrix divide(const Matrix&amp; rhs) const"

    divide element wise

### flatten<a name="flatten"></a>

!!! function "unique_ptr&lt;float[]&gt; flatten() const"

    convert matrix to 1D array

### getIdentity<a name="getIdentity"></a>

!!! function "static Matrix getIdentity()"

    get identity matrix

### multiply<a name="multiply"></a>

!!! function "Matrix multiply(const Matrix&amp; rhs) const"

    multiply element wise

### setIdentity<a name="setIdentity"></a>

!!! function "void setIdentity()"

    set identity matrix

### setMatrix<a name="setMatrix"></a>

!!! function "void setMatrix(const Matrix&amp; matrix)"

    set given matrix

### subtract<a name="subtract"></a>

!!! function "Matrix subtract(const Matrix&amp; rhs) const"

    subtract element wise

### ~Matrix<a name="_u007eMatrix"></a>

!!! function "virtual ~Matrix()"

    destructor
