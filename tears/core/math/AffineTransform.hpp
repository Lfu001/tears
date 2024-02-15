//
//  AffineTransform.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/15.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef AffineTransform_hpp
#define AffineTransform_hpp

#include "math/Matrix.hpp"

namespace tears {

/// an affine transform matrix for 2D graphics
class AffineTransform: public Matrix {
public:
    /// default constructor
    AffineTransform();
    /// destructor
    virtual ~AffineTransform();

public:
    /// translate
    /// @param matrix a matrix to translate
    /// @param offset an offset to translate given matrix
    static AffineTransform translate(const AffineTransform& matrix, Size offset);
    /// translate inplace
    /// @param offset an offset to translate matrix
    void translate(Size offset);
    /// scale
    /// @param matrix a matrix to translate
    /// @param factor a factor to scale given matrix
    static AffineTransform scale(const AffineTransform& matrix, Size factor);
    /// scale inplace
    /// @param factor a factor to scale matrix
    void scale(Size factor);
    /// rotate
    /// @param matrix a matrix to translate
    /// @param angle an angle to rotate given matrix. the unit is [°].
    static AffineTransform rotate(const AffineTransform& matrix, float angle);
    /// rotate inplace
    /// @param angle an angle to rotate matrix. the unit is [°].
    void rotate(float angle);
};

}    // namespace tears

#endif /* AffineTransform_hpp */
