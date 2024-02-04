//
//  MatrixTest.cpp
//  tears
//
//  Created by Lfu001 on 2024/02/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "tests/UnitTest.hpp"
#include "MatrixTest.hpp"

namespace tears {

using namespace std;

// Default constructor
MatrixTest::MatrixTest() {}

// Destructor
MatrixTest::~MatrixTest() {}

// get pretty matrix string
string MatrixTest::toString(const Matrix& matrix) {
    stringstream ss;
    ss << "[";
    for (int row = 0; row < 3; row++) {
        ss << "[";
        for (int col = 0; col < 3; col++) {
            ss << matrix[row][col];
            if (col < 2) {
                ss << ", ";
            }
        }
        ss << "]";
        if (row < 2) {
            ss << ",";
        }
        ss << endl;
    }
    ss << "]" << endl;
    return ss.str();
}

// Run tests
void MatrixTest::runTests() const {
    UnitTest unitTest;

    unitTest.addTestCase(make_unique<TestCase>("Multiply Matrices", []() {
        float a[3][3] = {
            {1.f, 0.f, 8.f },
            {3.f, 5.f, -2.f},
            {2.f, 3.f, 1.f }
        };
        float b[3][3] = {
            {-9.f, 3.f, 6.f},
            {2.f,  1.f, 0.f},
            {4.f,  2.f, 5.f}
        };
        float expected[3][3] = {
            {23.f,  19.f, 46.f},
            {-25.f, 10.f, 8.f },
            {-8.f,  11.f, 17.f}
        };
        Matrix aMat(a), bMat(b), expectedMat(expected);
        Matrix res = aMat * bMat;
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Add element wise", []() {
        float a[3][3] = {
            {2.f,  3.f, -4.f},
            {11.f, 8.f, 7.f },
            {2.f,  5.f, 3.f }
        };
        float b[3][3] = {
            {3.f,  1.f, 2.f},
            {2.f,  4.f, 4.f},
            {-1.f, 5.f, 6.f}
        };
        float expected[3][3] = {
            {5.f,  4.f,  -2.f},
            {13.f, 12.f, 11.f},
            {1.f,  10.f, 9.f }
        };
        Matrix aMat(a), bMat(b), expectedMat(expected);
        Matrix res = aMat.add(bMat);
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Subtract element wise", []() {
        float a[3][3] = {
            {2.f,  3.f, -4.f},
            {11.f, 8.f, 7.f },
            {2.f,  5.f, 3.f }
        };
        float b[3][3] = {
            {3.f,  1.f, 2.f},
            {2.f,  4.f, 4.f},
            {-1.f, 5.f, 6.f}
        };
        float expected[3][3] = {
            {-1.f, 2.f, -6.f},
            {9.f,  4.f, 3.f },
            {3.f,  0.f, -3.f}
        };
        Matrix aMat(a), bMat(b), expectedMat(expected);
        Matrix res = aMat.subtract(bMat);
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Multiply element wise", []() {
        float a[3][3] = {
            {2.f, 3.f, 5.f },
            {1.f, 4.f, 8.f },
            {2.f, 1.f, -3.f}
        };
        float b[3][3] = {
            {3.f,  1.f, 2.f},
            {2.f,  4.f, 2.f},
            {-1.f, 4.f, 3.f}
        };
        float expected[3][3] = {
            {6.f,  3.f,  10.f},
            {2.f,  16.f, 16.f},
            {-2.f, 4.f,  -9.f}
        };
        Matrix aMat(a), bMat(b), expectedMat(expected);
        Matrix res = aMat.multiply(bMat);
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Divide element wise", []() {
        float a[3][3] = {
            {7.f, 8.f, 9.f},
            {2.f, 6.f, 5.f},
            {3.f, 2.f, 1.f}
        };
        float b[3][3] = {
            {1.f, 2.f, 3.f},
            {2.f, 3.f, 1.f},
            {3.f, 2.f, 1.f}
        };
        float expected[3][3] = {
            {7.f, 4.f, 3.f},
            {1.f, 2.f, 5.f},
            {1.f, 1.f, 1.f}
        };
        Matrix aMat(a), bMat(b), expectedMat(expected);
        Matrix res = aMat.divide(bMat);
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Add scalar", []() {
        float a[3][3] = {
            {7.f, 8.f, 9.f},
            {2.f, 6.f, 5.f},
            {3.f, 2.f, 1.f}
        };
        float b = 2.f;
        float expected[3][3] = {
            {9.f, 10.f, 11.f},
            {4.f, 8.f,  7.f },
            {5.f, 4.f,  3.f }
        };
        Matrix aMat(a), expectedMat(expected);
        Matrix res = aMat + b;
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Subtract scalar", []() {
        float a[3][3] = {
            {7.f, 8.f, 9.f},
            {2.f, 6.f, 5.f},
            {3.f, 2.f, 1.f}
        };
        float b = 2.f;
        float expected[3][3] = {
            {5.f, 6.f, 7.f },
            {0.f, 4.f, 3.f },
            {1.f, 0.f, -1.f}
        };
        Matrix aMat(a), expectedMat(expected);
        Matrix res = aMat - b;
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Multiply by scalar", []() {
        float a[3][3] = {
            {7.f, 8.f, 9.f},
            {2.f, 6.f, 5.f},
            {3.f, 2.f, 1.f}
        };
        float b = 3.f;
        float expected[3][3] = {
            {21.f, 24.f, 17.f},
            {6.f,  18.f, 15.f},
            {9.f,  6.f,  3.f }
        };
        Matrix aMat(a), expectedMat(expected);
        Matrix res = aMat * b;
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Divide by scalar", []() {
        float a[3][3] = {
            {7.f, 8.f, 9.f},
            {2.f, 6.f, 5.f},
            {3.f, 2.f, 1.f}
        };
        float b = 2.f;
        float expected[3][3] = {
            {3.5f, 4.f, 4.5f},
            {1.f,  3.f, 2.5f},
            {1.5f, 1.f, 0.5f}
        };
        Matrix aMat(a), expectedMat(expected);
        Matrix res = aMat / b;
        if (res != expectedMat) {
            stringstream ss;
            ss << "expected:" << endl << toString(expectedMat) << endl;
            ss << "actual:" << endl << toString(res) << endl;
            runtime_error(ss.str());
        }
    }));
    unitTest.addTestCase(make_unique<TestCase>("Identity", []() {
        Matrix id = Matrix::getIdentity();
        float expected[3][3] = {
            {1.f, 0.f, 0.f},
            {0.f, 1.f, 0.f},
            {0.f, 0.f, 1.f}
        };
        Matrix expectedMat = Matrix(expected);
        if (id != expectedMat) {
            runtime_error(toString(id));
        }
    }));
    unitTest.run();
}

}    // namespace tears
