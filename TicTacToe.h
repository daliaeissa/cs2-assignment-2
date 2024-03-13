/*Part 2: Tic-Tac-Toe Game (20 points)
- Create a class named TicTacToe that inherits from the BoardGame class. This class will
represent our virtual Tic-Tac-Toe game.
- Implement the print method in the TicTacToe class, which should render the Tic-Tac-Toe
board with 'X' and 'O' marks.
- Override the makeMove method in the TicTacToe class to allow players to make moves,
alternating between 'X' and 'O'. Ensure that you handle move validation and win
conditions.
- Implement the game logic to check for a win or a draw. Override the isGameOver method
in the TicTacToe class to determine the game's outcome.*/

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "BoardGame.h"
#include<iostream>
using namespace std;

class TicTacToe : public BoardGame
{
    private:

    public:
    TicTacToe();
    TicTacToe(int r, int c);

    void makeMove(int row, int column) override;

    //void operator + (int move_r, int move_c);

    bool checkRows();

    bool checkColumns();

    bool checkDiagonals();

    bool checkWin();

    //bool checkDraw();

    void isGameOver() override;

    void print();
};

#endif