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

namespace tears {

using namespace std;

/// variable template to check if the type is a `std::unique_ptr`
/// @ingroup utils
template<typename T>
constexpr bool is_unique_ptr_v = false;
/// variable template to check if the type is a `std::unique_ptr`
/// @ingroup utils
template<typename T, typename Deleter>
constexpr bool is_unique_ptr_v<std::unique_ptr<T, Deleter>> = true;

/// a utility available only on debug build
/// @ingroup utils
class DebugUtil {
private:
    /// flag for disable execution pause on `tears_assert()` failed
    inline static bool noBreakMode = false;

public:
    /// pause execution and prints failed check, file name, line and function
    static void pauseExecution(
        const char* condition,
        const char* fileName,
        int line,
        const char* functionName) {
        if (!noBreakMode) {
            cout << "Assertion failed: '" << condition << "' in file " << fileName << ":" << line
                 << endl
                 << "\tin " << functionName << endl;

            // If the execution pauses here repeatedly and you want to skip the pause triggered by
            // `tears_assert()` on this run, enter the following code into the lldb console and
            // continue the execution.
            // `(lldb) expr noBreakMode = true`
            std::raise(SIGTRAP);
        }
    }
};

/// a name of the function
#ifdef _MSC_VER
#    define __TEARS_FUNCTION__ __FUNCTION__
#elif defined(__clang__) || defined(__GNUC__)
#    define __TEARS_FUNCTION__ __PRETTY_FUNCTION__
#else
#    define __TEARS_FUNCTION__ __func__
#endif

/// validates the condition in debug builds and breaks if the condition is false (and then you can
/// continue executing the program). In a release build, it does nothing.
#ifdef DEBUG
#    define tears_assert(condition) \
        (condition)                 \
            ? ((void)0)             \
            : DebugUtil::pauseExecution(#condition, __FILE__, __LINE__, __TEARS_FUNCTION__)
#else
#    define tears_assert(condition) ((void)0)
#endif

/// print to console on debug build, otherwise do nothing
#ifdef DEBUG
#    define tears_printf(...) printf(__VA_ARGS__)
#else
#    define tears_printf(...) ((void)0)
#endif

}    // namespace tears

#endif /* DebugUtil_hpp */
