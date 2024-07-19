#ifndef COM_H
#define COM_H

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>

class COM {
public:
    static std::pair<int, int> findBestMove(std::string(&grid)[3][3]);
    static int evaluate(const std::string(&grid)[3][3]);
    static bool isMovesLeft(const std::string(&grid)[3][3]);
private:
    static int minimax(std::string(&grid)[3][3], int depth, bool isMaximizing);
};

#endif // COM_H

