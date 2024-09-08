//
//  Interval.hpp
//  tears
//
//  Created by Lfu001 on 2024/07/14.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Interval_hpp
#define Interval_hpp

#include <optional>

namespace tears {
using namespace std;

/// a interval
/// @ingroup math
struct Interval {
protected:
    /// whether the left endpoint is included
    bool isLeftClosed = true;
    /// whether the right endpoint is included
    bool isRightClosed = true;

public:
    /// a left value
    float left = numeric_limits<float>::lowest();
    /// a right value
    float right = numeric_limits<float>::max();

public:
    /// default constructor
    Interval();
    /// constructor from endpoints
    Interval(float leftVal, float rightVal, bool leftClosed = true, bool rightClosed = true);
    /// copy constructor
    Interval(const Interval& other);
    /// move constructor
    Interval(Interval&& other);
    /// destructor
    virtual ~Interval();

public:
    /// copy assignment
    Interval& operator=(const Interval& other);
    /// move assignment
    Interval& operator=(Interval&& other);
    /// equality operator
    bool operator==(const Interval& other) const;
    /// inequality operator
    bool operator!=(const Interval& other) const;

public:
    /// set interval
    /// @param leftVal a left endpoint
    /// @param rightVal a right endpoint
    /// @param leftClosed whether the left endpoint is included
    /// @param rightClosed whether the right endpoint is included
    void set(float leftVal, float rightVal, bool leftClosed = true, bool rightClosed = true);
    /// get supremum
    float getSupremum() const;
    /// get maximum
    optional<float> getMaximum() const;
    /// get infimum
    float getInfimum() const;
    /// get minimum
    optional<float> getMinimum() const;
    /// get whether the left endpoint is included
    bool getIsLeftClosed() const { return isLeftClosed; }
    /// get whether the right endpoint is included
    bool getIsRightClosed() const { return isRightClosed; }

    /// whether the interval contains the value
    /// @param value a value to be checked
    bool contains(float value) const;
};

}    // namespace tears

#endif /* Interval_hpp */
