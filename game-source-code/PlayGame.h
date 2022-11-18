#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "GameProperties.h"
#include "CallStates.h"


typedef sf::Clock gameClock;
/**
 * @class PlayGame
 * @author Phetolo Malele
 * @date 27/09/2022
 * @file PlayGame.h
 * @brief class that manages the logic of the game
 */


class  PlayGame{
public:
PlayGame();
~PlayGame();
          /**
         * @brief function that executes the game logic while window is open
         */
        void execute_game_logic();
private:
gameClock _gameClock;
_gameResources _gameData;


    };

#endif // PLAYGAME_H
