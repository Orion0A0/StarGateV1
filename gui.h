#include "game.h"
#include <string>
#include "file.h"
#ifndef GUI_H
#define GUI_H

class GUI : public Game
{
public:
    GUI();
    void run();
    std::string removeDupes(const std::string&); // FIX me
    std::string checkLength_three(const std::string&); // FIXE
    std::string printSymbol(Player, int);
    std::string printSymbol(std::vector<Guard*>&, int);
    void loadSavedGames();
    void printGame();
    void saveGames();
private:
    void initialize();
    //void printGame();

    void welcome();
    void menu();
    //void loadSavedGames();
    void printWin();
    void printDead();
    //void saveGames();

    // always return exactly size three string
    //std::string printSymbol(std::vector<Guard*>, int);
    //std::string printSymbol(Player, int);


    //std::string checkLength_three(const std::string&); // size of the string will always be 3
    //std::string removeDupes(const std::string&);

    File file;
};

#endif