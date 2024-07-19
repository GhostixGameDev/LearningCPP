#include "TicTacToe.h" 

int main()
{
    TicTacToe* game = new TicTacToe();
    game->run();
    delete game;
    return 0;
}