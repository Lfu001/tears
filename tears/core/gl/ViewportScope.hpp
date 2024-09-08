//
//  ViewportScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/05/05.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef ViewportScope_hpp
#define ViewportScope_hpp

#include "math/AffineTransform.hpp"
#include "math/Size.hpp"

namespace tears {

/// a class that set viewport matrix
/// @ingroup gl
class ViewportScope {
    /// a backup of the viewport size
    Size viewportSizeBackup;
    /// a backup of the viewport matrix
    AffineTransform viewportMatrixBackup;

public:
    /// constructor
    /// @param width a viewport width [px]
    /// @param height a viewport height [px]
    ViewportScope(int width, int height);
    /// destructor
    virtual ~ViewportScope();
};

}    // namespace tears

#endif /* ViewportScope_hpp */
