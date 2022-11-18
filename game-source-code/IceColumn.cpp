#include "IceColumn.h"

IceColumn::IceColumn(const unsigned& cap, const Direction& dir, const float& xpos, const float& ypos)
{
    capacity = cap;
    x = xpos;
    y = ypos;
    initial_movement = dir;
    blue_col = false;

    auto space_between_ice_blocks = 2*(GameConstants::Ice_block_width);


    for(auto i = 0u; i < capacity; i++) {

            auto ice = std::make_shared<Ice>(initial_movement, x + i * space_between_ice_blocks, y);
            ices.push_back(ice);
    }
}


void IceColumn::moving_all(const Direction& dir)
{

    for(auto i = 0u; i < ices.size(); i++) {
        ices.at(i)->move_ice(dir);
    }
}

bool IceColumn::setBlueCol(bool colorSet){

blue_col = colorSet;
}
bool IceColumn::getBlueCol(){
return blue_col;
}
