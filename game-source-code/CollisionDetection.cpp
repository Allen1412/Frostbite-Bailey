#include "CollisionDetection.h"


CollisionDetection::CollisionDetection(collision_ptr& col):_collision(col)
{
build_house = 0;
}


bool CollisionDetection::ice_player_col(player_ptr& bailey, ice_blocks_ptr& ices_ptr)
{


        for(int i =0; i<ices_ptr->getIceBlocks().size(); i++){

            for(int j = 0; j<ices_ptr->getIceBlocks().at(i)->getIce().size(); j++){

                if(_collision->collided(bailey,ices_ptr->getIceBlocks().at(i)->getIce().at(j))) {



                    bailey ->setIsOnIce(true);

                    if(!ices_ptr->getIceBlocks().at(i)->getBlueCol()){
                            ices_ptr->getIceBlocks().at(i)->setBlueCol(true);

                                   if(build_house<13)
                                        build_house++;
                    }

                    else if(ices_ptr->getTurnedWhite() != i && ices_ptr->getTurnedWhite() != 6)
                    {
                             ices_ptr->makeAllWhite();
                             ices_ptr->setTurnedWhite(6);


                    }
                    else
                        ices_ptr->setTurnedWhite(6);

                    if(ices_ptr->isAllBlue())
                         ices_ptr->setTurnedWhite(i);


                    return true;

                }
            }
        }
        bailey ->setIsOnIce(false);

        return false;
}

bool CollisionDetection::bear_player_col(player_ptr& bailey, bear_ptr& bear){

    if(_collision->collided(bailey, bear))
        {
            bailey->setActiveState(false);
            return true;
            }

    return false;
}

float& CollisionDetection::getBuildHouse(){

return build_house;
}

