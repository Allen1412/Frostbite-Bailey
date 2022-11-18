#include "GameScreen.h"

 void GameScreen::CreateScreen(const float& _width, const float& _height, const std::string& _windowTitle, const uint32_t& _style)
{
     if(_width > 1600 || _height > 900)
        throw BiggerScreen{};
    _gameScreen.create(sf::VideoMode(_width, _height), _windowTitle, _style);
    _gameScreen.setVerticalSyncEnabled(true);
}

 void GameScreen::UpdateGameScreen()
{
     _gameScreen.display();
}

 void GameScreen::ClearScreen()
{
    _gameScreen.clear();
}

 void GameScreen::DrawToGameScreen(const sf::Drawable& _drawableObject)
{
    _gameScreen.draw(_drawableObject);
}

 void GameScreen::CloseGameScreen()
{
    _gameScreen.close();
}
