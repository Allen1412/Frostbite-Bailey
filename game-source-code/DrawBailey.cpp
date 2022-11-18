#include "DrawBailey.h"

DrawBailey::DrawBailey(const std::shared_ptr<Bailey>& position, DataManagement& data, const string& path) : _position(position)
{
    data.texture_loader(Texture_::Player_, path);

    _playerTex = data.get_texture(Texture_::Player_);
    _playerDrawable.setTexture(_playerTex);
}



void DrawBailey::ScaleBailey(float x_scale, float y_scale){
    _playerDrawable.setScale(x_scale, y_scale);
}


void DrawBailey::UpdateDrawBailey()
{
    _playerDrawable.setPosition(_position->getPosition().xCoord, _position->getPosition().yCoord);
}





void DrawBailey::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{

    _target.draw(_playerDrawable);

}
