#include "BoardGame.h"
#include <iostream>

BoardGame::BoardGame(){};

BoardGame::BoardGame(int r, int c): rows(r), columns(c)
{
    // play = new char[rows*columns];
    // for (int i=0; i<<rows; i++)
    // {
    //     for (int j=0; j<columns; j++)
    //     {play[i*j] = '\0';}
    // }
    /*OR:
    in private of class: char** play;*/
    play = new char*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        play[i] = new char[columns];
        for (int j = 0; j < columns; ++j) 
        {
            play[i][j] = '\0';
        }
    }
};

void BoardGame::printBoard()
{
    for (int i = 0; i < rows; i++)
    {
        cout << "|" ;
        for (int j = 0; j < columns; j++)
        {
            cout << "\t" << play[i][j] << "\t|" ;
        }
        cout << endl;
    }
};

void BoardGame::switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
};

bool BoardGame::isMoveValid(int row, int column)
{
    if ((row >= 0) && (row <= rows) && (column >= 0) && (column <= columns)) {return true;}
    else {return false;}
};

void BoardGame::makeMove(int row, int column)
{
    if (isMoveValid(row, column))
    {
        play[row][column] = currentPlayer;
        switchPlayer();
    }
    else {cout << "Invalid move! Try again!" << endl;}
    // for (int i=0; i<rows; i++)
    // {
    //     for (int j=0; j<columns; j++)
    //     {
            
    //     }
    // }
};

// BoardGame BoardGame::operator + (BoardGame &move)
// {
//     //overloading plus operator
// }


// bool BoardGame::isBoardFull()
// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < columns; j++)
//         {
//             if (play[i][j] != '\0') {return true;}
//             else {return false;}
//         }
//     }
// };

// bool BoardGame::isGameOver()
// {
//     if ((checkWin() == false) || (isBoardFull() == true)) {return true;}
//     else {return false;}
// };

// int main()
// {
//     // char gameChoice;
//     // cout<< "Select a game to play: ";
//     // cin>> gameChoice;

//     // switch (gameChoice)
//     // {
//     //     case 'T':
//     //         //call the class for the tictactoe: board game with (3,3)
//     //     case 'C':
//     //         //call the class for the connect four: board game with (,)
//     // }

//     //while(boardgame!=isGameOver): inside keep user entering the move and the play, the move contains the location of the play and the play itself

//     BoardGame boardgame1(3,3);
//     boardgame1.makeMove(1,1);
//     boardgame1.makeMove(1,2);
//     boardgame1.makeMove(1,0);
//     //boardgame.checkWin();
//     //boardgame.isGameOver();
//     boardgame1.printBoard();

//     // if ((boardgame1.isGameOver() == true) && (boardgame1.checkWin() == true))
//     // {cout << "You Win! GAMEOVER!" << endl;}
//     // else {cout << "You Lost! GAMEOVER!" << endl;}

//     BoardGame boardgame2(3,3);
//     boardgame2.makeMove(1,1);
//     boardgame2.makeMove(1,2);
//     boardgame2.makeMove(1,0);
//     //boardgame.checkWin();
//     //boardgame.isGameOver();
//     boardgame2.printBoard();

//     // if ((boardgame2.isGameOver() == true) && (boardgame2.checkWin() == true))
//     // {cout << "You Win! GAMEOVER!" << endl;}
//     // else {cout << "You Lost! GAMEOVER!" << endl;}

//     return 0;
// };