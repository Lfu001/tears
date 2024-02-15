//
//  PointTest.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#include <sstream>
#include "math/Point.hpp"
#include "tests/UnitTest.hpp"
#include "PointTest.hpp"

namespace tears {

constexpr int TEST_ITERATION_COUNT = 20000000;

// Default constructor
PointTest::PointTest() {}

// Destructor
PointTest::~PointTest() {}

// Run tests
void PointTest::runTests() const {
    UnitTest unitTest;
    vector<float> random1(UnitTest::generateRandomNumbers(TEST_ITERATION_COUNT));
    vector<float> random2(UnitTest::generateRandomNumbers(TEST_ITERATION_COUNT));
    unitTest.addTestCase(make_unique<TestCase>("Addition", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            Point res = a + b;
            float actualX = random1[i] + random2[i];
            float actualY = random1[i + 1] + random2[i + 1];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Addition ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Subtraction", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            Point res = a - b;
            float actualX = random1[i] - random2[i];
            float actualY = random1[i + 1] - random2[i + 1];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Subtraction ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Multiplication (scalar)", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            float b = random2[i];
            Point res = a * b;
            float actualX = random1[i] * random2[i];
            float actualY = random1[i + 1] * random2[i];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Multiplication (scalar) ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: " << random2[i] << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(
        make_unique<TestCase>("Multiplication (element-wise)", [&random1, &random2]() {
            for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
                Point a(random1[i], random1[i + 1]);
                Point b(random2[i], random2[i + 1]);
                Point res = a * b;
                float actualX = random1[i] * random2[i];
                float actualY = random1[i + 1] * random2[i + 1];
                if (res.x != actualX || res.y != actualY) {
                    stringstream ss;
                    ss << "--- Multiplication (element-wise) ---" << endl;
                    ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")"
                       << endl;
                    ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")"
                       << endl;
                    ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                    ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                    throw runtime_error(ss.str());
                }
            }
        }));
    unitTest.addTestCase(make_unique<TestCase>("Division (scalar)", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            float b = random2[i];
            if (random2[i] == 0.f) {
                continue;
            }
            Point res = a / b;
            float actualX = random1[i] / random2[i];
            float actualY = random1[i + 1] / random2[i];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Division (scalar) ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: " << random2[i] << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Division (element-wise)", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            if (random2[i] == 0.f || random2[i + 1] == 0.f) {
                continue;
            }
            Point res = a / b;
            float actualX = random1[i] / random2[i];
            float actualY = random1[i + 1] / random2[i + 1];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Division (element-wise) ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Change sign", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point res = -a;
            float actualX = -random1[i];
            float actualY = -random1[i + 1];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Change sign ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Length", [&random1]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            float res = a.calculateLength();
            float actual = sqrtf(random1[i] * random1[i] + random1[i + 1] * random1[i + 1]);
            if (res != actual) {
                stringstream ss;
                ss << "--- Length ---" << endl;
                ss << "input: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "result: " << res << endl;
                ss << "actual: " << actual << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Squared length", [&random1]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            float res = a.calculateSquaredLength();
            float actual = random1[i] * random1[i] + random1[i + 1] * random1[i + 1];
            if (res != actual) {
                stringstream ss;
                ss << "--- Squared length ---" << endl;
                ss << "input: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "result: " << res << endl;
                ss << "actual: " << actual << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Euclidean distance", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            float res = Point::calculateDistance(a, b, DistanceEuclidean);
            float actual = sqrtf(
                (random2[i] - random1[i]) * (random2[i] - random1[i])
                + (random2[i + 1] - random1[i + 1]) * (random2[i + 1] - random1[i + 1]));
            if (res != actual) {
                stringstream ss;
                ss << "--- Euclidean distance ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: " << res << endl;
                ss << "actual: " << actual << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Manhattan distance", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            float res = Point::calculateDistance(a, b, DistanceManhattan);
            float actual = fabsf(random2[i] - random1[i]) + fabsf(random2[i + 1] - random1[i + 1]);
            if (res != actual) {
                stringstream ss;
                ss << "--- Manhattan distance ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: " << res << endl;
                ss << "actual: " << actual << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Chebyshev distance", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            float res = Point::calculateDistance(a, b, DistanceChebyshev);
            float actual =
                fmaxf(fabsf(random2[i] - random1[i]), fabsf(random2[i + 1] - random1[i + 1]));
            if (res != actual) {
                stringstream ss;
                ss << "--- Chebyshev distance ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: " << res << endl;
                ss << "actual: " << actual << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Dot product", [&random1, &random2]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point b(random2[i], random2[i + 1]);
            float res = a.calculateDotProduct(b);
            float actual = random1[i] * random2[i] + random1[i + 1] * random2[i + 1];
            if (res != actual) {
                stringstream ss;
                ss << "--- Dot product ---" << endl;
                ss << "input 1: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "input 2: Vector2D(" << random2[i] << ", " << random2[i + 1] << ")" << endl;
                ss << "result: " << res << endl;
                ss << "actual: " << actual << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Normal vector", [&random1]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point res = a.calculateNormalVector();
            float actualX = random1[i + 1];
            float actualY = -random1[i];
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Normal vector ---" << endl;
                ss << "input: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Normalization", [&random1]() {
        for (int i = 0; i < TEST_ITERATION_COUNT; i += 2) {
            Point a(random1[i], random1[i + 1]);
            Point res = a.normalize();
            float length = sqrtf(random1[i] * random1[i] + random1[i + 1] * random1[i + 1]);
            float actualX = random1[i] / length;
            float actualY = random1[i + 1] / length;
            if (res.x != actualX || res.y != actualY) {
                stringstream ss;
                ss << "--- Normalization ---" << endl;
                ss << "input: Vector2D(" << random1[i] << ", " << random1[i + 1] << ")" << endl;
                ss << "result: Vector2D(" << res.x << ", " << res.y << ")" << endl;
                ss << "actual: Vector2D(" << actualX << ", " << actualY << ")" << endl;
                throw runtime_error(ss.str());
            }
        }
    }));
    unitTest.run();
}

}    // namespace tears
