#include "IceBlocks.h"

IceBlocks::IceBlocks(const unsigned& capx,
    const unsigned& capy,
    const Direction& dir,
    const float& xpos,
    const float& ypos)
{

    capacityX = capx;
    capacityY = capy;
    init = dir;
    x = xpos;
    y = ypos;
    turned_white_row = 6;
    reversing = 0;

    initial_tme = clock();

    auto space_between_ice_blocks = (GameObjectSpeed::_playerVerticalSpeed/60);

    for(auto i = 0u; i < capacityY; i++) {
                auto ice_block = std::make_shared<IceColumn>(capacityX, init, x, y + i*space_between_ice_blocks);
                ice_blocks.push_back(ice_block);
    }
}


void IceBlocks::move_all(bailey_ptr bailey)
{
    Direction direc1;
    Direction direc2;

    if (reversing%2 == 0){
        direc1 = Direction::Left;
        direc2 = Direction::Right;
    }else{

        direc1 = Direction::Right;
        direc2 = Direction::Left;
    }

    if(delay())
            {move_all_ice_blocks(direc1, direc2);
             bailey->move_with_ice(direc1);
            }
}


void IceBlocks::move_all_ice()
{
    Direction direc1;
    Direction direc2;

    if (reversing%2 == 0){
        direc1 = Direction::Left;
        direc2 = Direction::Right;
    }else{

        direc1 = Direction::Right;
        direc2 = Direction::Left;
    }

    if(delay())
            move_all_ice_blocks(direc1,direc2);
}


bool IceBlocks::delay()
    {

        delta_time = clock() - initial_tme;

        if((delta_time / 1000.f) >= 0.3f) {
            initial_tme = clock();
            return true;
        }

        return false;
    }



void IceBlocks::move_all_ice_blocks(const Direction& dir1, const Direction& dir2)
    {

        for(unsigned i = 0; i < ice_blocks.size(); i++) {

                if(i ==1 || i==3)
                  ice_blocks.at(i)->moving_all(dir1);
                else
                    ice_blocks.at(i)->moving_all(dir2);


        }
    }


bool IceBlocks::isAllBlue(){


            for(int i = 0; i<ice_blocks.size(); i++){

                if(!ice_blocks.at(i)->getBlueCol())
                    return false;


            }
    return true;
}


void IceBlocks::makeAllWhite(){


        for(int i = 0; i<ice_blocks.size(); i++)
                ice_blocks.at(i)->setBlueCol(false);


}


void IceBlocks::setTurnedWhite(int _turnedWhite){

    turned_white_row = _turnedWhite;
}
int IceBlocks::getTurnedWhite(){

    return turned_white_row;
}

void IceBlocks::setReverse(int rev){

    reversing = rev;
}
