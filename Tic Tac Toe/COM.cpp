#include "COM.h"
   
std::pair<int, int> COM::findBestMove(std::string (&grid)[3][3]){
    //This method will use the minimax method to return the best move the COM can do.
    int bestValue = -1000; //Start bestValue at a very low one to ensure any valid move will have a higher one.
    std::pair<int, int> bestMove ={-1, -1}; //Initializing it at an invalid position.
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            //Loop through all cells and place X on the empty ones
            if(grid[i][j] == " "){
                grid[i][j] = "x";
                //Simulate a move and then run the minimax simulation to determine if it is the best move.
                int moveValue = minimax(grid, 0, false); //Minimax is called with isMaximizing = false because the next move should be for the minimizingPlayer (USER).
                grid[i][j] = " "; //Undo the simulated move
                //If this move is determined to be the best one (By the minimax returned values on each loop)
                //then update the bestValue to the moveValue and store it into the bestMove pair.
                if(moveValue > bestValue){
                    bestMove ={i, j};
                    bestValue = moveValue;
                }
            }
        }
    }
    //After simulating all possible moves in search for the best one, return the best.
    return bestMove;
}
int COM::evaluate(const std::string (&grid)[3][3]){
        //This method will return a score based on the occupied cells with X.
        //10 Stands for win, -10 for lose and 0 for draw.
        for(int i = 0; i<3; i++){
            if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != " "){
                return(grid[i][0] == "x") ? 10 : -10;
            }
        }

        for(int col = 0; col < 3; ++col){
            if(grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col] && grid[0][col] != " "){
                return(grid[0][col] == "x") ? 10 : -10;
            }
        }

        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != " "){
            return(grid[0][0] == "x") ? 10 : -10;
        }
        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != " "){
            return(grid[0][2] == "x") ? 10 : -10;
        }

        return 0;
}

//This method checks if there is room left for moves.
bool COM::isMovesLeft(const std::string (&grid)[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i][j] == " "){
                return true;
            }
        }
    }
    return false;
}

int COM::minimax(std::string (&grid)[3][3], int depth, bool isMaximizing){
    //This will simulate every possible move and its counter, trying to maximize the 
    //Maximizing player (COM) score, and make the minimizing player (USER) achieve the lowest
    //Possible score.
    //At the end it will return a value used to make the best move at the current state of the game.

    //depth: The number of moves simulated (Game Tree Depth).
    //isMaximizing: Indicates if the current movement simulation is for the maximizing player (COM) or the minimizing one (USER).

    //Evaluates the grid and returns a score determined by who is ocuppying each cell, It checks if it is in a terminal state.
    int score = COM::evaluate(grid);
    //Positive scores represent advantageus positions for the maximizing player (In this case the computer)

    //This if statements will stop the recursive simulation in terminating cases.
    if(score == 10){
        return score - depth; //Computer wins, substract depth to prefer faster wins.
    }
    //Negative scores represent avantageus positions for the minimizing player (In this case the player/user)
    if(score == -10){
        return score + depth; //Player wins, add the depth to prefer slower losses.
    }
    //Zero represents a draw, checked by the isMovesLeft method.
    if(!COM::isMovesLeft(grid)){
        return 0;
    }
    if(isMaximizing){
        //COM Maximizing
        //Initialize best at a very low value
        int best = -1000;
        //Loop through all cells in the grid.
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(grid[i][j] == " "){
                    //For each empty cell simulate placing X on it
                    grid[i][j] = "x";
                    //Recursively call minimax with the next depth switching between Player and COM
                    best = std::max(best, minimax(grid, depth + 1, !isMaximizing)); //Update best with the maximum value returned by the recursive call
                    grid[i][j] = " "; //Clean the simulation
                }
            }
        }
        return best; //Return best as the best possible score the COM (Maximizer) can achieve from this move.
    }else{
        //PLAYER MINIMIZING
        //Initialize best at a very high value
        int best = 1000;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(grid[i][j] == " "){
                    grid[i][j] = "o";
                    //Recursively call minimax with the next depth switching between Player and COM
                    best = std::min(best, minimax(grid, depth + 1, !isMaximizing)); //Update best with the minimum value returned by the recursive call
                    grid[i][j] = " "; //Clean the simulation
                }
            }
        }
        return best; //Return best as the best possible score the PLAYER (Minimizer) can achieve from this move
    }
}
/* int main() {
    std::string board[3][3] = {
        {"X", "O", "X"},
        {" ", "O", " "},
        {" ", " ", " "}
    };

    std::pair<int, int> bestMove = COM::findBestMove(board);
    std::cout << "The best move is: (" << bestMove.first << ", " << bestMove.second << ")\n";

    return 0;
}
         */


