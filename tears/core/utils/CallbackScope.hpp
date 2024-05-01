//
//  CallbackScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/03.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef CallbackScope_hpp
#define CallbackScope_hpp

#include <functional>

namespace tears {

using namespace std;

/// a class that execute a callback function upon scope exit
/// @ingroup utils
class CallbackScope {
protected:
    /// a callback function to execute when scope exit
    function<void()> callback;

protected:
    /// default constructor
    CallbackScope() = delete;
    /// copy constructor
    CallbackScope(const CallbackScope&) = delete;
    /// copy assignment operator
    CallbackScope& operator=(const CallbackScope&) = delete;
    /// move constructor
    CallbackScope(CallbackScope&&) = delete;
    /// move assignment operator
    CallbackScope& operator=(CallbackScope&&) = delete;
    /// new operator
    void* operator new(size_t) = delete;
    /// new[] operator
    void* operator new[](size_t) = delete;

public:
    /// constructor
    CallbackScope(function<void()> aCallback);
    /// destructor
    ~CallbackScope() noexcept;
};

}    // namespace tears

#endif /* CallbackScope_hpp */
