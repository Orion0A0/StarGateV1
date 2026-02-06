#include "guard.h"
#ifndef FODDER_H
#define FODDER_H

#define F_MOVE_CHANCE 15
#define R_MOVE_CHANCE 50
#define A_MOVE_CHANCE 80

#define FODDER_SYMBOL 'F'
#define R_ARMY_SYMBOL 'R'
#define A_ARMY_SYMBOL 'A'

class Fodder: public Guard
{
public:
    Fodder(): Guard(FODDER_SYMBOL, spawnRandom()){}

    Movement moveAtRandom() override
    {
        Movement move = INVALID;
        if(randRange(1, 100) <= F_MOVE_CHANCE)
        {
            while(true)
            {
                move = static_cast<Movement>(randRange(0,3));
                if(isInRange(move))
                    break;
            }
        }
    return move;
    }
};

class RegularArmy: public Guard
{
public:
    RegularArmy(): Guard(R_ARMY_SYMBOL, spawnRandom()){}

    Movement moveAtRandom() override
    {
        Movement move = INVALID;
        if(randRange(1, 100) <= R_MOVE_CHANCE)
        {
            while(true)
            {
                move = static_cast<Movement>(randRange(0,3));
                if(isInRange(move))
                    break;
            }
        }
    return move;
    }
};

class AdvancedArmy: public Guard
{
public:
    AdvancedArmy(): Guard(A_ARMY_SYMBOL, spawnRandom()){}

    Movement moveAtRandom() override
    {
        Movement move = INVALID;
        if(randRange(1, 100) <= A_MOVE_CHANCE)
        {
            while(true)
            {
                move = static_cast<Movement>(randRange(0,3));
                if(isInRange(move))
                    break;
            }
        }
    return move;
    }
    

};
#endif