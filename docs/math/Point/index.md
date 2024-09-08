---
title: Point
description: a point in a 2D coordinates system 
generator: doxide
---


# Point

**struct Point**

a point in a 2D coordinates system

## Variables

| Name | Description |
| ---- | ----------- |
| [x](#x) | the x-coordinate of the point  |
| [y](#y) | the y-coordinate of the point  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | Copy assignment operator  |
| [operator=](#operator_u003d) | Move assignment operator  |
| [operator+](#operator_u002b) | Add points  |
| [operator+=](#operator_u002b_u003d) | Add points in-place  |
| [operator-](#operator_u002d) | Subtract points  |
| [operator-=](#operator_u002d_u003d) | Subtract points in-place  |
| [operator*](#operator_u002a) | Multiply vector by scalar  |
| [operator*=](#operator_u002a_u003d) | Multiply vector by scalar in-place  |
| [operator*](#operator_u002a) | Multiply points element-wise  |
| [operator*=](#operator_u002a_u003d) | Multiply points element-wise in-place  |
| [operator/](#operator_u002f) | Divide vector by scalar  |
| [operator/=](#operator_u002f_u003d) | Divide vector by scalar in-place  |
| [operator/](#operator_u002f) | Divide points element-wise  |
| [operator/=](#operator_u002f_u003d) | Divide points element-wise in-place  |
| [operator-](#operator_u002d) | Change sign  |

## Functions

| Name | Description |
| ---- | ----------- |
| [calculateEuclideanDistance](#calculateEuclideanDistance) | Calculate Euclidean distance  |
| [calculateManhattanDistance](#calculateManhattanDistance) | Calculate Manhattan distance  |
| [calculateChebyshevDistance](#calculateChebyshevDistance) | Calculate Chebyshev distance  |
| [Point](#Point) | Default constructor  |
| [Point](#Point) | Constructor  |
| [~Point](#_u007ePoint) | Destructor  |
| [Point](#Point) | Copy constructor  |
| [Point](#Point) | Move constructor  |
| [calculateLength](#calculateLength) | Calculate length  |
| [calculateSquaredLength](#calculateSquaredLength) | Calculate squared length  |
| [calculateDistance](#calculateDistance) | Calculate distance :material-location-enter: **Parameter** `mode` :    A type of distance (default: Euclidean)  |
| [calculateDotProduct](#calculateDotProduct) | Calculate dot product  |
| [calculateNormalVector](#calculateNormalVector) | Calculate normal vector  |
| [normalize](#normalize) | Normalize vector  |
| [applyTransform](#applyTransform) | apply transforms  |

## Variable Details

### x<a name="x"></a>

!!! variable "float x"

    the x-coordinate of the point

### y<a name="y"></a>

!!! variable "float y"

    the y-coordinate of the point

## Operator Details

### operator*<a name="operator_u002a"></a>

!!! function "Point operator&#42;(float rhs) const"

    Multiply vector by scalar

!!! function "Point operator&#42;(const Point&amp; rhs) const"

    Multiply points element-wise

### operator*=<a name="operator_u002a_u003d"></a>

!!! function "Point&amp; operator&#42;=(float rhs)"

    Multiply vector by scalar in-place

!!! function "Point&amp; operator&#42;=(const Point&amp; rhs)"

    Multiply points element-wise in-place

### operator+<a name="operator_u002b"></a>

!!! function "Point operator+(const Point&amp; rhs) const"

    Add points

### operator+=<a name="operator_u002b_u003d"></a>

!!! function "Point&amp; operator+=(const Point&amp; rhs)"

    Add points in-place

### operator-<a name="operator_u002d"></a>

!!! function "Point operator-(const Point&amp; rhs) const"

    Subtract points

!!! function "Point operator-() const"

    Change sign

### operator-=<a name="operator_u002d_u003d"></a>

!!! function "Point&amp; operator-=(const Point&amp; rhs)"

    Subtract points in-place

### operator/<a name="operator_u002f"></a>

!!! function "Point operator/(float rhs) const"

    Divide vector by scalar

!!! function "Point operator/(const Point&amp; rhs) const"

    Divide points element-wise

### operator/=<a name="operator_u002f_u003d"></a>

!!! function "Point&amp; operator/=(float rhs)"

    Divide vector by scalar in-place

!!! function "Point&amp; operator/=(const Point&amp; rhs)"

    Divide points element-wise in-place

### operator=<a name="operator_u003d"></a>

!!! function "Point&amp; operator=(const Point&amp; v)"

    Copy assignment operator

!!! function "Point&amp; operator=(Point&amp;&amp; v)"

    Move assignment operator

## Function Details

### Point<a name="Point"></a>

!!! function "Point()"

    Default constructor

!!! function "Point(float aX, float aY)"

    Constructor

!!! function "Point(const Point&amp; v)"

    Copy constructor

!!! function "Point(Point&amp;&amp; v)"

    Move constructor

### applyTransform<a name="applyTransform"></a>

!!! function "Point applyTransform(AffineTransform affine) const"

    apply transforms

### calculateChebyshevDistance<a name="calculateChebyshevDistance"></a>

!!! function "static float calculateChebyshevDistance(const Point&amp; p, const Point&amp; q)"

    Calculate Chebyshev distance

### calculateDistance<a name="calculateDistance"></a>

!!! function "static float calculateDistance(const Point&amp; p, const Point&amp; q, DistanceType mode = DistanceEuclidean)"

    Calculate distance
    :material-location-enter: **Parameter** `mode`
    :    A type of distance (default: Euclidean)

### calculateDotProduct<a name="calculateDotProduct"></a>

!!! function "float calculateDotProduct(const Point&amp; v) const"

    Calculate dot product

### calculateEuclideanDistance<a name="calculateEuclideanDistance"></a>

!!! function "static float calculateEuclideanDistance(const Point&amp; p, const Point&amp; q)"

    Calculate Euclidean distance

### calculateLength<a name="calculateLength"></a>

!!! function "float calculateLength() const"

    Calculate length

### calculateManhattanDistance<a name="calculateManhattanDistance"></a>

!!! function "static float calculateManhattanDistance(const Point&amp; p, const Point&amp; q)"

    Calculate Manhattan distance

### calculateNormalVector<a name="calculateNormalVector"></a>

!!! function "Point calculateNormalVector() const"

    Calculate normal vector

### calculateSquaredLength<a name="calculateSquaredLength"></a>

!!! function "float calculateSquaredLength() const"

    Calculate squared length

### normalize<a name="normalize"></a>

!!! function "Point normalize() const"

    Normalize vector

### ~Point<a name="_u007ePoint"></a>

!!! function "~Point()"

    Destructor
