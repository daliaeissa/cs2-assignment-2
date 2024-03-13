/*Part 4: Player Class (20 points)
- Create a class named Player to represent a player in a board game. The Player class
should have the following attributes:
● A name to store the player's name (as a string).
● A symbol to store the player's symbol (e.g., 'X' or 'O' or ‘Red’ or ‘Blue’).
● Overload the << operator to allow printing a player's information using std::cout.
When you use std::cout << player, it should print the player's name and symbol.
● Integrate the Player class into the board class. Modify it to have instances of two
Player objects, one for each player. Update the game logic to use these players
and print the name of the player whose turn it is to make a move*/

#ifndef PLAYER_H
#define PLAYER_H
#include "BoardGame.h"
#include<iostream>
using namespace std;

class Player
{
    private:
        string playerName;
        char playerSymbol;

    public:
        Player(string name, char symbol);
        Player(string);

};

#endif