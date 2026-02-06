#include <iostream>
#include <iomanip>
#include "gui.h"


#define CURR_POSITION (j + (i * ROW))
#define NUM_SPACE 5 * (COL - 1)

GUI::GUI():Game()
{
    initialize();
}

void GUI::initialize()
{

}

void GUI::printGame() 
{
    std::cout << std::setfill('-') << std::setw(NUM_SPACE) << "\n";
    for (int i = 0; i < ROW; ++i)
    {
        std::cout << "|";
        for (int j = 0; j < COL; ++j)
        {
            std::cout << printSymbol(enemies, CURR_POSITION);
            std::cout << "|";
        }
        std::cout << "\n";
        std::cout << "|";
        for (int j = 0; j < COL; ++j)
        {
            std::cout << printSymbol(*player, CURR_POSITION);
            std::cout << "|";
        }
        std::cout << "\n";
        std::cout << std::setfill('-') << std::setw(NUM_SPACE) << "\n";

    }
    

}

void GUI::welcome()
{
    std::cout << "Welcome to StarGate_NotContinued" << std::endl;
    std::cout << "Your goal is to go to the middle and place the bomb and get out of the place" << std::endl;
    std::cout << "Watchout for the different types of enemies on the way" << std::endl;
    
}

void GUI::menu()
{
    // ask the player to start a new game or load a saved game
        // call loadSaveGame if chose saved game
            // if there is no save game, the function will catch the exception thrown by loadSavedGames and print "No Game saved"


        // do nothing if start a new game
}

void GUI::loadSavedGames()
{
    // check if the file exist
        // if false: throws a runtime exception (outside)
        // if true: call readingProgress for both player and enemies from File class 

    enemies = file.readingProgress_enemy(); // this is the issue
	player = new Player(file.readingProgress_player());
        
}

void GUI::saveGames()
{
	file.savingProgress(enemies, *player);
}

std::string GUI::printSymbol(std::vector<std::unique_ptr<Guard>>& enemies, int currPos)
{
    std::string textToReturn{};

    for (int i = 0; i < enemies.size(); ++i)
    {
        if(enemies.at(i)->getPosition() == currPos)
            textToReturn.insert(textToReturn.end(),enemies.at(i)->getSymbol());
    }
    return checkLength_three(removeDupes(textToReturn));
}

std::string GUI::printSymbol(Player player, int currPos) 
{
    std::string temp{player.getSymbol()};
    if(player.getPosition() == currPos)
        return checkLength_three(" " + temp);  

    return "   ";
    
}

std::string GUI::checkLength_three(const std::string& str) 
{

    if(str.length() == 3)
        return str;
    
    if(str.length() < 3)
        return checkLength_three(str + " ");

    //if(str.length() > 3)
    return checkLength_three(removeDupes(str));
    
    
}

std::string GUI::removeDupes(const std::string& str)
{
    if (str.length() == 0)
        return str;

    std::string temp(str);
    for (size_t i = 0; i < temp.length() - 1; ++i)
    {
        int num = temp.find(temp.at(i), i + 1);
        while (num != std::string::npos)
        {
            temp.erase(temp.begin() + num);

            num = temp.find(temp.at(i), i + 1);
        }
  
    }
    
    return temp;
    
}
