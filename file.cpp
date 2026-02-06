#include "file.h"
#include "enemy.h"

#define FILE_NAME "progress.bin" 
#define NUM_F_GUARD 4
#define NUM_R_GUARD 3
#define NUM_A_GUARD 2
#define TOTAL_ENEMY (NUM_F_GUARD + NUM_R_GUARD + NUM_A_GUARD)

File::File():filename(FILE_NAME){}

// make sure to save the actual object and not the address 
void File::savingProgress(std::vector<std::unique_ptr<Guard>>& enemies, Player player) // not done, still need player
{
    out = openOutFile();
    // saves enemies
    for (size_t i = 0; i < enemies.size(); ++i)
    {
		Guard* enemy = enemies.at(i).get();
        out.write(reinterpret_cast<char*>(enemy), sizeof(Guard));
    }
        
 
    // save players
    out.write(reinterpret_cast<char*>(&player), sizeof(Player));

    out.close();
}

std::vector<std::unique_ptr<Guard>>& File::readingProgress_enemy()
{
    Fodder f;
    RegularArmy r;
    AdvancedArmy a;

    in = openInFile();
    if (!in.good()) throw std::runtime_error("unable to save to file");
    // enemies
    for (int i = 1; i < TOTAL_ENEMY + 1; ++i)
    {
        if(i <= NUM_F_GUARD)
        {
            in.read(reinterpret_cast<char*>(&f), sizeof(Fodder));
            enemies_storage.push_back(std::unique_ptr<Guard>(&f));
            continue;
        }
        if(i > NUM_F_GUARD && i <= (NUM_F_GUARD + NUM_R_GUARD))
        {
            in.read(reinterpret_cast<char*>(&r), sizeof(RegularArmy));
            enemies_storage.push_back(std::unique_ptr<Guard>(&r));
            continue;
        }
        if(i > (NUM_F_GUARD + NUM_R_GUARD))
        {
            in.read(reinterpret_cast<char*>(&a), sizeof(AdvancedArmy));
            enemies_storage.push_back(std::unique_ptr<Guard>(&a));
            continue;
        }
    }
    
    
    return enemies_storage;

}
Player File::readingProgress_player()
{
    Player p;
    if (!in.good()) throw std::runtime_error("unable to save to files");
    
    in.read(reinterpret_cast<char*>(&p), sizeof(Player));
    in.close();
    return p;

}

std::ofstream File::openOutFile()
{
    std::ofstream out (filename, std::ios::binary);

    if(!out) throw std::runtime_error("unable to open output file");

    return out;
}

std::ifstream File::openInFile()
{
    std::ifstream in (filename, std::ios::binary);

    if(!in) throw std::runtime_error("unable to open input file");

    return in;
}


