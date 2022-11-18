#include "Collissions.h"


bool Collissions::collided(const std::shared_ptr<MoveableObjects>& char_1,
    const std::shared_ptr<MoveableObjects>& char_2)
{
    auto minDY = (char_1->getSize().width_ + char_2->getSize().width_)/2.5;

    // calculating central positions
    auto x1_plus_x1_over_2 = char_1->getPosition().xCoord + char_1->getSize().width_/2;
    auto x2_plus_x2_over_2 = char_2->getPosition().xCoord + char_2->getSize().width_/2;
    auto y1_plus_y1_over_2 = char_1->getPosition().yCoord + char_1->getSize().height_/2;
    auto y2_plus_y2_over_2 = char_2->getPosition().yCoord + char_2->getSize().height_/2;

    auto dis = calculateDistance(x1_plus_x1_over_2, y1_plus_y1_over_2, x2_plus_x2_over_2, y2_plus_y2_over_2);

    if(dis< minDY )
        return true;

    return false;
}



float Collissions::calculateDistance(const float& x1, const float& y1, const float& x2, const float& y2)
{

    auto distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distance;
}
