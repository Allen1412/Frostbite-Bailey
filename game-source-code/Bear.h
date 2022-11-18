#ifndef BEAR_H
#define BEAR_H

#include <ctime>

#include "MoveableObjects.h"

using GameObjectSpeed::_bearSpeed;


/**
 * @class Bear
 * @author Phetolo Malele
 * @date 18/10/2022
 * @file Bear.h
 * @brief class that models a player and it capabilities
 */


class Bear : public MoveableObjects
{
public:
//constructor to set the initial position of a player
    Bear(const float& x, const float& y);
/**
 * @brief function to move a bear
 * @param direction is the direction of movement, of type Direction
 */
    int movement();

private:
     Direction _direction;
};

class InvalidBearPosition{ };


#endif // BEAR_H
