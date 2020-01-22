#include "LevelThree.h"
#include <string>
#include <memory>
#include <cstdlib>
using namespace std;

LevelThree::LevelThree(string file) : file{file}, random{true} {}

int LevelThree::getLevel() { return 3; }

bool LevelThree::getHeavy() { return true; }

shared_ptr<Block> LevelThree::generateBlock(std::shared_ptr<Board> b, string type) {
    string block;
    if(!random) { block = getNext(); }
    else if(type != "any") { block = type; }
    else  {
        int choice = rand() % 9;
        if(choice <= 1) { block = "S"; }
        else if(choice <= 3) { block = "Z"; }
        else if(choice == 4) { block = "I"; }
        else if(choice == 5) { block = "J"; }
        else if(choice == 6) { block = "L"; }
        else if(choice == 7) { block = "O"; }
        else { block = "T"; }
    }
    return createBlock(block, getLevel(), b);
}

void LevelThree::setRandom(bool r) {
    random = r;
    if(!random) getBlockInFile(file);
}

void LevelThree::setFile(string f) { file = f; }
