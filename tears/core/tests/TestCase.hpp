//
//  TestCase.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef TestCase_hpp
#define TestCase_hpp

#include <functional>
#include <string>

namespace tears {

using namespace std;

/// A test case
class TestCase {
protected:
    /// Name of the test case
    string testName;
    /// Test function
    function<void(void)> testFunction;

public:
    /// Constructor
    explicit TestCase(const string& aTestName, const function<void(void)>& aTestFunction);
    /// Destructor
    ~TestCase();
    /// Get test name
    string getTestName() const { return testName; }
    /// Run test
    /// @param outMessage Error message buffer
    /// @return True if test succeeded, otherwise false
    bool runTest(string* outMessage);
};

}    // namespace tears

#endif /* TestCase_hpp */
