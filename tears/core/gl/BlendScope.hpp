//
//  BlendScope.hpp
//  tears
//
//  Created by Lfu001 on 2024/05/06.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef BlendScope_hpp
#define BlendScope_hpp

#include <cstdint>
#include "gl/GLController.hpp"

namespace tears {

enum BlendEquationType : uint32_t;
enum BlendType : uint32_t;

/// a class that set GL blend equation and blend factors
/// @ingroup gl
class BlendScope {
protected:
    /// a backup of blend settings
    BlendSettings blendBackup;

public:
    /// constructor
    /// @param equation a blend equation
    /// @param factorSrc a blend factor for source
    /// @param factorDst a blend factor for destination
    BlendScope(BlendEquationType equation, BlendType factorSrc, BlendType factorDst);
    /// destructor
    virtual ~BlendScope();
};

}    // namespace tears

#endif /* BlendScope_hpp */
