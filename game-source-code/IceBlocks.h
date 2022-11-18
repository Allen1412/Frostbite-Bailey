#ifndef ICEBLOCKS_H
#define ICEBLOCKS_H

#include <ctime>
#include <vector>
#include "IceColumn.h"

#include "Bailey.h"

using ice_column_ptr = std::shared_ptr<IceColumn>;
using ice_column_vector = std::vector<ice_column_ptr>;
using bailey_ptr = std::shared_ptr<Bailey>;

/**
 * @class IceBlocks
 * @author Phetolo Malele
 * @date 04/10/2022
 * @file IceBlocks.h
 * @brief class that models all Ice blocks
 */

class IceBlocks{
    public:

    IceBlocks(const unsigned& capx, const unsigned& capy, const Direction& dir,
        const float& xpos,
        const float& ypos);
    /**
     * @brief function that gets the vector of Ice blocks by reference
     * @return returns a vector of armadas
     */
    ice_column_vector &getIceBlocks(){return ice_blocks;}
    /**
     * @brief function to move the army
     */
    void move_all(bailey_ptr bailey);
    void move_all_ice();
    void setReverse(int rev);

    bool isAllBlue();
    void makeAllWhite();
    void setTurnedWhite(int);
    int getTurnedWhite();


    /**
     * @brief function used to delay movement
     * @return boolean, true if time delay is greater than 5 seconds false otherwise
     */

    bool delay();

private:

    ice_column_vector ice_blocks;
    float x,y;
    Direction init;
    unsigned capacityX, capacityY;
    float initial_tme, delta_time;
    int turned_white_row;
    int reversing;
    /**
     * @brief function that moves all the army
     * @param dir direction of movement of all army
     */
    void move_all_ice_blocks(const Direction& dir1, const Direction& dir2);

    };

#endif // ICEBLOCKS_H
