#include "enemy.h"
#include "test.h"
#include "game.h"
#include "gui.h"
#include "file.h"

#define Setup AdvancedArmy a;
#define O_Setup Guard* a = new AdvancedArmy();
#define NUM_TRIAL 1000
#define TEST_STR "TWWWW"
void testMoveChance();
void testMovementCorrection();
void testRemoveDupes();
void testCheckLength_three();
void testPrintSymbol();

void testPrintGame();
void testSaveFile();
void testReadFile();
int main(int argc, char const *argv[])
{
    // testMoveChance();
    //testMovementCorrection();
    //Game g;
    //g.moveEnemy();
    //testRemoveDupes();
    //testCheckLength_three();
    //testPrintSymbol();

    //testPrintGame();
    //testSaveFile();
    testReadFile();
    return 0;
}
void testMovementCorrection()
{
    O_Setup
    a->setPosition(8);
    int count_up = 0;
    int count_left = 0;
    int count_down = 0;
    int count_right = 0;
    int count_invalid = 0;
    for(int i = 0; i < NUM_TRIAL; ++i)
    {
        switch (a->moveAtRandom(0))
        {
        case UP: count_up++; 
                 break;
        case LEFT: count_left++; 
                 break;
        case DOWN: count_down++; 
                 break;
        case RIGHT: count_right++; 
                 break;
        case INVALID: count_invalid++; 
                 break;
        
        }
    }
    std::cout << "UP :" << count_up << " | " 
              << "LEFT :" << count_left << " | "
              << "Down :" << count_down << " | "
              << "Right :" << count_right << " | "
              << "Invalid :" << count_invalid << " | " << std:: endl;
}

void testRemoveDupes()
{
    GUI obj;

    std::string test = "";
    
    std::cout << obj.removeDupes(test);
}

void testCheckLength_three()
{
    GUI obj;

    std::string str{obj.checkLength_three(TEST_STR) };

	std::cout << str;
    std::cout << str.length();

}

void testPrintSymbol()
{
    GUI obj;
    Player p;

    std::string str{ obj.printSymbol(p, 9) };
    std::cout << str << str.length();
}


void testPrintGame()
{
    GUI obj;

    obj.printGame();
}

void testSaveFile()
{
    
    GUI obj;

    obj.printGame();
    obj.saveGames();
}

void testReadFile()
{
    GUI obj;
    obj.loadSavedGames();
	obj.printGame();

}

void testMoveChance()
{
    Setup
    int count_invalid = 0;
    int count_move = 0;
    for(int i = 0; i < NUM_TRIAL; ++i)
    {
        if(a.moveAtRandom() == 4)
            count_invalid++;
        else
            count_move++;
    }
    std::cout << count_invalid /static_cast<double>(NUM_TRIAL) << " | " << count_move /static_cast<double>(NUM_TRIAL) << std::endl;
}