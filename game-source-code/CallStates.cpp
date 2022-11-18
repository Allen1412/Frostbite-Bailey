#include "CallStates.h"


SplashScreenState::SplashScreenState(_gameResources Data)
    : _gameData(Data)
{
}


void SplashScreenState::initial_state()
{
    Create_Screen();
}


void SplashScreenState::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void SplashScreenState::state_update()
{
}

void SplashScreenState::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}



void SplashScreenState::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::Splashscreen, filepath::splash_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::Splashscreen));
}




void SplashScreenState::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::Enter))
        _gameData->_states.adding_state(state_ptr(new MainMenuState(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}



SplashScreenState::~SplashScreenState()
{
}





//////////////////////////////////////////////////////////////////////////////////////
MainMenuState::MainMenuState(_gameResources Data)
    : _gameData(Data)
{
}

void MainMenuState::initial_state()
{
    Create_Screen();
}

void MainMenuState::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
            //    _gameData -> gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void MainMenuState::state_update()
{
}

void MainMenuState::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_menuSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void MainMenuState::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height, "Main menu",
        static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::MainMenu_, filepath::menu_file_path);
    _menuSprite.setTexture(_gameData->_resources.get_texture(Texture_::MainMenu_));
}



void MainMenuState::CheckForInput()
{

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
    if(_gameData->_input.isButtonPressed(Key::PlayButton))
        _gameData->_states.adding_state(state_ptr(new GamePlay(this->_gameData)), true);
}

MainMenuState::~MainMenuState()
{
}



////////////////////////xx////////////////////////////
GamePlay::GamePlay(_gameResources Data)
    : _gameData(Data)
{
}

void GamePlay::initial_state()
{

    Create_Screen();
    _bailey_logic =
        std::make_shared<Bailey>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);

          _bear_logic =
        std::make_shared<Bear>(GameConstants::_bearOriginalPositionX, GameConstants::_bearOriginalPositionY);

    _safe_logic=
        std::make_shared<Bailey>(GameConstants::_safeOriginalPositionX, GameConstants::_safeOriginalPositionY);

    bailey_SFML = std::make_shared<DrawBailey>(_bailey_logic, _gameData->_resources, filepath::player_file_path);
    bear_SFML = std::make_shared<DrawBear>(_bear_logic, _gameData->_resources, filepath::bear_file_path);
   // bear_SFML->ScaleBear(2.f,2.f);
    safe_SFML
     = std::make_shared<DrawBailey>(_safe_logic, _gameData->_resources, filepath::safe_file_path);


      _houses_logic=
        std::make_shared<Bailey>(GameConstants::_safeOriginalPositionX, GameConstants::_safeOriginalPositionY);


    houses_SFML = std::make_shared<DrawBailey>(_houses_logic, _gameData->_resources, filepath::safe_file_path);


    _ice_blocks = std::make_shared<IceBlocks>(GameConstants::ice_blocks_cols, GameConstants::ice_blocks_rows,
        Direction::Right, GameConstants::ice_blocks_X, GameConstants::ice_blocks_Y);

    create_ice_block_drawable(GameConstants::ice_blocks_rows, GameConstants::ice_blocks_cols, _iceSFML, _ice_blocks,
        filepath::ice_file_path);


    collisions = std::make_shared<Collissions>();
    handling_col = std::make_unique<CollisionDetection>(collisions);

    rev = 0;

}

void GamePlay::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}


void GamePlay::state_update()
{


        create_ice_block_drawable(GameConstants::ice_blocks_rows, GameConstants::ice_blocks_cols, _iceSFML, _ice_blocks,
        filepath::ice_file_path);

    if(handling_col->bear_player_col(_bailey_logic, _bear_logic))
           {
               _bailey_logic->setActiveState(false);
               _gameData->_states.adding_state(state_ptr(new GameOverLost(this->_gameData)), true);
           }


    if(handling_col->ice_player_col(_bailey_logic, _ice_blocks))
    {
         _ice_blocks->move_all(_bailey_logic);
    }
    else if (!(handling_col->ice_player_col(_bailey_logic, _ice_blocks)) && !(_bailey_logic->isTop()))
        {
            _ice_blocks->move_all_ice();
            _bailey_logic->setActiveState(false);
            _gameData->_states.adding_state(state_ptr(new GameOverLost(this->_gameData)), true);
        }
      else{
             _ice_blocks->move_all_ice();
          }

    _houses_logic=
        std::make_shared<Bailey>(GameConstants::_houses_X_position, houses_positions.at(handling_col->getBuildHouse()));

    houses_SFML =
        std::make_shared<DrawBailey>(_houses_logic, _gameData->_resources, houses.at(handling_col->getBuildHouse()));

        houses_SFML->ScaleBailey(0.5, 0.5);



  if(_bailey_logic->isLost())
        _gameData->_states.adding_state(state_ptr(new GameOverLost(this->_gameData)), true);



  if(_bailey_logic->isWon())
        _gameData->_states.adding_state(state_ptr(new GameOverWon(this->_gameData)), true);



    if(handling_col->getBuildHouse()==13 && _bailey_logic->isTop())
        _bailey_logic->move_towards_door();


       for(auto i = 0u; i < _iceSFML.size(); i++) {
        for(auto j = 0u; j < _iceSFML[i].size(); j++) {
            _iceSFML[i][j]->UpdateIceDrawable();
        }
    }

    bear_SFML->ScaleBear(_bear_logic->movement(), 1);
    bailey_SFML->UpdateDrawBailey();
    houses_SFML->UpdateDrawBailey();
    bear_SFML->UpdateDrawBear();



}


void GamePlay::draw_State()
{
    //
    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_background);
    _gameData->gameScreen_.DrawToGameScreen(*safe_SFML);

    if(handling_col->getBuildHouse()>0)
        {_gameData->gameScreen_.DrawToGameScreen(*bailey_SFML);
            _gameData->gameScreen_.DrawToGameScreen(*houses_SFML);
        }
        else{
            _gameData->gameScreen_.DrawToGameScreen(*houses_SFML);
            _gameData->gameScreen_.DrawToGameScreen(*bailey_SFML);
        }
    _gameData->gameScreen_.DrawToGameScreen(*bear_SFML);



     for(const auto& i : _iceSFML) {
        for(const auto& j : i)
            _gameData->gameScreen_.DrawToGameScreen(*j);
    }

    _iceSFML.clear();

    _gameData->gameScreen_.UpdateGameScreen();
}


void GamePlay::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height, "GamePlay",
        static_cast<uint32_t>(WindowType::NONE));
    //
    _gameData->_resources.texture_loader(Texture_::Game_Screen, filepath::game_screen_file_path);
    _background.setTexture(_gameData->_resources.get_texture(Texture_::Game_Screen));
}

void GamePlay::CheckForInput()
{

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
    //
    else if(_gameData->_input.isButtonPressed(Key::Left)) {
        _bailey_logic->move_manual(Direction::Left);
    }

    else if(_gameData->_input.isButtonPressed(Key::Right)) {
        _bailey_logic->move_manual(Direction::Right);
    }

    else if(_gameData->_input.isButtonPressed(Key::Up)) {
        _bailey_logic->move_manual(Direction::Up);
    }

    if(_gameData->_input.isButtonPressed(Key::Down)) {
        _bailey_logic->move_manual(Direction::Down);
    }

    if(_gameData->_input.isButtonPressed(Key::Reverser)) {

                if(handling_col->ice_player_col(_bailey_logic, _ice_blocks)&& handling_col->getBuildHouse()>0)
                    {rev++;
                     _ice_blocks->setReverse(rev/2);
                     handling_col->getBuildHouse() = handling_col->getBuildHouse() - 0.5f;
                    // handling_col->setBuildHouse(handling_col->getBuildHouse() + 1);
                     std::cout << "build house " << handling_col->getBuildHouse()<< std::endl;
                    }
    }


}


void GamePlay::create_ice_block_drawable(const unsigned& val,
        const unsigned& val2,
        ice_block_vec& _iceSFML,
        const ice_blocks_ptr& ice_blocks,
        const string& f1)

{

    std::vector<std::unique_ptr<DrawIceBlocks>> en;

    for(auto i = 0u; i < val2; i++) {

        for(auto j = 0u; j < val; j++) {

                auto ice =
                    std::make_unique<DrawIceBlocks>(_ice_blocks->getIceBlocks().at(i)->getIce().at(j), _gameData->_resources, f1);

                if (_ice_blocks->getIceBlocks().at(i)->getBlueCol())
                    ice->setBlueColor();
                else
                    ice->setWhiteColor();

                en.push_back(std::move(ice));
        }

        _iceSFML.push_back(std::move(en));
        en.clear();
    }
}






GameOverWon::GameOverWon(_gameResources Data)
    : _gameData(Data)
{
}

void GameOverWon::initial_state()
{
    Create_Screen();
}

void GameOverWon::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void GameOverWon::state_update()
{
}

void GameOverWon::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void GameOverWon::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::GameWon_, filepath::won_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::GameWon_));
}
void GameOverWon::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::PlayButton))
        _gameData->_states.adding_state(state_ptr(new GamePlay(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}

GameOverWon::~GameOverWon()
{
}

GameOverLost::GameOverLost(_gameResources Data)
    : _gameData(Data)
{
}

void GameOverLost::initial_state()
{
    Create_Screen();
}

void GameOverLost::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void GameOverLost::state_update()
{
}

void GameOverLost::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void GameOverLost::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::GameLost_, filepath::lost_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::GameLost_));
}
void GameOverLost::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::PlayButton))
        _gameData->_states.adding_state(state_ptr(new GamePlay(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}

GameOverLost::~GameOverLost()
{
}

