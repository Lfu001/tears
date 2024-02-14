//
//  MatrixTest.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef MatrixTest_hpp
#define MatrixTest_hpp

#include <string>
#include "math/Matrix.hpp"

namespace tears {

/// An unit test of Matrix
class MatrixTest {
protected:
    /// get pretty matrix string
    static string toString(const Matrix& matrix);

public:
    /// Default constructor
    MatrixTest();
    /// Destructor
    virtual ~MatrixTest();
    /// Run tests
    void runTests() const;
};

}    // namespace tears

#endif /* MatrixTest_hpp */
