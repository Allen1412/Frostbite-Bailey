#ifndef DRAWBEAR_H
#define DRAWBEAR_H

#include "Bear.h"
#include <SFML/Graphics.hpp>
/**
 * @class DrawBear
 * @author Phetolo Malele
 * @date 02/10/2022
 * @file DrawBear.h
 * @brief class that draws Bear objects to the screen
 */
class DrawBear : public sf::Drawable, public sf::Transformable
{
public:
    DrawBear(const std::shared_ptr<Bear>& position, DataManagement& data, const string& path) ;
  /**
   * @brief function that keeps on drawing Bear on screen depending on its state and position
   */
    void UpdateDrawBear();
    void ScaleBear(float, float);

private:
/**
 * @brief function that draws the bear object to the screen
 * @param _target the window at which object is drawn
 * @param _states states of the object to be drawn
 */

    virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
    std::shared_ptr<Bear> _position;
    sf::Sprite _bearDrawable;
    sf::Texture _bearTex;

};


#endif // DRAWBEAR_H
