//
//  TearsEngine.hpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef TearsEngine_hpp
#define TearsEngine_hpp

#include <memory>

namespace tears {

using namespace std;

class GLController;
class Scene;

/// an engine of tears app
class TearsEngine {
protected:
    /// GL state manager and drawer
    GLController* glController = nullptr;
    /// current scene
    shared_ptr<Scene> currentScene;
    /// dirty flag
    bool isDirty = false;

protected:
    /// initializer
    void initialize();

public:
    /// default constructor
    TearsEngine();
    /// copy constructor
    TearsEngine(const TearsEngine& engine);
    /// destructor
    virtual ~TearsEngine();

public:
    /// run one event loop
    void runOneLoop();
    /// set a size of the view
    void setViewSize(int x, int y);
    /// set dirty flag
    void setIsDirty(bool b) { isDirty = b; }
};

}    // namespace tears

#endif /* TearsEngine_hpp */
