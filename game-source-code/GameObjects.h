#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "GameProperties.h"

/**
 * @class GameObjects
 * @author Phetolo Malele
 * @date 01/10/2022
 * @file GameObjects.h
 * @brief class to model objects of the game (Moving and static)
 */

class GameObjects
{
public:
/**
 * @brief function to set the size of objects
 * @param _xmin x_coord minimum size of object
 * @param _ymin y_coord minimum size of object
 * @param _xmax x_coord maximum size of object
 * @param _ymax y_coord maimum size of object
 */

    virtual void setSize(const float& _xmin = 0.f,
        const float& _ymin = 0.f,
        const float& _xmax = 100.f,
        const float& _ymax = 100.f) = 0;

    /**
     * @brief function to set position of object
     * @param x_pos x_coord of object
     * @param y_pos y_coord of object
     */
    virtual void setPosition(const float& x_pos, const float& y_pos) = 0;
    /**
     * @brief function to get the position of an object
     * @return
     */
    virtual Coordinates getPosition() const = 0;
/**
 * @brief function to get the size of an object
 * @return
 */
    virtual Size getSize() const = 0;
/**
 * @brief function to get the state of an object
 * @return true if state is active and false otherwise
 */
    virtual bool getActiveState() const = 0;
/**
 * @brief function to set the state of the object
 * @param _flag true sets the state to be active and false sets the state to be non-active
 */
    virtual void setActiveState(const bool& _flag) = 0;
};

#endif // GAMEOBJECTS_H
