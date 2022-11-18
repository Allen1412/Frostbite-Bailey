#include "Bailey.h"

Bailey::Bailey(const float& x, const float& y)
    : MoveableObjects()
{
    setVerticalSpeed(_playerVerticalSpeed);
    setHorizontalSpeed(_playerHorizontalSpeed);
    isOnTop = false;
    isOnIce = false;
    won = false;

    if(x > (ScreenDimensions::_Screen_Width - GameConstants::playerWidth) || x < 0 ||
        y > (ScreenDimensions::_Screen_Height - GameConstants::playerHeight) || y < 0)
        {
            throw InvalidPosition{};}

    setSize(GameConstants::playerWidth_or, GameConstants::playerHeight_or, GameConstants::playerWidth,
        GameConstants::playerHeight);
    setPosition(x, y);
}



void Bailey::move_manual(const Direction& _direction)
{

    setVerticalSpeed(_playerVerticalSpeed);
    switch(_direction) {
    case Direction::Left:

        move_left();
        break;
    case Direction::Right:
        move_right();
        break;
        case Direction::Up:
            if((getPosition().yCoord < GameConstants::playerHeight + GameConstants::safe_zone_height) || !isOnIce) {
                return;
            }
            jump_up();
        return;
        break;
        case Direction::Down:
            if(getPosition().yCoord >= (ScreenDimensions::_Screen_Height-73) - GameConstants::playerHeight) {
                return;
            }
            jump_down();
        return;
        break;
    default:
        return;
    }
}


void Bailey::move_with_ice(const Direction& dir){

    setVerticalSpeed(_playerVerticalSpeed);

    if (getPosition().yCoord== (_playerVerticalSpeed/60 - GameConstants::playerHeight + GameConstants::safe_zone_height)){
            if(dir == Direction::Left)
                move_right();
            else
                 move_left();
    }
    else if(getPosition().yCoord==(2*_playerVerticalSpeed/60 - GameConstants::playerHeight + GameConstants::safe_zone_height)){
            if(dir == Direction::Left)
                move_left();
            else
                 move_right();
    }
   else if(getPosition().yCoord == (3*_playerVerticalSpeed/60 - GameConstants::playerHeight + GameConstants::safe_zone_height)){

        if(dir == Direction::Left)
                move_right();
            else
                 move_left();
    }else if(getPosition().yCoord == (4*_playerVerticalSpeed/60 - GameConstants::playerHeight + GameConstants::safe_zone_height)){
        if(dir == Direction::Left)
                move_left();
            else
                 move_right();
    }


}


void Bailey::gravity()
{
   setVerticalSpeed(_playerVerticalSpeed);

            if(delay())
                jump_down();


}

bool Bailey::delay()
    {

        delta_time = clock() - initial_tme;

        if((delta_time / 1000.f) >= 0.3f) {
            initial_tme = clock();
            return true;
        }

        return false;
    }


    bool Bailey::isLost(){
        if(getPosition().xCoord < GameConstants::playerWidth || getPosition().xCoord>ScreenDimensions::_Screen_Width - GameConstants::playerWidth)
           {
               setActiveState(false);
               return true;
           }
        if(getPosition().yCoord >= ScreenDimensions::_Screen_Height - GameConstants::playerHeight)
            {
                setActiveState(false);
                return true;
            }


        return false;

        }

     bool Bailey::isTop(){

         if(getPosition().yCoord>(160))
            isOnTop = false;
         else
            isOnTop = true;

     return isOnTop;
     }


     bool Bailey::setIsOnIce(bool onIce){

        isOnIce = onIce;

     }


void Bailey::move_towards_door(){



    if(getPosition().xCoord >=GameConstants::_houses_X_position + (GameConstants::housesFinalWidth)/2 - 42){
            if(getPosition().yCoord <= GameConstants::housesFinalHeight - 3*GameConstants::playerHeight)
                {
                    won = true;
                    return;}
            setVerticalSpeed(_toHouseSpeed);
            jump_up();
    }


}


bool Bailey::isWon(){return won;}
