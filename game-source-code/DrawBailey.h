#ifndef DRAWBAILEY_H
#define DRAWBAILEY_H

#include "Bailey.h"
#include <SFML/Graphics.hpp>
/**
 * @class DrawBailey
 * @author Phetolo Malele
 * @date 02/10/2022
 * @file DrawBailey.h
 * @brief class that draws player objects to the screen
 */
class DrawBailey : public sf::Drawable, public sf::Transformable
{
public:
    DrawBailey(const std::shared_ptr<Bailey>& position, DataManagement& data, const string& path) ;
  /**
   * @brief function that keeps on drawing player on screen depending on its state and position
   */
    void UpdateDrawBailey();

    void ScaleBailey(float, float);

private:
/**
 * @brief function that draws the player object to the screen
 * @param _target the window at which object is drawn
 * @param _states states of the object to be drawn
 */

    virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
    std::shared_ptr<Bailey> _position;
    sf::Sprite _playerDrawable;
    sf::Texture _playerTex;

};

#endif // DRAWBAILEY_H
