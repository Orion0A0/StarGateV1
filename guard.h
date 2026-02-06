#include <cstdlib>
#include "entity.h"

#ifndef GUARD_H
#define GUARD_H

struct Guard : public Entity
{
public:
    Guard(const Guard&);
    ~Guard();
	Guard& operator=(const Guard&);

    virtual Movement moveAtRandom() = 0; 
    Movement moveAtRandom(int);
    bool getChasePlayer() const;
    void chasePlayer();
    char getSymbol() const;
    int spawnRandom();
    void resetChase_player();
protected:
    Guard(char, int);

    
    int randRange(size_t, size_t);
    void setSeed(int);
    

    char symbol;
    bool chase_player;
};


#endif