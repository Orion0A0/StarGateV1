#include "game.h"


#define NUM_OF_A_ARMY 2
#define A_ARMY_POS (enemies.size() - NUM_OF_A_ARMY)

Game::Game() { }
Game::Game(bool initialize)
{
    initial();
}

Game::~Game() 
{
    delete player;
}

Game::Game(const Game& other)
{
    player = new Player;
    player = other.player;
}

Game& Game::operator=(const Game& other)
{
    if (this != &other) 
    {
        delete player;
        player = new Player;
        player = other.player;
    }
	return *this;
}

void Game::initial()
{
    player = new Player();
    enemies = {
        new Fodder(), new Fodder(), new Fodder(), new Fodder(),
        new RegularArmy(), new RegularArmy(), new RegularArmy(),
        new AdvancedArmy(), new AdvancedArmy()
    };

}

void Game::moveEnemy() 
{
    checkAdjcent();
    for (int i = 0; i < enemies.size(); i++)
    {
        if(enemies.at(i)->getChasePlayer()) // if the enemy detects the player, this will become true
        {
            move(enemies.at(i), enemies.at(i)->moveAtRandom(player->getPosition()));
            continue;
        } 
        move(enemies.at(i), enemies.at(i)->moveAtRandom());
    }
}



bool Game::win()
{
    if (!player->getBomb() && player->getPosition() == SPAWN)
        return true;
    
    return false;
}

bool Game::checkDead()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies.at(i)->getPosition() == player->getPosition())
        {
            return true;
        }
    }
    return false;
}

void Game::playerAction(Movement steps)
{
    if(steps == PLACE)
    {
        player->placeBomb();
        return;
    }   
    move(player, steps);
}

void Game::checkAdjcent() // determines if player is near A_guard
{
    for (int i = enemies.size() - NUM_OF_A_ARMY; i < enemies.size(); ++i)
    {
        int guardPos = enemies.at(i)->getPosition();
        int playerPos = player->getPosition();
        if (guardPos - ROW == playerPos || guardPos + ROW == playerPos || guardPos + 1 == playerPos || guardPos - 1 == playerPos)
            enemies.at(i)->chasePlayer();
    }
}

void Game::move(Entity* obj, Movement move)
{
    obj->movePosition(move);
}

void Game::objectToPointer(const std::vector<Guard>& target)
{
    for (int i = 0; i < target.size(); ++i)
    {
        if (target.at(i).getSymbol() == FODDER_SYMBOL)
            enemies.push_back(new Fodder(target.at(i)));
        else if (target.at(i).getSymbol() == R_ARMY_SYMBOL)
            enemies.push_back(new RegularArmy(target.at(i)));
        else if (target.at(i).getSymbol() == A_ARMY_SYMBOL)
			enemies.push_back(new AdvancedArmy(target.at(i)));
    }
    
}

bool Game::reset() 
{
    // reset enemies

    int i = 0;
    for (; i < enemies.size(); ++i)
    {
        enemies.at(i)->setPosition(enemies.at(i)->spawnRandom());
    }
    for (i = enemies.size() - NUM_OF_A_ARMY; i < enemies.size(); ++i)
    {
        enemies.at(i)->resetChase_player();
    }
    // reset players

    player->setPosition(SPAWN);
    player->resetBomb();

    return true;
}