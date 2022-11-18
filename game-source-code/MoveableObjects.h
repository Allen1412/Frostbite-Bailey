#ifndef MOVEABLEOBJECTS_H
#define MOVEABLEOBJECTS_H

#include "GameObjects.h"
#include "GameProperties.h"

#include <iostream>

/**
 * @class MoveableObjects
 * @author Phetolo Malele
 * @date 01/10/2022
 * @file MoveableObjects.h
 * @brief class to model every moveable character
 */


class MoveableObjects : public GameObjects
{
public:
    MoveableObjects()
        : isActive(true)
    {
    }
    virtual ~MoveableObjects()
    {
    }
/**
 * @brief virtual voud function to set the position of any moveable character
 * @param x_pos the x-coordinate of a moveable character
 * @param y_pos the y-coordinate of a moveable character
 */
    virtual void setPosition(const float& x_pos, const float& y_pos) override;
/**
 * @brief function that sets the size of any moveable character
 * @param _xmin minimum width of a moveable character
 * @param _ymin minimum height of a moveable character
 * @param _xmax maximum width of any moveable character
 * @param _ymax maximum height of any moveable character
 */
    virtual void setSize(const float& _xmin = 0.f,
        const float& _ymin = 0.f,
        const float& _xmax = 100.f,
        const float& _ymax = 100.f) override;
/**
 * @brief function getter, that gets the position of any moveable character
 * @return position of moveable character
 */
    virtual Coordinates getPosition() const override
    {
        return position_;
    }
    /**
     * @brief getter for the size of the character
     * @return size of any moveable character, type size
     */

    virtual Size getSize() const override
    {
        return size_;
    }

/**
 * @brief function getter to
 * @return speed of moveable character, float type
 */
    float getHorizontalSpeed() const
    {
        return horizontal_speed;
    }

    float getVerticalSpeed() const
    {
        return vertical_speed;
    }

/**
 * @brief function to return the state of a moveable character
 * @return returns the state, boolean
 */
    virtual bool getActiveState() const override
    {
        return isActive;
    }
    /**
     * @brief function to set the state of a moveable character, sets true or false
     * @param _flag boolean character that sets the state of a moveable character
     */

    virtual void setActiveState(const bool& _flag) override
    {
        isActive = _flag;
    }

protected:
/**
 * @brief function to move character
 * @param direction parameter to determine the direction of movement
 */
    virtual void move(const Direction& direction);
    /**
     * @brief function to move a moveable character up
     */

    void jump_up();
/**
 * @brief function to move a moveable character down
 */
    void jump_down();
/**
 * @brief function to move a character to the left
 */
    void move_left();
/**
 * @brief function that moves a character to the right
 */
    void move_right();
    /**
     * @brief functions that set both the horizontal and vertical speeds of all moveable characters
     * @param _speed the speed of which a specific character moves
     */

    void setHorizontalSpeed(const float& horizontal_speed);
    void setVerticalSpeed(const float& vertical_speed);
/**
 * @brief function to change the position of a specific moveable character
 * @param x_pos the new x-coordinate, float
 * @param y_pos the new y-coordinate, float
 */
    void changePosition(const float& x_pos, const float& y_pos);

private:
    double horizontal_speed, vertical_speed;
    Coordinates position_;
    Size size_;
    bool isActive;
};

#endif // MOVEABLEOBJECTS_H
