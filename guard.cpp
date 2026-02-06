#include "guard.h"

#define NEXT_TO_SPAWN 2
#define DEFAULT_STATUS false



Guard::Guard(char symbol, int position) : Entity(position), symbol(symbol), chase_player(DEFAULT_STATUS){}

Guard::Guard(const Guard& other) : Entity(other.position), symbol(other.symbol), chase_player(other.chase_player) {}
Guard::~Guard() 
{
	// no dynamic memory to free
}
Guard& Guard::operator=(const Guard& other) 
{
    if (this != &other) 
    {
        position = other.position;
        symbol = other.symbol;
        chase_player = other.chase_player;
    }
    return *this;
}

Movement Guard::moveAtRandom(int playerPos) // need other function to make sure this is in range
{
    if(playerPos < position)
        return static_cast<Movement>(randRange(0,1));
    if(playerPos > position)
        return static_cast<Movement>(randRange(2,3));
    return INVALID;
}

int Guard::spawnRandom()
{
    int pos = randRange(NEXT_TO_SPAWN, (ROW*COL));
    while(true)
    {
        if(pos != (ROW + 1))
            break;
    }
    return pos;
}


int Guard::randRange(size_t start, size_t end)
{
    return  rand() % (end - start + 1) + start;
}

void Guard::setSeed(int seed) {srand(seed);}

void Guard::chasePlayer() {chase_player = true;}
char Guard::getSymbol() const {return symbol;}
bool Guard::getChasePlayer() const { return chase_player; }
void Guard::resetChase_player() {chase_player = DEFAULT_STATUS;}
