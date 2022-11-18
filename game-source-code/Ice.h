#ifndef ICE_H
#define ICE_H

#include "MoveableObjects.h"

using namespace GameObjectSpeed;

/**
 * @class Ice
 * @author Phetolo Malele
 * @date 03/10/2022
 * @file Ice.h
 * @brief class that models each ice on an armada
 */
class Ice : public MoveableObjects
{
public:
    Ice(const Direction& dir, const float& x, const float& y);//initial direction, initial x-coord, initial y-coord
    /**
     * @brief function that moves the enemy at a particular speed
     * @param dir a specific direction to which the enemy should go
     */
    void move_ice(const Direction& dir);
    /**
     * @brief function to return the direction of movement
     * @return enum of directions
     */
     bool setBlue(bool color);
     bool getBlue();

    Direction& getDirection(){return direc;}


private:
Direction direc;
bool blue;
};

class InvalidInitialIcePosition{ };
#endif // ICE_H
