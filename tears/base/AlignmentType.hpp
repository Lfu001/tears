//
//  AlignmentType.hpp
//  tears
//
//  Created by Lfu001 on 2023/11/26.
//  Copyright © 2023 tears team. All rights reserved.
//

#ifndef AlignmentType_h
#define AlignmentType_h

namespace tears {

/// alignment type
enum AlignmentType {
    /// top and leading edge of the view
    AlignmentTopLeading,
    /// top edge of the view
    AlignmentTop,
    /// top and trailing edge of the view
    AlignmentTopTrailing,
    /// leading edge of the view
    AlignmentLeading,
    /// center of the view
    AlignmentCenter,
    /// trailing edge of the view
    AlignmentTrailing,
    /// bottom and leading edge of the view
    AlignmentBottomLeading,
    /// bottom edge of the view
    AlignmentBottom,
    /// bottom and trailing edge of the view
    AlignmentBottomTrailing,
};

}    // namespace tears

#endif /* AlignmentType_h */
