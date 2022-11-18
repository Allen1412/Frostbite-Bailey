#include "PlayGame.h"

PlayGame::PlayGame()
{
   _gameData = std::make_shared<GameComponents>();
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width,ScreenDimensions::_Screen_Height, "Frostbite Bailey", sf::Style::Close);
    _gameData->_states.adding_state(state_ptr(new SplashScreenState(this->_gameData)));
}

PlayGame::~PlayGame(){}

void PlayGame::execute_game_logic()
{
    auto newTime = 0.f;
    auto TimeBetweenFrames = 0.f;
    auto currentTime = _gameClock.getElapsedTime().asSeconds();

    auto delay_ = 0.f;


    while(_gameData->gameScreen_.getGameScreen().isOpen())
    {
        _gameData->_states.updating_state();
        newTime = _gameClock.getElapsedTime().asSeconds();
        TimeBetweenFrames = newTime - currentTime;

        if(TimeBetweenFrames > 0.4)
        {
            TimeBetweenFrames = 0.4;
        }
        currentTime = newTime;
        delay_ += TimeBetweenFrames;
        while (delay_ >= delta)
        {
            _gameData->_states.get_current_state()->input_handler();
            _gameData->_states.get_current_state()->state_update( );
            delay_ -= delta;
        }

        _gameData->_states.get_current_state()->draw_State();
    }
}
