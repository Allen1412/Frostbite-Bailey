#ifndef DRAWICEBLOCKS_H
#define DRAWICEBLOCKS_H

#include "Ice.h"
#include <SFML/Graphics.hpp>
/**
 * @class DrawIceBlocks
 * @author Phetolo Malele
 * @date 04/10/2022
 * @file DrawIceBlocks.h
 * @brief class to draw ice blocks on screen
 */

class DrawIceBlocks : public sf::Drawable, public sf::Transformable
{
public:
    DrawIceBlocks(const std::shared_ptr<Ice>& position, DataManagement& data, const string& path) ;
  /**
   * @brief function to update what needs to be presented
   */
    void UpdateIceDrawable();
    void setBlueColor();
    void setWhiteColor();

private:
  /**
   * @brief function to draw the object
   * @param _target to draw to
   * @param _states of the object to be drawn
   */
    virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
    std::shared_ptr<Ice> _position;
    sf::Sprite _IceDrawable;
    sf::Texture _IceTex;

};
#endif // DRAWICEBLOCKS_H
