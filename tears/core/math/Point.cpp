//
//  Point.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#include <cassert>
#include <cmath>
#include "math/AffineTransform.hpp"
#include "Point.hpp"

namespace tears {

using namespace std;

// Default constructor
Point::Point() {
    x = 0.f;
    y = 0.f;
}

// Constructor
Point::Point(float aX, float aY) {
    x = aX;
    y = aY;
}

// Destructor
Point::~Point() {}

// Copy constructor
Point::Point(const Point& v) {
    x = v.x;
    y = v.y;
}

// Copy assignment operator
Point& Point::operator=(const Point& v) {
    x = v.x;
    y = v.y;
    return *this;
}

// Move constructor
Point::Point(Point&& v) {
    x = v.x;
    y = v.y;
}

// Move assignment operator
Point& Point::operator=(Point&& v) {
    x = v.x;
    y = v.y;
    return *this;
}

// Add vectors
Point Point::operator+(const Point& rhs) const {
    return Point(x + rhs.x, y + rhs.y);
}

// Add vectors in-place
Point& Point::operator+=(const Point& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

// Subtract vectors
Point Point::operator-(const Point& rhs) const {
    return Point(x - rhs.x, y - rhs.y);
}

// Subtract vectors in-place
Point& Point::operator-=(const Point& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

// Multiply vector by scalar
Point Point::operator*(float rhs) const {
    return Point(x * rhs, y * rhs);
}

// Multiply vector by scalar in-place
Point& Point::operator*=(float rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

// Multiply vectors element-wise
Point Point::operator*(const Point& rhs) const {
    return Point(x * rhs.x, y * rhs.y);
}

// Multiply vectors element-wise in-place
Point& Point::operator*=(const Point& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

// Divide vector by scalar
Point Point::operator/(float rhs) const {
    if (rhs == 0.f) {    // zero division
        assert(false);
        return Point();
    }
    return Point(x / rhs, y / rhs);
}

// Divide vector by scalar in-place
Point& Point::operator/=(float rhs) {
    if (rhs == 0.f) {    // zero division
        assert(false);
        return *this;
    }
    x /= rhs;
    y /= rhs;
    return *this;
}

// Divide vectors element-wise
Point Point::operator/(const Point& rhs) const {
    if (rhs.x == 0.f || rhs.y == 0.f) {    // zero division
        assert(false);
        return Point();
    }
    return Point(x / rhs.x, y / rhs.y);
}

// Divide vectors element-wise in-place
Point& Point::operator/=(const Point& rhs) {
    if (rhs.x == 0.f || rhs.y == 0.f) {    // zero division
        assert(false);
        return *this;
    }
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

// Change sign
Point Point::operator-() const {
    return Point(-x, -y);
}

// Calculate length
float Point::calculateLength() const {
    return sqrtf(x * x + y * y);
}

// Calculate squared length
float Point::calculateSquaredLength() const {
    return x * x + y * y;
}

// Calculate distance
float Point::calculateDistance(
    const Point& p,
    const Point& q,
    DistanceType mode /* = DistanceEuclidean */) {
    switch (mode) {
        case DistanceEuclidean:
            return calculateEuclideanDistance(p, q);
        case DistanceManhattan:
            return calculateManhattanDistance(p, q);
        case DistanceChebyshev:
            return calculateChebyshevDistance(p, q);
        default:
            assert(false);
            return 0.f;
    }
}

// Calculate Euclidean distance
float Point::calculateEuclideanDistance(const Point& p, const Point& q) {
    float a = q.x - p.x;
    float b = q.y - p.y;
    return sqrtf(a * a + b * b);
}

// Calculate Manhattan distance
float Point::calculateManhattanDistance(const Point& p, const Point& q) {
    return fabsf(q.x - p.x) + fabsf(q.y - p.y);
}

// Calculate Chebyshev distance
float Point::calculateChebyshevDistance(const Point& p, const Point& q) {
    return fmaxf(fabsf(q.x - p.x), fabsf(q.y - p.y));
}

// Calculate dot product
float Point::calculateDotProduct(const Point& v) const {
    return x * v.x + y * v.y;
}

// Calculate normal vector
Point Point::calculateNormalVector() const {
    return Point(y, -x);
}

// Normalize vector
Point Point::normalize() const {
    float length = calculateLength();
    if (length == 0.f) {    // zero division
        assert(false);
        return Point();
    }
    return *this / length;
}

// apply transforms
Point Point::applyTransform(AffineTransform affine) const {
    float ox = affine[0][0] * x + affine[0][1] * y + affine[0][2];
    float oy = affine[1][0] * x + affine[1][1] * y + affine[1][2];
    return Point(ox, oy);
}

}    // namespace tears
