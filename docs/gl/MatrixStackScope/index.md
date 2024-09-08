---
title: MatrixStackScope
description: a scope class that manages matrix stack 
generator: doxide
---


# MatrixStackScope

**class MatrixStackScope**

a scope class that manages matrix stack

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | copy assignment operator  |
| [operator=](#operator_u003d) | move assignment operator  |
| [operator new](#operatornew) | new operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [MatrixStackScope](#MatrixStackScope) | copy constructor  |
| [MatrixStackScope](#MatrixStackScope) | move constructor  |
| [MatrixStackScope](#MatrixStackScope) | default constructor  |
| [~MatrixStackScope](#_u007eMatrixStackScope) | destructor  |
| [getTopMatrix](#getTopMatrix) | get the top matrix of the matrix stack  |

## Operator Details

### operator new<a name="operatornew"></a>

!!! function "void&#42; operator new(size_t size) = delete"

    new operator

### operator=<a name="operator_u003d"></a>

!!! function "MatrixStackScope&amp; operator=(const MatrixStackScope&amp; other) = delete"

    copy assignment operator

!!! function "MatrixStackScope&amp; operator=(MatrixStackScope&amp;&amp; other) = delete"

    move assignment operator

## Function Details

### MatrixStackScope<a name="MatrixStackScope"></a>

!!! function "MatrixStackScope(const MatrixStackScope&amp; other) = delete"

    copy constructor

!!! function "MatrixStackScope(MatrixStackScope&amp;&amp; other) = delete"

    move constructor

!!! function "MatrixStackScope()"

    default constructor

### getTopMatrix<a name="getTopMatrix"></a>

!!! function "AffineTransform&#42; getTopMatrix() const"

    get the top matrix of the matrix stack

### ~MatrixStackScope<a name="_u007eMatrixStackScope"></a>

!!! function "virtual ~MatrixStackScope()"

    destructor
