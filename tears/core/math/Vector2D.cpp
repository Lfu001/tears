//
//  Vector2D.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#include <cassert>
#include <cmath>
#include "Vector2D.hpp"

namespace tears {

using namespace std;

// Default constructor
Vector2D::Vector2D() {
    x = 0.f;
    y = 0.f;
}

// Constructor
Vector2D::Vector2D(float aX, float aY) {
    x = aX;
    y = aY;
}

// Destructor
Vector2D::~Vector2D() {}

// Copy constructor
Vector2D::Vector2D(const Vector2D& v) {
    x = v.x;
    y = v.y;
}

// Copy assignment operator
Vector2D& Vector2D::operator=(const Vector2D& v) {
    x = v.x;
    y = v.y;
    return *this;
}

// Move constructor
Vector2D::Vector2D(Vector2D&& v) {
    x = v.x;
    y = v.y;
}

// Move assignment operator
Vector2D& Vector2D::operator=(Vector2D&& v) {
    x = v.x;
    y = v.y;
    return *this;
}

// Add vectors
Vector2D Vector2D::operator+(const Vector2D& rhs) const {
    return Vector2D(x + rhs.x, y + rhs.y);
}

// Add vectors in-place
Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

// Subtract vectors
Vector2D Vector2D::operator-(const Vector2D& rhs) const {
    return Vector2D(x - rhs.x, y - rhs.y);
}

// Subtract vectors in-place
Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

// Multiply vector by scalar
Vector2D Vector2D::operator*(float rhs) const {
    return Vector2D(x * rhs, y * rhs);
}

// Multiply vector by scalar in-place
Vector2D& Vector2D::operator*=(float rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

// Multiply vectors element-wise
Vector2D Vector2D::operator*(const Vector2D& rhs) const {
    return Vector2D(x * rhs.x, y * rhs.y);
}

// Multiply vectors element-wise in-place
Vector2D& Vector2D::operator*=(const Vector2D& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

// Divide vector by scalar
Vector2D Vector2D::operator/(float rhs) const {
    if (rhs == 0.f) {    // zero division
        assert(false);
        return Vector2D();
    }
    return Vector2D(x / rhs, y / rhs);
}

// Divide vector by scalar in-place
Vector2D& Vector2D::operator/=(float rhs) {
    if (rhs == 0.f) {    // zero division
        assert(false);
        return *this;
    }
    x /= rhs;
    y /= rhs;
    return *this;
}

// Divide vectors element-wise
Vector2D Vector2D::operator/(const Vector2D& rhs) const {
    if (rhs.x == 0.f || rhs.y == 0.f) {    // zero division
        assert(false);
        return Vector2D();
    }
    return Vector2D(x / rhs.x, y / rhs.y);
}

// Divide vectors element-wise in-place
Vector2D& Vector2D::operator/=(const Vector2D& rhs) {
    if (rhs.x == 0.f || rhs.y == 0.f) {    // zero division
        assert(false);
        return *this;
    }
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

// Change sign
Vector2D Vector2D::operator-() const {
    return Vector2D(-x, -y);
}

// Calculate length
float Vector2D::calculateLength() const {
    return sqrtf(x * x + y * y);
}

// Calculate squared length
float Vector2D::calculateSquaredLength() const {
    return x * x + y * y;
}

// Calculate distance
float Vector2D::calculateDistance(
    const Vector2D& p,
    const Vector2D& q,
    DistanceType mode /* = DistanceEuclidian */) {
    switch (mode) {
        case DistanceEuclidian:
            return calculateEuclidianDistance(p, q);
        case DistanceManhattan:
            return calculateManhattanDistance(p, q);
        case DistanceChebyshev:
            return calculateChebyshevDistance(p, q);
        default:
            assert(false);
            return 0.f;
    }
}

// Calculate Euclidian distance
float Vector2D::calculateEuclidianDistance(const Vector2D& p, const Vector2D& q) {
    float a = q.x - p.x;
    float b = q.y - p.y;
    return sqrtf(a * a + b * b);
}

// Calculate Manhattan distance
float Vector2D::calculateManhattanDistance(const Vector2D& p, const Vector2D& q) {
    return fabsf(q.x - p.x) + fabsf(q.y - p.y);
}

// Calculate Chebyshev distance
float Vector2D::calculateChebyshevDistance(const Vector2D& p, const Vector2D& q) {
    return fmaxf(fabsf(q.x - p.x), fabsf(q.y - p.y));
}

// Calculate dot product
float Vector2D::calculateDotProduct(const Vector2D& v) const {
    return x * v.x + y * v.y;
}

// Calculate normal vector
Vector2D Vector2D::calculateNormalVector() const {
    return Vector2D(y, -x);
}

// Normalize vector
Vector2D Vector2D::normalize() const {
    float length = calculateLength();
    if (length == 0.f) {    // zero division
        assert(false);
        return Vector2D();
    }
    return *this / length;
}

}    // namespace tears
