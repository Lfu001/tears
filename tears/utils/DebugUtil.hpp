//
//  DebugUtil.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/18.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef DebugUtil_hpp
#define DebugUtil_hpp

#include <csignal>
#include <iostream>

/// Variable template to check if the type is a `std::unique_ptr`
template<typename T>
constexpr bool is_unique_ptr_v = false;
/// Variable template to check if the type is a `std::unique_ptr`
template<typename T, typename Deleter>
constexpr bool is_unique_ptr_v<std::unique_ptr<T, Deleter>> = true;

class DebugUtil {
public:
    /// raise signal
    static void raiseSignal() { std::raise(SIGINT); }
};

/// validates the condition in debug builds and breaks if the condition is false (and then you can
/// continue executing the program). In a release build, it does nothing.
#ifdef DEBUG
#    define tears_assert(condition)                                                          \
        if (!(condition)) {                                                                  \
            printf("Assertion failed: %s in file %s: %d\n", #condition, __FILE__, __LINE__); \
            DebugUtil::raiseSignal();                                                        \
        }                                                                                    \
        ((void)0)
#else
#    define tears_assert(condition) ((void)0)
#endif

#endif /* DebugUtil_hpp */
