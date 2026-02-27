#include <fstream>
#include <vector>
#include "guard.h"
#include "player.h"
#ifndef FILE_H
#define FILE_H

#define BUFFER_SIZE 1024

// everything isn't tested

class File
{
public:
    File();
    void savingProgress(std::vector<Guard*>&, Player);
    std::vector<Guard>& readingProgress_enemy();
    Player readingProgress_player(); // has to be read after "readingProgress_enemy"

    bool changeFileName(const std::string&);


private:
    std::ifstream in;
    std::ofstream out;
	std::vector<Guard> enemies_storage; // to store the dynamically allocated enemies when reading from file

    std::string filename;

    std::ifstream openInFile();
    std::ofstream openOutFile();
    
};


#endif