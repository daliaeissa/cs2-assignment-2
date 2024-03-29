#include "TicTacToe.h"
#include <iostream>

//TicTacToe::TicTacToe() {};

TicTacToe::TicTacToe(int r, int c) : BoardGame(r,c)
{
    r = 3; c = 3;
    //BoardGame(r,c);
//    r =5;
//    c = 6;
//    c += r;
};

void TicTacToe::makeMove(int row, int column)
{
    BoardGame::makeMove(row, column);
    // if (isMoveValid(row, column))
    // {
    //     play[row][column] = currentPlayer;
    //     switchPlayer();
    // }
    // else {cout << "Invalid move! Try again!" << endl;}
    // for (int i=0; i<rows; i++)
    // {
    //     for (int j=0; j<columns; j++)
    //     {
            
    //     }
    // }
};

// void TicTacToe:: operator +(int move_r, int move_c)
// {

// };

void TicTacToe::print()
{
    BoardGame::printBoard();
};

bool TicTacToe::checkRows()
{
    //int i = 0, j = 0;
    //if ((play[0][0] != play[0][1]) || (play[0][0] != play[0][2])) {return false;}

    //checks the first row if there are 3 consecutive same plays then checkrow is true
    if ((play[0][0] == play[0][1]) && (play[0][0] == play[0][2])) 
    {
        currentPlayer = play [0][0];
        return true;
    }
    //checks the second row if there are 3 consecutive same plays then checkrow is true
    else if ((play[1][0] == play[1][1]) && (play[1][0] == play[1][2])) 
    {
        currentPlayer = play [1][0];
        return true;
    }
    //checks the third row if there are 3 consecutive same plays then checkrow is true
    else if ((play[2][0] == play[2][1]) && (play[2][0] == play[2][2])) 
    {
        currentPlayer = play [2][0];
        return true;
    }
    //otherwise if no match found within the rows then check row is false
    else {return false;}

    // char first = play[0][0];

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < columns; j++)
    //     {
    //         if () {return true;}
    //     }
    // }
};

bool TicTacToe::checkColumns()
{
    if ((play[0][0] == play[1][0]) && (play[0][0] == play[2][0])) 
    {
        currentPlayer = play [0][0];
        return true;
    }
    else if ((play[0][1] == play[1][1]) && (play[0][1] == play[2][1])) 
    {
        currentPlayer = play [0][1];
        return true;
    }
    else if ((play[2][0] == play[2][1]) && (play[2][0] == play[2][2])) 
    {
        currentPlayer = play [2][0];
        return true;
    }
    else {return false;}
    // int **q; int rows, col;

    // for (int i=0;)
};

bool TicTacToe::checkDiagonals()
{
    if ((play[0][0] == play[1][1]) && (play[0][0] == play[2][2])) 
    {
        currentPlayer = play [0][0];
        return true;
    }
    else if ((play[0][2] == play[1][1]) && (play[1][1] == play[2][0])) 
    {
        currentPlayer = play [0][2];
        return true;
    }
    else {return false;}
};

bool TicTacToe::checkWin()
{
    //char wonplayer;
    if ((checkRows() == true) || (checkColumns() == true) || (checkDiagonals() == true)) {return true;}
    else {return false;}
};

// bool TicTacToe::checkDraw()
// {
//     if (((currentPlayer == 'X') || (currentPlayer == 'O')) && (checkWin() == false))
//     {return true;}
//     else {return false;}
// };

void TicTacToe::isGameOver()
{
    //bool gameover = false;s
    if ((checkWin() == false) || (BoardGame::isBoardFull() == true)) 
    {
        cout << "IT'S A DRAW! GAMEOVER!" << endl;
        //gameover = true;
    }
    else if ( checkWin() == true)
    {
        cout << "Player " << currentPlayer << " WON! GAMEOVER!" << endl;
        //gameover = false;
    }
};


int main()
{
    TicTacToe tictactoegame(3,3);
    tictactoegame.makeMove(1,1);
    tictactoegame.makeMove(1,2);
    tictactoegame.makeMove(2,1);
    tictactoegame.makeMove(0,1);
    tictactoegame.makeMove(2,2);
    tictactoegame.makeMove(0,2);
    tictactoegame.makeMove(2,0);

    tictactoegame.print();
    tictactoegame.isGameOver();

    return 0;
}