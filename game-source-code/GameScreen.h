#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>

using sf::RenderWindow;


/**
 * @class GameScreen
 * @author Phetolo Malele
 * @date 19/09/2019
 * @file GameScreen.h
 * @brief class for the render window characteristics of the game
 */

class GameScreen
{
public:
    GameScreen(){}
    ~GameScreen(){}
 /**
  * @brief function to create the screen
  * @param _width width of the screen, float
  * @param _height height of the screen, float
  * @param _windowTitle title of window, string
  * @param _style type of window used
  */
    void  CreateScreen(const float& _width, const float& _height, const std::string& _windowTitle, const uint32_t& _style);
 /**
  * @brief clears the screen
  */
    void ClearScreen();
  /**
   * @brief updates the screen
   */
    void UpdateGameScreen();
  /**
   * @brief draws and object to game screen
   * @param _drawableObject takes in a drawable object
   */
    void DrawToGameScreen(const sf::Drawable& _drawableObject);
    /**
     * @brief function to close the game window
     */

    void CloseGameScreen();
   /**
    * @brief function that gets the window
    * @return returns the render window of the game
    */
    RenderWindow& getGameScreen () {return _gameScreen;}

private:
    RenderWindow _gameScreen;
};

class BiggerScreen{ };

#endif // GAMESCREEN_H
