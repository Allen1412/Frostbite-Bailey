#include "Bear.h"

Bear::Bear(const float& x, const float& y)
           : MoveableObjects()
{
        setHorizontalSpeed(_bearSpeed);



    if(x > (ScreenDimensions::_Screen_Width - GameConstants::bearWidth) || x < GameConstants::bearWidth ||
        y > (ScreenDimensions::_Screen_Height - GameConstants::bearHeight) || y < GameConstants::bearHeight)
        throw InvalidBearPosition{};

    setSize(GameConstants::bearWidth_or, GameConstants::bearHeight_or, GameConstants::bearWidth,
        GameConstants::bearHeight);





    setPosition(x, y);
    _direction = Direction::Right;

}

int Bear::movement(){

        setHorizontalSpeed(_bearSpeed);

        switch(_direction) {
    case Direction::Left:
        if((getPosition().xCoord < GameConstants::bearWidth)) {
                _direction = Direction::Right;
                return 1;
            }
        move_left();
        break;
    case Direction::Right:
        if((getPosition().xCoord > ScreenDimensions::_Screen_Width - GameConstants::bearWidth)) {
                _direction = Direction::Left;
                return -1;
            }
        move_right();
        break;
    default:
        return -1;

        }

        if(_direction == Direction::Left)
            return 1;
        else
            return -1;
}

