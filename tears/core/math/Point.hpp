//
//  Point.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

namespace tears {

/// A type of distance
/// @ingroup math
enum DistanceType {
    /// Euclidean distance
    DistanceEuclidean,
    /// Manhattan distance
    DistanceManhattan,
    /// Chebyshev distance
    DistanceChebyshev,
};

class AffineTransform;

/// a point in a 2D coordinates system
/// @ingroup math
struct Point {
protected:
    /// Calculate Euclidean distance
    static float calculateEuclideanDistance(const Point& p, const Point& q);
    /// Calculate Manhattan distance
    static float calculateManhattanDistance(const Point& p, const Point& q);
    /// Calculate Chebyshev distance
    static float calculateChebyshevDistance(const Point& p, const Point& q);

public:
    /// the x-coordinate of the point
    float x;
    /// the y-coordinate of the point
    float y;

public:
    /// Default constructor
    Point();
    /// Constructor
    Point(float aX, float aY);
    /// Destructor
    ~Point();
    /// Copy constructor
    Point(const Point& v);
    /// Copy assignment operator
    Point& operator=(const Point& v);
    /// Move constructor
    Point(Point&& v);
    /// Move assignment operator
    Point& operator=(Point&& v);

public:
    /// Add points
    Point operator+(const Point& rhs) const;
    /// Add points in-place
    Point& operator+=(const Point& rhs);
    /// Subtract points
    Point operator-(const Point& rhs) const;
    /// Subtract points in-place
    Point& operator-=(const Point& rhs);
    /// Multiply vector by scalar
    Point operator*(float rhs) const;
    /// Multiply vector by scalar in-place
    Point& operator*=(float rhs);
    /// Multiply points element-wise
    Point operator*(const Point& rhs) const;
    /// Multiply points element-wise in-place
    Point& operator*=(const Point& rhs);
    /// Divide vector by scalar
    Point operator/(float rhs) const;
    /// Divide vector by scalar in-place
    Point& operator/=(float rhs);
    /// Divide points element-wise
    Point operator/(const Point& rhs) const;
    /// Divide points element-wise in-place
    Point& operator/=(const Point& rhs);
    /// Change sign
    Point operator-() const;

public:
    /// Calculate length
    float calculateLength() const;
    /// Calculate squared length
    float calculateSquaredLength() const;
    /// Calculate distance
    /// @param mode A type of distance (default: Euclidean)
    static float
        calculateDistance(const Point& p, const Point& q, DistanceType mode = DistanceEuclidean);
    /// Calculate dot product
    float calculateDotProduct(const Point& v) const;
    /// Calculate normal vector
    Point calculateNormalVector() const;
    /// Normalize vector
    Point normalize() const;

    /// apply transforms
    Point applyTransform(AffineTransform affine) const;
};

static_assert(sizeof(Point) == sizeof(float) * 2);

}    // namespace tears

#endif /* Point_hpp */
