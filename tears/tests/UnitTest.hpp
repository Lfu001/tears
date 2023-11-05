//
//  UnitTest.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef UnitTest_hpp
#define UnitTest_hpp

#include <memory>
#include <random>
#include <vector>

#include "TestCase.hpp"

namespace tears {

using namespace std;

/// Manage test cases
class UnitTest {
protected:
    /// Test cases
    vector<unique_ptr<TestCase>> testCases;
    /// Random number generator engine
    static mt19937 engine;

public:
    /// Default constructor
    UnitTest();
    /// Destructor
    virtual ~UnitTest();

public:
    /// Add test case
    void addTestCase(unique_ptr<TestCase> testCase);
    /// Generate random numbers
    /// @param numbersCount The number of random numbers to generate
    static vector<float> generateRandomNumbers(int numbersCount);
    /// Run tests
    void run();
};

}    // namespace tears

#endif /* UnitTest_hpp */
