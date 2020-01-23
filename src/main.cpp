#include "Game.hpp"

int main()
{
    Game* game = new Game();

    game->play();

    delete game;
    
    return 0;
}