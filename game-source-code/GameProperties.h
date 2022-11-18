#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H
// Data layer

#include "DataManagement.h"
#include "KeyInputHandler.h"
#include "StatesManager.h"
#include "GameScreen.h"
#include <SFML/Graphics.hpp> // use of textures and sprites, including the window that will be used to render the graphics of the game
#include <memory> // use of shared pointers
#include <vector>
/**
 * @class GameComponents
 * @author Phetolo Malele
 * @date 29/09/2022
 * @file GameProperties.h
 * @brief this has all the properties that are gonna be needed in the entite game
 */

using sf::RenderWindow;
using sf::Sprite;
using sf::Texture;
using std::vector;
using ScreenItem = Sprite;
// This struct is used to store the relevant objects that will be needed for the game to run

struct GameComponents {
    KeyInputHandler _input;
    StatesManager _states;  // Used for state handling
    DataManagement _resources; // Used to load the required textures, fonts, etc
    GameScreen gameScreen_;     // The window that will be used to render the screen
};

using _gameResources = std::shared_ptr<GameComponents>;

/**
 * @class Coordinates
 * @author Masabata Pule (482412) and Tsietsi Gcanga(2104199)
 * @date 29/09/2022
 * @file GameProperties.h
 * @brief all coordinates for the game
 */


struct Coordinates {
    float xCoord;
    float yCoord;

    Coordinates()
        : xCoord(0.f)
        , yCoord(0.f)
    {
    }
    Coordinates(const float& xCo, const float& yCo)
        : xCoord(xCo)
        , yCoord(yCo)
    {
    }
    Coordinates(const Coordinates& _rhs)
        : xCoord(_rhs.xCoord)
        , yCoord(_rhs.yCoord)
    {
    }

    void operator=(const Coordinates& _rhs)
    {
        this->xCoord = _rhs.xCoord;
        this->yCoord = _rhs.yCoord;
    }

    bool operator==(const Coordinates& _rhs) const
    {
        if((this->xCoord == _rhs.xCoord) && (this->yCoord == _rhs.yCoord))
            return true;
        else
            return false;
    }

    bool operator<=(const Coordinates& _rhs) const
    {
        if((this->xCoord <= _rhs.xCoord) && (this->yCoord <= _rhs.yCoord)) {
            return true;
        } else
            return false;
    }
};



struct Size {
    float height_ = 50.0f;
    float width_ = 55.0f;
};


enum class WindowType { NONE = 0, FULLSCREEN = 1 << 3, DEFAULT = 1 << 0 | 1 << 1 | 1 << 2 };

// Direction of movement
enum class Direction { Up, Down, Left, Right, Nowhere };
// Used for determining movement speeds
const float delta = 1.0f / 60.f; // Required for drawing objects to screen



struct GameScreenSize {
    GameScreenSize(const float& _width = 1000.f, const float& _height = 650.f)
        : width_(_width)
        , height_(_height)
    {
    }
    float width_;
    float height_;
};

// Dimensions of the screen, from splash screen, to game play
namespace ScreenDimensions
{
const float _Screen_Width = 900.f;
const float _Screen_Height = 563.f;
}

namespace GameObjectSpeed
{
const float _playerVerticalSpeed = 80*60;
const float _playerHorizontalSpeed = 1000.f;

const float _iceBlockSpeed = 1000.f;
const float _gravitySpeed = 80.f;

const float _bearSpeed = 100.f;
const float _toHouseSpeed = 150.f;
};

namespace filepath
{
const std::string splash_file_path = "resources/images/Splash_Background.jpg";
const std::string menu_file_path = "resources/images/Main_menu.jpg";
const std::string player_file_path = "resources/images/Bailey.png";
const std::string bear_file_path = "resources/images/Bear.png";
const std::string game_screen_file_path = "resources/images/water2.png";
const std::string ice_file_path = "resources/images/white_Ice.png";
const std::string safe_file_path = "resources/images/stripline.png";
const std::string house1 = "resources/images/image1.png";
const std::string house2 = "resources/images/image2.png";
const std::string house3 = "resources/images/image3.png";
const std::string house4 = "resources/images/image4.png";
const std::string house5 = "resources/images/image5.png";
const std::string house6 = "resources/images/image6.png";
const std::string house7 = "resources/images/image7.png";
const std::string house8 = "resources/images/image8.png";
const std::string house9 = "resources/images/image9.png";
const std::string house10 = "resources/images/image10.png";
const std::string house11 = "resources/images/image11.png";
const std::string house12 = "resources/images/image12.png";
const std::string house13 = "resources/images/image13.png";

const std::string won_file_path = "resources/images/_game_over_w.png";
const std::string lost_file_path = "resources/images/_game_over_lost.png";

}

namespace GameConstants
{

const float playerWidth = 32.f;
const float playerHeight = 40.f;
const float playerWidth_or = 0.f;
const float playerHeight_or = 0.f;

const float bearWidth = 60.f;
const float bearHeight = 40.f;
const float bearWidth_or = 0.f;
const float bearHeight_or = 0.f;

const float Ice_block_width = 93.f;
const float Ice_block_height = 13.f;
const float Ice_block_width_or = 0.f;
const float Ice_block_height_or = 0.f;

const float safe_zone_width = ScreenDimensions::_Screen_Width;
const float safe_zone_height = 140.0f;
const float safe_zone_width_or = 0.f;
const float safe_zone_height_or = 0.f;

const int ice_blocks_rows = 4;
const int ice_blocks_cols = 4;

const int ice_blocks_X = Ice_block_width;
const int ice_blocks_Y = safe_zone_height + GameObjectSpeed::_playerVerticalSpeed/60;

const float _playerOriginalPositionX = (ScreenDimensions::_Screen_Width)/2 + playerWidth;
const float _playerOriginalPositionY = safe_zone_height - playerHeight;

const float _bearOriginalPositionX = bearWidth;
const float _bearOriginalPositionY = safe_zone_height - bearHeight;

const float _safeOriginalPositionX = 0;
const float _safeOriginalPositionY = 0;

const float _house1Position = safe_zone_height-95;
const float _house2Position = safe_zone_height-95;
const float _house3Position = safe_zone_height - 95;
const float _house4Position = safe_zone_height - 95;
const float _house5Position = safe_zone_height - 110;
const float _house6Position = safe_zone_height - 110;
const float _house7Position = safe_zone_height - 110;
const float _house8Position = safe_zone_height - 110;
const float _house9Position = safe_zone_height - 125;
const float _house10Position = safe_zone_height - 125;
const float _house11Position = safe_zone_height - 125;
const float _house12Position = safe_zone_height - 125;
const float _house13Position = safe_zone_height - 140;
const float _houses_X_position = ScreenDimensions::_Screen_Width - 160;//120+40

const float housesFinalWidth = 120;
const float housesFinalHeight = 120;



}

#endif // GAMEPROPERTIES_H
