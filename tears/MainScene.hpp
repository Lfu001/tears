//
//  MainScene.hpp
//  tears
//
//  Created by Lfu001 on 2024/02/12.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include "scene/Scene.hpp"

namespace tears {

/// the first scene displayed after the application is launched
class MainScene: public Scene {
public:
    /// constructor
    MainScene(TearsEngine* aEngine);
    /// constructor (with child views)
    /// @param aChildren child views where child is subclass of `View`
    template<class... Views>
    MainScene(Views&&... aChildren): Scene(std::forward<Views>(aChildren)...) {}
    /// destructor
    virtual ~MainScene();
};

}    // namespace tears

#endif /* MainScene_hpp */
