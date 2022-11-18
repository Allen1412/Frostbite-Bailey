#include "DrawBear.h"

DrawBear::DrawBear(const std::shared_ptr<Bear>& position, DataManagement& data, const string& path) : _position(position)
{
    data.texture_loader(Texture_::Bear_, path);

    _bearTex = data.get_texture(Texture_::Bear_);
    _bearDrawable.setTexture(_bearTex);
}




void DrawBear::UpdateDrawBear()
{
    _bearDrawable.setPosition(_position->getPosition().xCoord, _position->getPosition().yCoord);
}





void DrawBear::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{

    _target.draw(_bearDrawable);

}

void DrawBear::ScaleBear(float x_scale, float y_scale){
    _bearDrawable.setScale(x_scale, y_scale);
}
