#include <cmath> 
#include "player.h"

#define DEFAULT_BOMB_SETTING true

Player::Player():Entity(SPAWN), hasBomb(true), symbol(PLAYER_SYMBOL){}

void Player::placeBomb()
{
    if (isAtCenter() && hasBomb)
    {
        hasBomb = false;
    }
}

bool Player::getBomb()
{
    return hasBomb;
}


char Player::getSymbol() const
{
    return symbol;
}

bool Player::isAtCenter()
{
    int center = GRID / 2;
    int space_above = center - ROW;

    if(abs(position - center) <= 1)
        return true;
    if(abs(position - space_above) <= 1)
        return true;

    return false;
}

void Player::resetBomb() {hasBomb = DEFAULT_BOMB_SETTING;}
