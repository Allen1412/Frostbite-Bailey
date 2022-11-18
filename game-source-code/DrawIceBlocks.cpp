#include "DrawIceBlocks.h"

DrawIceBlocks::DrawIceBlocks(const std::shared_ptr<Ice>& position, DataManagement& data, const string& path) : _position(position)
{
    data.texture_loader(Texture_::Ice_, path);

    _IceTex = data.get_texture(Texture_::Ice_);
    _IceDrawable.setTexture(_IceTex);
}




void DrawIceBlocks::UpdateIceDrawable()
{
    _IceDrawable.setPosition(_position->getPosition().xCoord, _position->getPosition().yCoord);
}





void DrawIceBlocks::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{

    _target.draw(_IceDrawable);

}

void DrawIceBlocks::setBlueColor(){

      _IceDrawable.setColor(sf::Color::Blue);
}
void DrawIceBlocks::setWhiteColor(){

    _IceDrawable.setColor(sf::Color::White);
}
