#include "KeyInputHandler.h"

bool KeyInputHandler::isButtonPressed(const Key& _key)
{
    switch(_key)
    {
        case Key::Escape:
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                return true;
            }
                else return false;

        case Key::Up:
            if (Keyboard::isKeyPressed(Keyboard::Up))
                return true;
                else return false;
           case Key::Down:
            if (Keyboard::isKeyPressed(Keyboard::Down))
                return true;
                else return false;
        case Key::Left:
            if (Keyboard::isKeyPressed(Keyboard::Left))
                return true;
                else return false;
        case Key::Right:
            if (Keyboard::isKeyPressed(Keyboard::Right))
                 return true;
                else return false;
        case Key::Space:
            if (Keyboard::isKeyPressed(Keyboard::Space))
                return true;
                else return false;
        case Key::PlayButton:
            if (Keyboard::isKeyPressed(Keyboard::P))
                return true;
                else return false;
            case Key::Enter:
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                    return true;
                    else return false;
             case Key::Reverser:
                if (Keyboard::isKeyPressed(Keyboard::R))
                    {
                        return true;}
                    else return false;
        default:
         assert(false);
    }
}
