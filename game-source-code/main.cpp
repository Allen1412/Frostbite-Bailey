#include "PlayGame.h"
#include <memory>
#include <iostream>

int main()
{
    auto game_ = std::make_unique<PlayGame>();
    game_->execute_game_logic();

    return 0;
}
