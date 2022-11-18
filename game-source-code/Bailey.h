#ifndef BAILEY_H
#define BAILEY_H
#include <ctime>

#include "MoveableObjects.h"

using GameObjectSpeed::_playerHorizontalSpeed;
using GameObjectSpeed::_playerVerticalSpeed;
using GameObjectSpeed::_iceBlockSpeed;
using GameObjectSpeed::_gravitySpeed;
using GameObjectSpeed::_toHouseSpeed;

/**
 * @class Bailey
 * @author Phetolo Malele
 * @date 02/10/2022
 * @file Bailey
 * @brief class that models a player and it capabilities
 */


class Bailey : public MoveableObjects
{
public:
//constructor to set the initial position of a player
    Bailey(const float& x, const float& y);
/**
 * @brief function to move a player
 * @param direction is the direction of movement, of type Direction
 */
    void move_manual(const Direction& _direction);
    void move_towards_door();
    bool isLost();
    bool isTop();
    void move_with_ice(const Direction& dir);
    void gravity();
    bool setIsOnIce(bool);
    bool delay();
    bool isWon();



private:
    float initial_tme, delta_time;
    bool isOnTop;
    bool isOnIce;
    bool won;

};

class InvalidPosition{};

#endif // BAILEY_H
