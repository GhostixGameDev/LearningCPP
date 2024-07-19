#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <windows.h>
#include "COM.h"

class TicTacToe {
private:
    std::string grid[3][3];
public:
    // Class constructors
    TicTacToe();

    // Getters and setters
    std::string(&getGrid())[3][3];
    std::string getGridValue(int x, int y);
    void setGrid(std::string newValues[3][3]);
    void editGrid(int x, int y, std::string newValue);

    // Instance methods
    void printGrid();
    void userSelect();
    bool validSelection(int x, int y);
    void clear();
    void reset();
    bool gameOver(bool won);
    void run();
};

#endif // TICTACTOE_H
