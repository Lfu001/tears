//
//  ViewFlag.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef ViewFlag_h
#define ViewFlag_h

#include <cstdint>

namespace tears {

using namespace std;

/// flag types for ViewFlag
enum FlagType : int64_t {
    /// whether the View is visible
    FlagVisible = 1 << 0,
    /// whether the View layout is dirty
    FlagDirtyLayout = 1 << 1,
};

/// manage flags of the View
class ViewFlag {
private:
    /// 64-bit flag holder
    int64_t flags = 0x0;

protected:
    /// reset all the flags to false
    void resetFlagsDefault();

public:
    /// constructor
    ViewFlag();
    /// destructor
    virtual ~ViewFlag();

public:
    /// get whether the View is visible
    bool getIsVisible() const;
    /// set whether the View is visible
    void setIsVisible(bool b);
    /// get whether the View layout is dirty
    bool getIsDirtyLayout() const;
    /// set whether the View layout is dirty
    void setIsDirtyLayout(bool b);
};

}    // namespace tears

#endif /* ViewFlag_h */
