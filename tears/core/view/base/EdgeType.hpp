//
//  PositionType.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef EdgeType_h
#define EdgeType_h

namespace tears {

/// edge position set
/// @ingroup view 
enum EdgeType {
    /// {top, bottom, leading, trailing}
    EdgeAll,
    /// {top}
    EdgeTop,
    /// {bottom}
    EdgeBottom,
    /// {leading}
    EdgeLeading,
    /// {trailing}
    EdgeTrailing,
    /// {leading, trailing}
    EdgeHorizontal,
    /// {top, bottom}
    EdgeVertical,
};

}    // namespace tears

#endif /* EdgeType_h */
