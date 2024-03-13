#include "Player.h"
#include <iostream>

Player::Player(){};
Player::Player(string name, char symbol)
{
    playerName = name;
    playerSymbol = symbol;
};

Player Player::operator<<(Player &player)
{
    ostream playerInfo;
    playerInfo << player.get_name() << endl;
    playerInfo << player.get_symbol() << endl;
};
