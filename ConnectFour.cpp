#include "ConnectFour.h"
#include <iostream>

ConnectFour::ConnectFour(){};
ConnectFour::ConnectFour(int r, int c)
{
    r = 6; 
    r = 7;
    BoardGame(r,c);
};

void ConnectFour::makeMove(int row, int column)
{
    if (isMoveValid(row, column))
    {
        play[row][column] = currentPlayer;
        switchPlayer();
    }
    else {cout << "Invalid move! Try again!" << endl;}
};

