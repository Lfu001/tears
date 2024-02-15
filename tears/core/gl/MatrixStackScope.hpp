//
//  MatrixStackScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/14.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef MatrixStackScope_hpp
#define MatrixStackScope_hpp

namespace tears {

class AffineTransform;
class View;

/// a scope class that manages matrix stack
class MatrixStackScope {
    friend View;

protected:
    /// default constructor
    MatrixStackScope();
    /// destructor
    virtual ~MatrixStackScope();

    /// copy constructor
    MatrixStackScope(const MatrixStackScope& other) = delete;
    /// move constructor
    MatrixStackScope(MatrixStackScope&& other) = delete;
    /// copy assignment operator
    MatrixStackScope& operator=(const MatrixStackScope& other) = delete;
    /// move assignment operator
    MatrixStackScope& operator=(MatrixStackScope&& other) = delete;
    /// new operator
    void* operator new(size_t size) = delete;

public:
    /// get the top matrix of the matrix stack
    AffineTransform* getTopMatrix() const;
};

}    // namespace tears

#endif /* MatrixStackScope_hpp */
