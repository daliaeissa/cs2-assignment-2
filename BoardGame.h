/*Part 1: Base Board Class (20 points)
- Create a base class called BoardGame which represents the common attributes and
behaviors shared among all board games on GameToGo.
- Define a constructor for the BoardGame class that initializes the dimensions of the game
board (rows and columns).
- Implement the method called printBoard in the BoardGame class. This method should
print the current state of the game board to the user's interface.
- Create a method named makeMove in the BoardGame class. This method should allow a
player to make a move on the game board. Ensure that you handle move validation and
maintain turn order.
- Overload the operator + to do the same functionality as makeMove in the BoardGame
class.
- Implement a pure virtual method named isGameOver in the BoardGame class. This
method should check whether the game is over due to a win, draw, or other game-specific
conditions. Override this method in derived game classes to provide game-specific win
and draw conditions*/

#ifndef BOARDGAME_H
#define BOARDGAME_H

#include<iostream>
using namespace std;
class BoardGame 
{
    protected:
    int rows;
    int columns;
    char **play;
    char currentPlayer = 'X';

    public:
    // BoardGame( int , int =0);
    BoardGame(int r, int c);
    
    void printBoard();

    void switchPlayer();

    bool isMoveValid(int row, int column);

    virtual void makeMove(int row, int column);

    //BoardGame operator + (BoardGame &move);

    // bool checkRows();

    // bool checkColumns();

    // bool checkDiagonals();

    // bool checkWin();

    bool isBoardFull();

    virtual void isGameOver() = 0;

    //bool isGameOver();
};


#endif