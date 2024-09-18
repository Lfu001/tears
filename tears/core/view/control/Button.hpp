//
//  Button.hpp
//  tears
//
//  Created by Lfu001 on 2024/09/18.
//  Copyright © 2024 tears team. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <functional>
#include "view/base/View.hpp"

namespace tears {
using namespace std;

class Shape;

/// A control that initiates an action.
/// @ingroup control
class Button: public View {
protected:
    /// An action which is triggered when the button is pressed.
    function<void()> action;
    /// A background.
    Shape* background = nullptr;

public:
    /// constructor
    Button(function<void()> aAction = nullptr);
    /// destructor
    virtual ~Button();

public:
    /// Set backgroud.
    void setBackground(unique_ptr<Shape> background);
    /// Handle a touch event. Call this method from the OS API.
    void onTap();
};

}    // namespace tears

#endif /* Button_hpp */
