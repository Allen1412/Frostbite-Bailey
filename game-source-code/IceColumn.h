#ifndef ICECOLUMN_H
#define ICECOLUMN_H

#include "Ice.h"
#include <vector>
using ice_ptr = std::shared_ptr<Ice>;
using ice_vector = std::vector<ice_ptr>;

/**
 * @class IceColumn
 * @author Phetolo Malele
 * @date 04/10/2022
 * @file IceColumn.h
 * @brief class that models a row of Ices as a vector
 */

class IceColumn
{
public:
    IceColumn(const unsigned& cap, const Direction& dir,const float& xpos, const float& ypos);
    /**
     * @brief function that gets the armada vector
     * @return vector type, armada vector
     */
    ice_vector& getIce()
    {
        return ices;
    }
    /**
     * @brief function that moves all the armada
     * @param dir direction of movement
     */
    void moving_all(const Direction& dir);
    bool setBlueCol(bool colorSet);
    bool getBlueCol();

private:
    unsigned capacity;
    float x, y;
    bool blue_col;

    Direction initial_movement;
    ice_vector ices;

    /**
     * @brief function that moves all ice blocks,or turns them
     * @param dir direction of movement
     */
    void move_all(const Direction& dir);
};

#endif // ICECOLUMN_H
