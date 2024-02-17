//
//  TearsEngine.hpp
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef TearsEngine_hpp
#define TearsEngine_hpp

#include <functional>
#include <memory>
#include "math/Size.hpp"

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
    /// next scene
    unique_ptr<Scene> nextScene;
    /// dirty flag
    bool isDirty = false;
    /// callback function
    function<void()> callback = nullptr;
    /// screen size
    Size size;

protected:
    /// initializer
    void initialize(Size screenSize);

public:
    /// constructor
    TearsEngine(int screenWidth, int screenHeight);
    /// copy constructor
    TearsEngine(const TearsEngine& engine);
    /// destructor
    virtual ~TearsEngine();

public:
    /// run one event loop
    void runOneLoop();
    /// register callback function to run on the beginning of the next event loop
    void setNextLoopCallback(function<void()> aCallback) { callback = aCallback; }
    /// set current scene
    /// @param scene a scene to be set as current scene
    /// @param lazy if true, set scene on the next event loop, otherwise set intermediately
    /// (default: true)
    void setCurrentScene(unique_ptr<Scene> scene, bool lazy = true);
    /// set a size of the view
    void setViewSize(int width, int height);
    /// set screen scale
    void setScreenScale(float scale) const;
    /// get dirty flag
    bool getIsDirty() const { return isDirty; }
    /// set dirty flag
    void setIsDirty(bool b) { isDirty = b; }
};

}    // namespace tears

#endif /* TearsEngine_hpp */
