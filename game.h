#include <vector>
#include "enemy.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(); // for making an empty object
    Game(bool); // true for initialize a brand new game
    ~Game();
	Game(const Game&); // copy constructor
	Game& operator=(const Game&); // copy assignment operator
    
    void initial(); // put player at 0, place enemy randomly, creates enemies and play objects
    void moveEnemy();
    bool reset();

    
    // player functions
    bool win(); // win if player is at 0 and placed the bomb
    bool checkDead();
    void playerAction(Movement); // if placing the bomb, call placeBomb


protected: 
    std::vector<Guard*> enemies;
    Player* player = nullptr;

	void objectToPointer(const std::vector<Guard>&);
private:
    // enemy support function
    void checkAdjcent();
    // move both player and enemies
    void move(Entity*, Movement);
    
};

// write a copy constructor, destructor, copy assignment operator for Guard class and Game class
#endif