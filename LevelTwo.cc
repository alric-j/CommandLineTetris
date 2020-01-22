#include "LevelTwo.h"
#include <string>
#include <memory>
#include <cstdlib>
using namespace std;

LevelTwo::LevelTwo() {}

int LevelTwo::getLevel() { return 2; }

bool LevelTwo::getHeavy() { return false; }

shared_ptr<Block> LevelTwo::generateBlock(std::shared_ptr<Board> b, string type) {
    string block;
    if(type != "any") { block = type; }
    else  {
        int choice = rand() % 7;
        if(choice == 0) { block = "S"; }
        else if(choice == 1) { block = "Z"; }
        else if(choice == 2) { block = "I"; }
        else if(choice == 3) { block = "J"; }
        else if(choice == 4) { block = "L"; }
        else if(choice == 5) { block = "O"; }
        else { block = "T"; }
    }
    return createBlock(block, getLevel(), b);
}

void LevelTwo::setRandom(bool r) {}

void LevelTwo::setFile(string f) {}
