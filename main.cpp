/*GameToGo is an online gaming startup that offers a collection of engaging and interactive board
games for players of all ages. Their platform focuses on providing a virtual environment for
playing classic board games like Tic-Tac-Toe and Connect Four. They emphasize user
experience, fair play, and community engagement.
In this assignment, you will play the role of a developer at GameBoardGo. You will design and
implement two classic board games, Tic-Tac-Toe and Connect Four, within their online gaming
platform. These games should be implemented using object-oriented principles such as
inheritance and polymorphism. Additionally, you will utilize operator overloading in your
implementations. Your mission is to create a seamless and enjoyable gaming experience for their
users.
Part 1: Base Board Class (20 points)
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
and draw conditions.
Part 2: Tic-Tac-Toe Game (20 points)
- Create a class named TicTacToe that inherits from the BoardGame class. This class will
represent our virtual Tic-Tac-Toe game.
- Implement the print method in the TicTacToe class, which should render the Tic-Tac-Toe
board with 'X' and 'O' marks.
- Override the makeMove method in the TicTacToe class to allow players to make moves,
alternating between 'X' and 'O'. Ensure that you handle move validation and win
conditions.
- Implement the game logic to check for a win or a draw. Override the isGameOver method
in the TicTacToe class to determine the game's outcome.
Part 3: Connect Four Game (20 points)
- Create a class named ConnectFour that inherits from the BoardGame class. This class
will represent our virtual Connect Four game.
- Implement the print method in the ConnectFour class, which should render the Connect
Four board with 'X' and 'O' marks.
- Override the makeMove method in the ConnectFour class to allow players to make
moves, following Connect Four's rules. Ensure that you handle move validation and win
conditions.
- Implement the game logic to check for a win or a draw. Override the isGameOver method
in the ConnectFour class to determine the game's outcome.
Part 4: Player Class (20 points)
- Create a class named Player to represent a player in a board game. The Player class
should have the following attributes:
● A name to store the player's name (as a string).
● A symbol to store the player's symbol (e.g., 'X' or 'O' or ‘Red’ or ‘Blue’).
● Overload the << operator to allow printing a player's information using std::cout.
When you use std::cout << player, it should print the player's name and symbol.
● Integrate the Player class into the board class. Modify it to have instances of two
Player objects, one for each player. Update the game logic to use these players
and print the name of the player whose turn it is to make a move
Part 5: Main Program (20 points)
Create a main program that demonstrates the functionality of the two games.
Bonus (15 points): Make the games look good using QT.*/

#include<iostream>
#include <fstream>
using namespace std;

// Player class
class Player
{
    private:
        string playerName;
        char playerSymbol;

    public:
        Player();
        Player(string name, char symbol);
        
        friend ostream &operator << (ostream &info, const Player &player);

        string get_name();
        char get_symbol();
        //void displayPlayer();
};

Player::Player(string name, char symbol) : playerName(name), playerSymbol(symbol)
{};

ostream &operator << (ostream &info, const Player &player)
{
    info << "Player: " << player.playerName << "\nSymbol: " << player.playerSymbol << endl;
    return info;
};

string Player::get_name(){return playerName;};
char Player::get_symbol(){return playerSymbol;};

// void Player::displayPlayer()
// {
//     cout << "Player Name: " << get_name() << "\nPlayer Symbol: " << get_symbol() << endl;
// };

// BoardGame class
class BoardGame 
{
    protected:
    int rows;
    int columns;
    char **play;
    //char currentPlayer = 'X';
    char currentPlayersymbol;
    Player *player1;
    Player *player2;
    Player *currentPlayer;

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
    play = new char*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        play[i] = new char[columns];
        for (int j = 0; j < columns; ++j) 
        {
            play[i][j] = '\0';
        }
    }
    // player1->displayPlayer();
    // player2->displayPlayer();
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
    //currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
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
        play[row][column] = currentPlayer->get_symbol();
        switchPlayer();
    }
    else {cout << "Invalid move! Try again!" << endl;}
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

// TicTacToe class
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

    virtual void isGameOver();

    void print();
};

TicTacToe::TicTacToe() {};

TicTacToe::TicTacToe(int r, int c) : BoardGame(r,c)
{
    r = 3; c = 3;
    player1 = new Player("Player 1", 'X');
    player2 = new Player("Player 2", 'O');
    currentPlayer = player1;
    //BoardGame(r,c);
};

void TicTacToe::makeMove(int row, int column)
{
    BoardGame::makeMove(row, column);
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

void TicTacToe::isGameOver()
{
    //bool gameover = false;s
    if ((checkWin() == false) || (BoardGame::isBoardFull() == true)) 
    {
        cout << "IT'S A DRAW! GAMEOVER!" << endl;
    }
    else if ( checkWin() == true)
    {
        cout << "Player " << playerwon << " WON! GAMEOVER!" << endl;
    }
};

// ConnectFour class
class ConnectFour : public BoardGame
{
    private:
    char playerwon;
    int lastemptyrow = rows - 1;
    int i = 0;
    int countcolumns = 0;

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
    player1 = new Player("Player 1", 'X');
    player2 = new Player("Player 2", 'O');
    currentPlayer = player1;
};

bool ConnectFour::isRowEmpty()
{
    for (int i = lastemptyrow; i >= 0; i--)
    {
            int j = 0;
            if ((play[i][j] != '\0') && (play[i][j + 1] != '\0') && (play[i][j + 2] != '\0') && (play[i][j + 3] != '\0') && (play[i][j + 4] != '\0') && (play[i][j + 5] != '\0') && (play[i][j + 6] != '\0'))
            {
                return false;
            }
            else {return true;}
    }
    //lastemptyrow--;
};

int ConnectFour::getEmptyRow()
{return lastemptyrow;};

void ConnectFour::makeMove(int column)
{
    // for (int i = 0; i < rows; i++)
    // {
    // for (int j = 0; j < columns; j++)
    // {
        if (isMoveValid(column))
        {
            play[lastemptyrow][column] = currentPlayer->get_symbol();
            switchPlayer();
            countcolumns++;
            if ((isRowEmpty() == false))//(countcolumns == 7) && 
            {
                countcolumns = 0;
                lastemptyrow--;
            }
        }
        else {cout << "Invalid move! Try again!" << endl;}
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
        for (int j = 0; j < columns - 3; j++)
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
};

bool ConnectFour::checkColumns()
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows - 3; j++)
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
};

bool ConnectFour::checkDiagonals()
{
    //if the row and column index are the same 
    for (int i = 0; i < rows - 3; i++)
    {
        for (int j = 0; j < columns - 3; j++)
        {
            if ((play[i][j] != '\0') && (play[i][j] == play[i + 1][j + 1]) && (play[i][j] == play[i + 2][j + 2]) && (play[i][j] == play[i + 3][j + 3]))
            {
                playerwon = play[i][j];
                //cout << "left diag" << i << " " << j << " " << playerwon << endl;
                return true;
            }
            else if ((play[i][j + 3] != '\0') && (play[i][j + 3] == play[i + 1][j + 2]) && (play[i][j + 3] == play[i + 2][j + 1]) && (play[i][j + 3] == play[i + 3][j])) 
            {
                playerwon = play[i][j + 3];
                //cout << "right diag" << i << " " << j + 3 << " " << playerwon << endl;
                return true;
            }
            //else {return false;}
        }
    }
    return false;
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
    else if ((checkWin() == false) && (BoardGame::isBoardFull() == false))
    {cout << "The game is not over yet! Continue playing!" << endl;}
    else if (checkWin() == true)
    {
        switchPlayer();
        cout << "Player " << currentPlayer->get_symbol() << " WON! GAMEOVER!" << endl;
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
    Player player1("Khouly", 'X');
    cout << player1;
    // connect4.makeMove(0);
    // connect4.makeMove(6);
    // connect4.makeMove(1);
    // connect4.makeMove(5);
    // connect4.makeMove(2);
    // connect4.makeMove(4);
    // connect4.makeMove(3);
    connect4.makeMove(0);//
    connect4.makeMove(1);
    connect4.makeMove(2);
    connect4.makeMove(3);
    connect4.makeMove(4);
    connect4.makeMove(5);
    connect4.makeMove(6);
    connect4.makeMove(1);//
    connect4.makeMove(6);
    connect4.makeMove(2);
    connect4.makeMove(3);
    connect4.makeMove(4);
    connect4.makeMove(5);
    connect4.makeMove(6);
    connect4.makeMove(0);
    connect4.makeMove(2);//
    connect4.makeMove(3);
    connect4.makeMove(5);
    connect4.makeMove(6);
    connect4.makeMove(0);
    connect4.makeMove(1);
    connect4.makeMove(4);
    connect4.makeMove(2);
    connect4.makeMove(3);//
    connect4.makeMove(6);
    connect4.makeMove(1);
    connect4.makeMove(2);
    connect4.makeMove(4);
    connect4.makeMove(5);
    connect4.makeMove(3);

    connect4.print();
    connect4.isGameOver();
    cout << "\n------------------------------------------------------------------------\n" << endl;

    return 0;
}