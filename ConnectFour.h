/*Part 3: Connect Four Game (20 points)
- Create a class named ConnectFour that inherits from the BoardGame class. This class
will represent our virtual Connect Four game.
- Implement the print method in the ConnectFour class, which should render the Connect
Four board with 'X' and 'O' marks.
- Override the makeMove method in the ConnectFour class to allow players to make
moves, following Connect Four's rules. Ensure that you handle move validation and win
conditions.
- Implement the game logic to check for a win or a draw. Override the isGameOver method
in the ConnectFour class to determine the game's outcome.
*/

#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
#include "BoardGame.h"
#include<iostream>
using namespace std;

class ConnectFour : public BoardGame
{
    private:

    public:
    ConnectFour(){}
    ConnectFour(int r, int c) : BoardGame(6,7){}

    void makeMove(int row, int column) override;

    bool checkRows();

    bool checkColumns();

    bool checkDiagonals();

    bool checkWin();

    void isGameOver() override;

    void print();

};

#endif