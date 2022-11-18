#ifndef CALLSTATES_H
#define CALLSTATES_H

#include "GameProperties.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

//main game files included
#include "Bailey.h"
#include "DrawBailey.h"
#include "IceBlocks.h"
#include "DrawIceBlocks.h"
#include "CollisionDetection.h"
#include "Bear.h"
#include "DrawBear.h"

#include <vector>

/**
 * @class SplashState
 * @author Phetolo Malele
 * @date 29/09/2022
 * @file CallStates.h
 * @brief class for outputting the splash state of the game
 */

class SplashScreenState : public State
{
public:
    SplashScreenState(_gameResources Data);
    ~SplashScreenState();
    /**
     * @brief initial conditions for splash state
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief splash state updated
     */
    virtual void state_update() override; // update the state
    /**
     * @brief checking for inputs and responding to them
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief drawing changes to splash state
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _backSprite;
    GameScreenSize _screen_size{ ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height };
    /**
     * @brief function to create screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function that checks for inputs
     */
    virtual void CheckForInput() override;
};





/**
 * @class MainMenuState
 * @author Phetolo Malele
 * @date 30/09/2022
 * @file CallStates.h
 * @brief class for displaying the main menu state, executed after user presses enter
 */

class MainMenuState : public State
{
public:
    MainMenuState(_gameResources Data);
    ~MainMenuState();
    /**
     * @brief initial conditions for main menu
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief main menu state updated
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function that handles inputs for main menu
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function that draws main menu objects
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _menuSprite;
    /**
     * @brief function to create screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function to check for inputs
     */
    virtual void CheckForInput() override;
};


//Aliasing
using player_ptr = std::shared_ptr<Bailey>;
using bear_ptr = std::shared_ptr<Bear>;

using ice_ptr = std::shared_ptr<Ice>;
using ice_columns_ptr = std::shared_ptr<IceColumn>;
using ice_blocks_ptr = std::shared_ptr<IceBlocks>;
using ice_block_vec = std::vector<vector<std::unique_ptr<DrawIceBlocks>>>;

 using collision_handling_ptr = std::unique_ptr<CollisionDetection>;

/**
 * @class GamePlay
 * @author Phetolo Malele
 * @date 02/10/2022
 * @file CallStates.h
 * @brief class to model the game playing state of the game, called after user presses P
 */


class GamePlay : public State
{
public:
    GamePlay(_gameResources Data);
    ~GamePlay();

    /**
     * @brief function to initialise game mode state
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief function to update game mode state
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function to handle inputs on game mode state
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function to draw objects on screen from game mode state
     */
    virtual void draw_State() override; // draw the new state
    //
    //
private:
    _gameResources _gameData;
    ScreenItem _background;

    std::vector<std::string> houses{filepath::safe_file_path, filepath::house1, filepath::house2, filepath::house3, filepath::house4, filepath::house5, filepath::house6, filepath::house7, filepath::house8, filepath::house9, filepath::house10, filepath::house11, filepath::house12, filepath::house13};
    std::vector<float> houses_positions{GameConstants::_safeOriginalPositionY,GameConstants::_house1Position, GameConstants::_house2Position, GameConstants::_house3Position, GameConstants::_house4Position, GameConstants::_house5Position, GameConstants::_house6Position, GameConstants::_house7Position, GameConstants::_house8Position, GameConstants::_house9Position, GameConstants::_house10Position, GameConstants::_house11Position, GameConstants::_house12Position, GameConstants::_house13Position};

    std::shared_ptr<DrawBailey> bailey_SFML;
    std::shared_ptr<DrawBailey> safe_SFML;
    std::shared_ptr<DrawBailey> houses_SFML;
    std::shared_ptr<DrawBear> bear_SFML;
    player_ptr _bailey_logic;
    player_ptr _safe_logic;
    player_ptr _houses_logic;
    bear_ptr _bear_logic;

    ice_ptr _ice;
    ice_blocks_ptr _ice_blocks;
    ice_block_vec _iceSFML;


    collision_handling_ptr handling_col;
    collision_ptr collisions;

    int rev;


     /**
     * @brief function to update the drawable objects
     * @param val columns of enemies
     * @param val2 row of enemies
     * @param _arm vector of army objects for presentation
     * @param _armyy pointer of army
     * @param fl filepath
     */
    void create_ice_block_drawable(const unsigned& val,
        const unsigned& val2,
        ice_block_vec& _iceSFML,
        const ice_blocks_ptr& ice_blocks,
        const string& fl);
    /**
     * @brief function to create screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function to check inputs
     */
    virtual void CheckForInput() override;
};



/**
 * @class GameOverWon
 * @author Phetolo Malele
 * @date 18/10/2022
 * @file CallStates.h
 * @brief the game winning state class of the game
 */
class GameOverWon : public State
{

public:
    GameOverWon(_gameResources Data);
    ~GameOverWon();
    /**
     * @brief function to initialise the state
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief function that updates the state
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function that handles inputs in the game_over state
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function that draws objects to the screen
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _backSprite;
    /**
     * @brief function that creates the screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function that checks for inputs
     */
    virtual void CheckForInput() override;
};

/**
 * @class GameOverLost
 * @author Phetolo Malele
 * @date 18/10/2022
 * @file CallStates.h
 * @brief the game lost state class of the game
 */
class GameOverLost : public State
{

public:
    GameOverLost(_gameResources Data);
    ~GameOverLost();

    virtual void initial_state() override; // initialise the state
    /**
     * @brief function to update the state
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function that handles the inputs
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function to draw the state
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _backSprite;
    /**
     * @brief function that creates the screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function that checks for inputs
     */
    virtual void CheckForInput() override;
};



#endif // CALLSTATES_H
