//
//  GLController.hpp
//  tears
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef GLController_hpp
#define GLController_hpp

#include <memory>

namespace tears {

using namespace std;

/// A singleton class that manage GL states and provide drawer.
class GLController {
protected:
    /// singleton instance
    static unique_ptr<GLController> glController;

protected:
    /// default constructor
    GLController();
    /// copy constuctor
    GLController(const GLController& gl) = delete;
    /// copy assignment operator
    GLController& operator=(const GLController& gl) = delete;
    /// move constructor
    GLController(GLController&& gl) = delete;
    /// move assignment operator
    GLController& operator=(GLController&& gl) = delete;

protected:
    /// get singleton instance
    static GLController* getInstance();
};

}    // namespace tears

#endif /* GLController_hpp */
