//
//  TestCase.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#include "TestCase.hpp"

namespace tears {

// Constructor
TestCase::TestCase(const string& aTestName, const function<void(void)>& aTestFunction) {
    testName = aTestName;
    testFunction = aTestFunction;
}

// Destructor
TestCase::~TestCase() {}

// Run test
bool TestCase::runTest(string* outMessage) {
    try {
        testFunction();
        return true;
    } catch (const runtime_error& e) {
        *outMessage = e.what();
        return false;
    }
}

}    // namespace tears
