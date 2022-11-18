#include "Ice.h"



Ice::Ice(const Direction& init_dir, const float& x, const float& y)
    : MoveableObjects()
{
    direc = init_dir;

    if(x > (ScreenDimensions::_Screen_Width - GameConstants::Ice_block_width) || x < GameConstants::Ice_block_width ||
        y > (ScreenDimensions::_Screen_Height - GameConstants::Ice_block_height) || y < GameConstants::Ice_block_height)
        throw InvalidInitialIcePosition{ };


    setSize(GameConstants::Ice_block_width_or, GameConstants::Ice_block_height_or, GameConstants::Ice_block_width,
        GameConstants::Ice_block_height);

        blue = false;

    setPosition(x, y);
    setActiveState(true);
}


bool Ice::setBlue(bool color){
    blue = color;
}
bool Ice::getBlue(){

    return blue;
}



void Ice::move_ice(const Direction& dir)
{

    switch(dir) {
    case Direction::Right:
        if(getPosition().xCoord >= (ScreenDimensions::_Screen_Width + GameConstants::Ice_block_width))
            {
                setPosition(0,this->getPosition().yCoord);
            }
        setHorizontalSpeed(GameObjectSpeed::_iceBlockSpeed);
        move_right();
        break;
    case Direction::Left:
        if(getPosition().xCoord < - GameConstants::Ice_block_width){
            setPosition(ScreenDimensions::_Screen_Width, this->getPosition().yCoord);
        }
        setHorizontalSpeed(GameObjectSpeed::_iceBlockSpeed);
        move_left();
        break;
    default:
        return;
    }
}
