//
//  TearsEngine.hpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef TearsEngine_hpp
#define TearsEngine_hpp

namespace tears {

class GLController;

/// an engine of tears app
class TearsEngine {
protected:
    /// GL state manager and drawer
    GLController* glController = nullptr;

protected:
    /// initializer
    void initialize();

public:
    /// default constructor
    TearsEngine();
    /// destructor
    virtual ~TearsEngine();

public:
    /// run one event loop
    void runOneLoop() const;
    /// set a size of the view
    void setViewSize(int x, int y) const;
};

}    // namespace tears

#endif /* TearsEngine_hpp */
