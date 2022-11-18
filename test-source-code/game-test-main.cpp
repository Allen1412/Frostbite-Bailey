#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../game-source-code/GameScreen.h"
#include "../game-source-code/Bailey.h"
#include "../game-source-code/CallStates.h"
#include "../game-source-code/CollisionDetection.h"
#include "../game-source-code/IceBlocks.h"
#include "../game-source-code/GameProperties.h"
#include "../game-source-code/Bear.h"

#include <memory>

using namespace std;

//////////////////////////TESTING SCREEN/////////////////////////////////////////
TEST_CASE("Screen dimensions not bigger than 1600x900")
{

    std::unique_ptr<GameScreen> screen_ptr;
    screen_ptr = std::make_unique<GameScreen>();
    CHECK_THROWS_AS(screen_ptr->CreateScreen(1601.f, 901.f, "Frosbite Bailey"s, sf::Style::Close), BiggerScreen);
}

//////////////////////////TESTING PLAYER/////////////////////////////////////////
/// Testing Bailey (player) movements

TEST_CASE("Bailey object can move left, right,and jump down")
{

    player_ptr _player;
    _player =
    std::make_shared<Bailey>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);

    _player->move_manual(Direction::Left);
    CHECK(_player->getPosition().xCoord < GameConstants::_playerOriginalPositionX);

    _player->move_manual(Direction::Right);
    CHECK(_player->getPosition().xCoord == GameConstants::_playerOriginalPositionX);

    _player->move_manual(Direction::Down);
    CHECK(_player->getPosition().yCoord > GameConstants::_playerOriginalPositionY);

}


TEST_CASE("Bailey object can jump up if it is on ice only not in water or on safe zone")
{

    player_ptr _player;
    _player =
    std::make_shared<Bailey>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);

    // Cannot move up on safe zone
    _player->move_manual(Direction::Up);
    CHECK(_player->getPosition().yCoord == GameConstants::_playerOriginalPositionY);

    //Cannot move up when not on Ice
    _player->move_manual(Direction::Down);
    _player->move_manual(Direction::Down);

    auto ypos = _player->getPosition().yCoord;

    _player->move_manual(Direction::Up);
    CHECK(_player->getPosition().yCoord == ypos);


    // can only move up when on ice
    _player->setIsOnIce(true);

    _player->move_manual(Direction::Up);
    CHECK(_player->getPosition().yCoord < ypos);

}

///Testing invalid initial positions of Bailey (player)

TEST_CASE("Player initial position cannot be beyond screen dimensions")
{

    player_ptr _player;
    CHECK_THROWS_AS(
        _player = std::make_shared<Bailey>((ScreenDimensions::_Screen_Width - GameConstants::playerWidth + 1.f),
            GameConstants::_playerOriginalPositionY),
        InvalidPosition);

    player_ptr _player2;
    CHECK_THROWS_AS(_player2 = std::make_shared<Bailey>(
                        (0 - 1.f), GameConstants::_playerOriginalPositionY),
        InvalidPosition);

    player_ptr _player3;
    CHECK_THROWS_AS(_player3 = std::make_shared<Bailey>(GameConstants::_playerOriginalPositionX,
                        (ScreenDimensions::_Screen_Height - GameConstants::playerHeight + 1.f)),
        InvalidPosition);

    player_ptr _player4;
    CHECK_THROWS_AS(_player4 = std::make_shared<Bailey>(
                        GameConstants::_playerOriginalPositionX, (0 - 1.f)),
        InvalidPosition);
}

///testing Bailey(Player) state

TEST_CASE("Player can be dead or alive")
{

    player_ptr _player;
    _player =
        std::make_shared<Bailey>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);
    _player->setActiveState(true);
    CHECK(_player->getActiveState());

    _player->setActiveState(false);
    CHECK_FALSE(_player->getActiveState());
}

//////////////////////////TESTING BEAR/////////////////////////////////////////

///Bear Can move to the right

TEST_CASE("Bear object moves right when started from left boundary")
{

    bear_ptr _bear;
    _bear =
    std::make_shared<Bear>(GameConstants::_bearOriginalPositionX, GameConstants::_bearOriginalPositionY);

    //Bear moves right when started from left position
    _bear->movement();
    CHECK(_bear->getPosition().xCoord > GameConstants::_bearOriginalPositionX);

}


///Bear Can move to the left

TEST_CASE("Bear object moves right when started from left boundary")
{

    bear_ptr _bear;
    _bear =
    std::make_shared<Bear>(ScreenDimensions::_Screen_Width - GameConstants::bearWidth, GameConstants::_bearOriginalPositionY);

    //Bear moves left when started from right position
    _bear->movement();
    CHECK(_bear->getPosition().xCoord > GameConstants::_bearOriginalPositionX);

}

///Bear Initial position cannot be beyond screen


TEST_CASE("Bear initial position cannot be beyond screen dimensions")
{

    bear_ptr _bear;
    CHECK_THROWS_AS(
        _bear = std::make_shared<Bear>((ScreenDimensions::_Screen_Width - GameConstants::bearWidth + 1.f),
            GameConstants::_bearOriginalPositionY),
        InvalidBearPosition);

    bear_ptr _bear2;
    CHECK_THROWS_AS(_bear2 = std::make_shared<Bear>(
                        (GameConstants::bearWidth - 1.f), GameConstants::_bearOriginalPositionY),
        InvalidBearPosition);

    bear_ptr _bear3;
    CHECK_THROWS_AS(_bear3 = std::make_shared<Bear>(GameConstants::_bearOriginalPositionX,
                        (ScreenDimensions::_Screen_Height - GameConstants::bearHeight + 1.f)),
        InvalidBearPosition);

    bear_ptr _bear4;
    CHECK_THROWS_AS(_bear4 = std::make_shared<Bear>(
                        GameConstants::_bearOriginalPositionX, (GameConstants::bearHeight - 1.f)),
        InvalidBearPosition);
}


//////////////////////////TESTING ICES/////////////////////////////////////////


// ices initial position bounds check
TEST_CASE("Ice initial position cannot be beyond screen dimensions")
{

    ice_ptr ice1;
    CHECK_THROWS_AS(
        ice1 = std::make_shared<Ice>(Direction::Right,
            ScreenDimensions::_Screen_Width - GameConstants::Ice_block_width + 1, ScreenDimensions::_Screen_Height / 2.f),
        InvalidInitialIcePosition);

    ice_ptr ice2;
    CHECK_THROWS_AS(ice2 = std::make_shared<Ice>(
                        Direction::Right, GameConstants::Ice_block_width - 1, ScreenDimensions::_Screen_Height / 2.f),
        InvalidInitialIcePosition);

    ice_ptr ice3;
    CHECK_THROWS_AS(ice3 = std::make_shared<Ice>(Direction::Right, ScreenDimensions::_Screen_Width / 2.f,
                        ScreenDimensions::_Screen_Height - GameConstants::Ice_block_height + 1),
        InvalidInitialIcePosition);

    ice_ptr ice4;
    CHECK_THROWS_AS(ice4 = std::make_shared<Ice>(
                        Direction::Right, ScreenDimensions::_Screen_Width / 2.f, GameConstants::Ice_block_height - 1),
        InvalidInitialIcePosition);
}



/// ice movements tests
TEST_CASE("Ice can move left and right")
{
    ice_ptr ice;
    ice = std::make_shared<Ice>(
        Direction::Left, ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f);

    auto x = ice->getPosition().xCoord;

    ice->move_ice(Direction::Left);
    CHECK(x > ice->getPosition().xCoord);

    ice->move_ice(Direction::Right);
    CHECK(x == ice->getPosition().xCoord);


}

/// ice appears on the other side of the screen when at left boundary
TEST_CASE("Ice can reappear at right end of screen when moving left and reaches the boundary")
{
    ice_ptr ice;
    ice = std::make_shared<Ice>(
        Direction::Left, GameConstants::Ice_block_width, ScreenDimensions::_Screen_Height / 2.f);
    auto x = ice->getPosition().xCoord;


    for(int i=0; i<15; i++)
    ice->move_ice(Direction::Left);

    CHECK(x < ice->getPosition().xCoord);

}


/// ice appears on the other side of the screen when at right boundary
TEST_CASE("Ice can reappear at left end of screen when moving right and reaches the boundary")
{
    ice_ptr ice;
    ice = std::make_shared<Ice>(
        Direction::Right, ScreenDimensions::_Screen_Width-GameConstants::Ice_block_width, ScreenDimensions::_Screen_Height / 2.f);

    auto x = ice->getPosition().xCoord;


    for(int i=0; i<15; i++)
    ice->move_ice(Direction::Right);

    CHECK(x > ice->getPosition().xCoord);

}

/// distance between column adjacent ices must be bigger than at least twice the  player width

TEST_CASE("distance between column adjacent ices is bigger than at least twice the  player width")
{
    ice_columns_ptr ice_col;
    ice_col = std::make_shared<IceColumn>(
        4,Direction::Right, GameConstants::Ice_block_width, GameConstants::ice_blocks_Y);

    CHECK(ice_col->getIce().at(1)->getPosition().xCoord-ice_col->getIce().at(0)->getPosition().xCoord > 2*GameConstants::playerWidth);

}

/// Distance between adjacent rows of ices must be greater than the player height

TEST_CASE("Distance between adjacent rows of ices is greater than the player height")
{
    ice_blocks_ptr ice_block;
    ice_block = std::make_shared<IceBlocks>(
        4,4,Direction::Right, GameConstants::Ice_block_width, GameConstants::ice_blocks_Y);

    CHECK(ice_block->getIceBlocks().at(1)->getIce().at(0)->getPosition().yCoord-ice_block->getIceBlocks().at(0)->getIce().at(0)->getPosition().yCoord > GameConstants::playerHeight);

}



/////////////////////COLLISIONS TESTING///////////////
///Player collides with ice

TEST_CASE("true if two moveable characters have collided and false otherwise")
{

    collision_ptr col = std::make_shared<Collissions>();

    player_ptr _player = std::make_shared<Bailey>(200.f, 200.f);

    ice_ptr ice;
    ice = std::make_shared<Ice>(Direction::Right, 400.f, 400.f);

    CHECK_FALSE(col->collided(_player, ice));

    ice = std::make_shared<Ice>(Direction::Left, 200.f, 200.f);

    CHECK(col->collided(_player, ice));
}


//////////////////////////TESTING COLLISION DETECTIONS/////////////////////////////////////////
/// Collision between bear and player

TEST_CASE("bailey is destroyed after collision"){

     player_ptr _player = std::make_shared<Bailey>(80.f,80.f);
     bear_ptr bear = std::make_shared<Bear>(80.f,80.f);


     collision_ptr col = std::make_shared<Collissions>();

     collision_handling_ptr handling_col = std::make_unique<CollisionDetection>(col);

    handling_col->bear_player_col(_player, bear);

    CHECK_FALSE(_player->getActiveState());

}

///Collision between ice_blocks and player


TEST_CASE("block ices collide with bailey"){

     player_ptr _player = std::make_shared<Bailey>(200.f,200.f);
     ice_blocks_ptr ice_block;

     ice_block = std::make_shared<IceBlocks>(
        4,4,Direction::Right,200.f ,200.f);


     collision_ptr col = std::make_shared<Collissions>();

     collision_handling_ptr handling_col = std::make_unique<CollisionDetection>(col);

    CHECK(handling_col->ice_player_col(_player, ice_block));


}
