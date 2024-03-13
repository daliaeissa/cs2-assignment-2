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
// BoardGame::BoardGame(){int r = 0; int c = 0;};

BoardGame::BoardGame(int r = 3, int c = 3): rows(r), columns(c)
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
    if ((row >= 0) && (row <= rows) && (column >= 0) && (column <= columns) && (play[row][column] == '\0')) {return true;}
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
bool BoardGame::isBoardFull()
{
    int countplays = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (play[i][j] != '\0')
            {
                countplays++;
            }
        }
    }
    if (countplays == rows*columns) {return true;}
    else {return false;}
};
class TicTacToe : public BoardGame
{
    private:
    char playerwon;

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

    virtual void isGameOver();

    void print();
};

TicTacToe::TicTacToe() {};

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
        playerwon = play [0][0];
        return true;
    }
    //checks the second row if there are 3 consecutive same plays then checkrow is true
    else if ((play[1][0] == play[1][1]) && (play[1][0] == play[1][2])) 
    {
        playerwon = play [1][0];
        return true;
    }
    //checks the third row if there are 3 consecutive same plays then checkrow is true
    else if ((play[2][0] == play[2][1]) && (play[2][0] == play[2][2])) 
    {
        playerwon = play [2][0];
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
        playerwon = play [0][0];
        return true;
    }
    else if ((play[0][1] == play[1][1]) && (play[0][1] == play[2][1])) 
    {
        playerwon = play [0][1];
        return true;
    }
    else if ((play[2][0] == play[2][1]) && (play[2][0] == play[2][2])) 
    {
        playerwon = play [2][0];
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
        playerwon = play [0][0];
        return true;
    }
    else if ((play[0][2] == play[1][1]) && (play[1][1] == play[2][0])) 
    {
        playerwon = play [0][2];
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
        cout << "Player " << playerwon << " WON! GAMEOVER!" << endl;
        //gameover = false;
    }
};

class ConnectFour : public BoardGame
{
    private:
    char playerwon;
    int lastemptyrow = rows - 1;
    int i = 0;

    public:
    ConnectFour();
    ConnectFour(int r, int c);

    bool isRowEmpty();

    int getEmptyRow();

    void makeMove(int column);

    bool isMoveValid(int column);

    bool checkRows();

    bool checkColumns();

    bool checkDiagonals();

    bool checkWin();

    void isGameOver() override;

    void print();

};

//ConnectFour::ConnectFour() {};

ConnectFour::ConnectFour(int r, int c) : BoardGame(r,c)
{
    r = 6; c = 7;
};

bool ConnectFour::isRowEmpty()
{
    // for (int i = lastemptyrow; i >= 0; i--)
    // {
    i = lastemptyrow;
    for (int j = 0; j <= columns - 7; j++)
    {
        if ((play[i][j] == '\0') && (play[i][j + 1] == '\0') && (play[i][j + 2] == '\0') && (play[i][j + 3] == '\0') && (play[i][j + 4] == '\0') && (play[i][j + 5] == '\0') && (play[i][j + 6] == '\0'))
        {
            lastemptyrow--;
            return true;
        }
    }
    // }
};

int ConnectFour::getEmptyRow()
{return lastemptyrow;};

void ConnectFour::makeMove(int column)
{
    // for (int i = 0; i < rows; i++)
    // {
    for (int j = 0; j < columns; j++)
    {
        if (isMoveValid(column))
        {
            play[getEmptyRow()][column] = currentPlayer;
            switchPlayer();
        }
        else {cout << "Invalid move! Try again!" << endl;}
    }
    // }
    // if (isMoveValid(column))
    // {
    //     play[row][column] = currentPlayer;
    //     switchPlayer();
    // }
    // else {cout << "Invalid move! Try again!" << endl;}
};

bool ConnectFour::isMoveValid(int column)
{
    if ((column >= 0) && (column < columns) && (play[0][column] == '\0'))
    {return true;}
    else {return false;}
};

void ConnectFour::print()
{
    BoardGame::printBoard();
};

bool ConnectFour::checkRows()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            if ((play[i][j] != '\0') && (play[i][j] == play[i][j + 1]) && (play[i][i] == play[i][j + 2]) && (play[i][j] == play[i][j + 3])) 
            {
                playerwon = play[i][j];
                return true;
            }
            //else {return false;}
        }
    }
    return false;
    //int i = 0, j = 0;
    //if ((play[0][0] != play[0][1]) || (play[0][0] != play[0][2])) {return false;}

    //checks the first row if there are 3 consecutive same plays then checkrow is true
    // if ((play[0][0] == play[0][1]) && (play[0][0] == play[0][2])) 
    // {
    //     currentPlayer = play [0][0];
    //     return true;
    // }
    // //checks the second row if there are 3 consecutive same plays then checkrow is true
    // else if ((play[1][0] == play[1][1]) && (play[1][0] == play[1][2])) 
    // {
    //     currentPlayer = play [1][0];
    //     return true;
    // }
    // //checks the third row if there are 3 consecutive same plays then checkrow is true
    // else if ((play[2][0] == play[2][1]) && (play[2][0] == play[2][2])) 
    // {
    //     currentPlayer = play [2][0];
    //     return true;
    // }
    // //otherwise if no match found within the rows then check row is false
    // else {return false;}

    // char first = play[0][0];

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < columns; j++)
    //     {
    //         if () {return true;}
    //     }
    // }
};

bool ConnectFour::checkColumns()
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j <= rows - 4; j++)
        {
            if ((play[j][i] != '\0') && (play[j][i] == play[j + 1][i]) && (play[j][i] == play[j + 2][i]) && (play[i][j] == play[j + 3][i])) 
            {
                playerwon = play[j][i];
                return true;
            }
            //else {return false;}
        }
    }
    return false;
    // if ((play[0][0] == play[1][0]) && (play[0][0] == play[2][0])) 
    // {
    //     currentPlayer = play [0][0];
    //     return true;
    // }
    // else if ((play[0][1] == play[1][1]) && (play[0][1] == play[2][1])) 
    // {
    //     currentPlayer = play [0][1];
    //     return true;
    // }
    // else if ((play[2][0] == play[2][1]) && (play[2][0] == play[2][2])) 
    // {
    //     currentPlayer = play [2][0];
    //     return true;
    // }
    // else {return false;}

    // int **q; int rows, col;

    // for (int i=0;)
};

bool ConnectFour::checkDiagonals()
{
    //if the row and column index are the same 
    for (int i = 0; i <= rows - 4; i++)
    {
        for (int j = 0; j <= columns - 4; j--)
        {
            if ((play[i][j] != '\0') && (play[i][j] == play[i + 1][j + 1]) && (play[i][j] == play[i + 2][j + 2]) && (play[i][j] == play[i + 3][j + 3]))
            {
                playerwon = play[i][j];
                return true;
            }
            else if ((play[i][j + 3] != '\0') && (play[i][j + 3] == play[i + 1][j + 2]) && (play[i][j + 3] == play[i + 2][j + 1]) && (play[i][j + 3] == play[i + 3][j])) 
            {
                playerwon = play[i][j + 3];
                return true;
            }
            //else {return false;}
        }
    }
    return false;
    // for (int i = 0; i <= rows - 4; i++)
    // {
    //     for (int j = columns - 1; j < 0; j--)
    //     {
    //         if ((play[i][j] != '\0') && (play[i][j] == play[i + 1][j -1]) && (play[i][j] == play[i + 2][j - 2]) && (play[i][j] == play[i + 3][j - 3])){}
    //     }
    // }

    // if ((play[0][0] == play[1][1]) && (play[0][0] == play[2][2])) 
    // {
    //     currentPlayer = play [0][0];
    //     return true;
    // }
    // else if ((play[0][2] == play[1][1]) && (play[1][1] == play[2][0])) 
    // {
    //     currentPlayer = play [0][2];
    //     return true;
    // }
    // else {return false;}
};

bool ConnectFour::checkWin()
{
    //char wonplayer;
    if ((checkRows() == true) || (checkColumns() == true) || (checkDiagonals() == true)) {return true;}
    else {return false;}
};

void ConnectFour::isGameOver()
{
     if ((checkWin() == false) || (BoardGame::isBoardFull() == true)) 
    {
        cout << "IT'S A DRAW! GAMEOVER!" << endl;
    }
    else if ( checkWin() == true)
    {
        cout << "Player " << playerwon << " WON! GAMEOVER!" << endl;
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

    cout << "\n------------------------------------------------------------------------\n" << endl;

    ConnectFour connect4(6,7);
    connect4.makeMove(0);
    connect4.makeMove(6);
    connect4.makeMove(1);
    connect4.makeMove(5);
    connect4.makeMove(2);
    connect4.makeMove(4);
    connect4.makeMove(3);

    connect4.print();
    connect4.isGameOver();

    return 0;
}