#include "TicTacToe.h"
//Class constructors
TicTacToe::TicTacToe(){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            grid[i][j] = " ";
        }
    }
}

//Getters and setters.
std::string(&TicTacToe::getGrid())[3][3]{
    return this->grid;
}
std::string TicTacToe::getGridValue(int x, int y){ 
    return this->grid[x][y]; 
}
void TicTacToe::setGrid(std::string newValues[3][3]){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            this->grid[i][j] = newValues[i][j];
        }
    }
}
void TicTacToe::editGrid(int x, int y, std::string newValue){
    this->grid[x][y] = newValue; 
}

//Instance methods.
//Prints the grid values.
void TicTacToe::printGrid(){
    std::string(*occupied)[3] = this->getGrid();
    std::cout << "  1 2 3\n";
    std::cout << " =======\n";
    for(int i = 0; i < 3; i++){
        std::cout << i + 1 << "|" << occupied[i][0] << " " << occupied[i][1] << " " << occupied[i][2] << " |\n";
    }
    std::cout << " =======\n";
}
//Asks the user wich position he wants to occupy
void TicTacToe::userSelect(){
    static int selection[2];
    while(true){
        std::cout << "Elija la fila \n";
        std::cin >> selection[0];
        selection[0]--;
        std::cout << "Elija la columna \n";
        std::cin >> selection[1];
        selection[1]--;

        if(selection[0] < 0 || selection[1] < 0 || selection[0] > 2 || selection[1] > 2){ 
            std::cout << "Vuelva a ingresar los valores. El valor ingresado excede los limites. \n";
        }else if(!validSelection(selection[0], selection[1])){
            std::cout << "Esa casilla ya esta ocupada, vuelva a ingresar. \n";
        }else{
            // If everything is alright we return the selection
            this->editGrid(selection[0], selection[1], "o");
            break;
        }
        // If some error is encountered, it prints the grid again for the user to select again
        this->printGrid();
    }
}
//Checks if the position is not already occupied
bool TicTacToe::validSelection(int x, int y){
        return this->getGridValue(x, y) == " ";
}
void TicTacToe::clear(){
    system("cls");
}
//Resets the grid
void TicTacToe::reset(){ 
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            grid[i][j] = " ";
        }
    }
}
//Prints the game over screen and asks the user if he wants to play another round.
bool TicTacToe::gameOver(bool won){
    if(!won){
        std::cout << "Game Over! \n";
    }else{
        std::cout << "Felicidades! Ganaste un fulbito! \n"; 
    }
    this->printGrid();
    this->reset();
    std::cout << "Desea continuar? y/n \n";
    std::string option = "";
    std::cin >> option;
    return option == "y" ? true : false;
}
//Handles the main game loop.
void TicTacToe::run(){
    bool playAgain = true;
    int roundsPlayed = 0;
    while(playAgain){
        this->printGrid(); 
        //User turn
        this->userSelect(); 
        //Machine's turn
        std::pair<int, int> bestMove = COM::findBestMove(this->getGrid());
        this->editGrid(bestMove.first, bestMove.second, "x");
        switch(COM::evaluate(this->getGrid())){
            case -10:
                //-10 Stands for the player
                playAgain = this->gameOver(true);
                break;
            case 10:
                //10 stands for the computer
                playAgain = this->gameOver(false); 
                break;
            case 0:
                //0 Stands for draw
                if(!COM::isMovesLeft(this->getGrid())){
                    this->clear();
                    std::cout << "Empataste, ";
                    playAgain = this->gameOver(false);
                }
                break;
            default:
                //Clears the screen if not reached any terminating cases.
                this->clear();
                break;
        }
    }
}

/* int main(){
    TicTacToe* game = new TicTacToe();
    game->run();
} */