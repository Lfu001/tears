//
//  Vector2D.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

namespace tears {

/// A type of distance
enum DistanceType {
    /// Euclidian distance
    DistanceEuclidian,
    /// Manhattan distance
    DistanceManhattan,
    /// Chebyshev distance
    DistanceChebyshev,
};

/// A 2D vector representing coordinates or rectangle size
class Vector2D {
protected:
    union {
        /// A x-coordinate for vectors
        float x;
        /// A width for rectangles
        float width;
    };
    union {
        /// A y-coordinate for vectors
        float y;
        /// A height for rectangles
        float height;
    };

protected:
    /// Calculate Euclidian distance
    static float calculateEuclidianDistance(const Vector2D& p, const Vector2D& q);
    /// Calculate Manhattan distance
    static float calculateManhattanDistance(const Vector2D& p, const Vector2D& q);
    /// Calculate Chebyshev distance
    static float calculateChebyshevDistance(const Vector2D& p, const Vector2D& q);

public:
    /// Default constructor
    Vector2D();
    /// Constructor
    Vector2D(float aX, float aY);
    /// Destructor
    virtual ~Vector2D();
    /// Copy constructor
    Vector2D(const Vector2D& v);
    /// Copy assignment operator
    Vector2D& operator=(const Vector2D& v);
    /// Move constructor
    Vector2D(Vector2D&& v);
    /// Move assignment operator
    Vector2D& operator=(Vector2D&& v);

public:
    /// Get x-coordinate
    float getX() const { return x; }
    /// Set x-coordinate
    void setX(float aX) { x = aX; }
    /// Get y-coordinate
    float getY() const { return y; }
    /// Set y-coordinate
    void setY(float aY) { y = aY; }
    /// Get width
    float getWidth() const { return width; }
    /// Set width
    void setWidth(float aWidht) { width = aWidht; }
    /// Get height
    float getHeight() const { return height; }
    /// Set height
    void setHeight(float aHeight) { height = aHeight; }

public:
    /// Add vectors
    Vector2D operator+(const Vector2D& rhs) const;
    /// Add vectors in-place
    Vector2D& operator+=(const Vector2D& rhs);
    /// Subtract vectors
    Vector2D operator-(const Vector2D& rhs) const;
    /// Subtract vectors in-place
    Vector2D& operator-=(const Vector2D& rhs);
    /// Multiply vector by scalar
    Vector2D operator*(float rhs) const;
    /// Multiply vector by scalar in-place
    Vector2D& operator*=(float rhs);
    /// Multiply vectors element-wise
    Vector2D operator*(const Vector2D& rhs) const;
    /// Multiply vectors element-wise in-place
    Vector2D& operator*=(const Vector2D& rhs);
    /// Divide vector by scalar
    Vector2D operator/(float rhs) const;
    /// Divide vector by scalar in-place
    Vector2D& operator/=(float rhs);
    /// Divide vectors element-wise
    Vector2D operator/(const Vector2D& rhs) const;
    /// Divide vectors element-wise in-place
    Vector2D& operator/=(const Vector2D& rhs);
    /// Change sign
    Vector2D operator-() const;

public:
    /// Calculate length
    float calculateLength() const;
    /// Calculate squared length
    float calculateSquaredLength() const;
    /// Calculate distance
    /// @param mode A type of distance (default: Euclidian)
    static float calculateDistance(
        const Vector2D& p,
        const Vector2D& q,
        DistanceType mode = DistanceEuclidian);
    /// Calculate dot product
    float calculateDotProduct(const Vector2D& v) const;
    /// Calculate normal vector
    Vector2D calculateNormalVector() const;
    /// Normalize vector
    Vector2D normalize() const;
};

}    // namespace tears

#endif /* Vector2D_hpp */
