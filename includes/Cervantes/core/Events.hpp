#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "KeyCodes.hpp"
namespace Cervantes{

class WindowCloseEvent
{
    
};

class KeyEvent
{
    public:
        enum class KeyAction{ UNDEFINED, PRESS, REPEAT, RELEASE };
        KeyEvent(Key keyCode, KeyAction action);        
        Key getKeyCode() const;
        KeyAction getAction() const;
        void setKeyCode(Key newKeyCode);
        void setAction(KeyAction newAction);
    private:
        Key mKeyCode{Key::Unknown};
        KeyAction mAction{KeyAction::UNDEFINED};
};

}


#endif