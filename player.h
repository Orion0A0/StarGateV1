#include "entity.h"
#ifndef PLAYER_H
#define PLAYER_H

#define GRID (ROW * COL)
#define PLAYER_SYMBOL 'O'

class Player: public Entity
{
public:
    Player();
    void placeBomb();
    bool getBomb();
    void resetBomb();
    char getSymbol() const;
private:
    bool isAtCenter();
    
    char symbol;
    bool hasBomb;
};

#endif