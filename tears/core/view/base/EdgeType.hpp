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
    /// {top-leading}
    EdgeTopLeading,
    /// {top}
    EdgeTop,
    /// {top-trailing}
    EdgeTopTrailing,
    /// {bottom-leading}
    EdgeBottomLeading,
    /// {bottom}
    EdgeBottom,
    /// {bottom-trailing}
    EdgeBottomTrailing,
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
