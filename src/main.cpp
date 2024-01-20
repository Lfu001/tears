//
//  main.cpp
//  tears
//
//  Created by Lfu001 on 2023/11/04.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifdef DEBUG
#include "tests/Vector2DTest.hpp"
#endif    // DEBUG

int main() {
#ifdef DEBUG
    tears::Vector2DTest vector2DTest;
    vector2DTest.runTests();
#endif    // DEBUG
}
