//
//  UnitTest.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//


#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include "TestCase.hpp"
#include "UnitTest.hpp"

namespace tears {

using namespace std;

/// Random seed
constexpr int RANDOM_SEED = 0;
/// Random number generator engine
mt19937 UnitTest::engine = mt19937(RANDOM_SEED);

// Default constructor
UnitTest::UnitTest() {}

// Destructor
UnitTest::~UnitTest() {}

// Add test case
void UnitTest::addTestCase(unique_ptr<TestCase> testCase) {
    testCases.push_back(std::move(testCase));
}

// Generate random numbers
vector<float> UnitTest::generateRandomNumbers(int numbersCount) {
    uniform_real_distribution<float> dist(-2.f, 2.f);
    vector<float> randomNumbers;
    randomNumbers.reserve(numbersCount);
    for (int i = 0; i < numbersCount; i++) {
        randomNumbers.push_back(dist(engine));
    }
    return randomNumbers;
}

// Run tests
void UnitTest::run() {
    vector<thread> threads;
    mutex mtx;
    vector<string> errorMessages;
    int passedCount = 0;
    int failedCount = 0;
    int testCount = (int)testCases.size();
    auto start_time = std::chrono::high_resolution_clock::now();
    cout << "running " << testCount << " tests" << endl;
    for (auto& testCase: testCases) {
        threads.push_back(thread([&mtx, &testCase, &passedCount, &failedCount, &errorMessages]() {
            string message;
            bool passed = testCase->runTest(&message);
            {
                lock_guard<mutex> lock(mtx);
                cout << "test " << testCase->getTestName() << " ... " << (passed ? "ok" : "FAILED")
                     << endl;
            }
            if (passed) {    // test case succeeded
                lock_guard<mutex> lock(mtx);
                passedCount++;
            } else {
                lock_guard<mutex> lock(mtx);
                failedCount++;
            }
            if (!message.empty()) {    // test case returned error message
                lock_guard<mutex> lock(mtx);
                errorMessages.push_back(message);
            }
        }));
    }
    for (auto& thread: threads) {
        thread.join();
    }
    if (failedCount != 0) {    // tests failed
        cout << endl << "failures:" << endl << endl;
        for (auto& m: errorMessages) {
            cout << m << endl << endl;
        }
    }
    cout << endl
         << "test result: " << (failedCount == 0 ? "ok" : "FAILED") << ". " << passedCount
         << " passed; " << failedCount << " failed" << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "tests finished in: " << duration.count() << " ms" << std::endl;
}

}    // namespace tears
