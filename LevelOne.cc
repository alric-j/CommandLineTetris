#include "LevelOne.h"
#include <string>
#include <memory>
#include <cstdlib>
using namespace std;

LevelOne::LevelOne() {}

int LevelOne::getLevel() { return 1; }

bool LevelOne::getHeavy() { return false; }

shared_ptr<Block> LevelOne::generateBlock(std::shared_ptr<Board> b, string type) {
    string block;
    if(type != "any") { block = type; }
    else  {
        int choice = rand() % 12;
        if(choice == 0) { block = "S"; }
        else if(choice == 1) { block = "Z"; }
        else if(choice <= 3) { block = "I"; }
        else if(choice <= 5) { block = "J"; }
        else if(choice <= 7) { block = "L"; }
        else if(choice <= 9) { block = "O"; }
        else { block = "T"; }
    }
    return createBlock(block, getLevel(), b);
}

void LevelOne::setRandom(bool r) {}

void LevelOne::setFile(string f) {}
