#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "IceBlocks.h"
#include "Collissions.h"
#include "Bailey.h"
#include "Bear.h"

#include <iostream>

using player_ptr = std::shared_ptr<Bailey>;
using collision_ptr = std::shared_ptr<Collissions>;
using ice_blocks_ptr = std::shared_ptr<IceBlocks>;
using bear_ptr = std::shared_ptr<Bear>;

/**
 * @class CollisionDetection
 * @author Phetolo Malele
 * @file CollisionDetection.h
 * @brief class that takes care of collisions between particular objects
 */
class CollisionDetection
{
public:
    CollisionDetection();
    CollisionDetection(collision_ptr& col);
    ~CollisionDetection()
    {
    }
    /**
     * @brief function to detect collision between Ice and player
     */
    bool ice_player_col(player_ptr& bailey, ice_blocks_ptr& ices_ptr);
    bool bear_player_col(player_ptr& bailey, bear_ptr& bear);
    float& getBuildHouse();


private:
    collision_ptr _collision;
    float build_house;
};
#endif // COLLISIONDETECTION_H
