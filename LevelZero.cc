#include "LevelZero.h"
#include "iblock.h"
#include <string>
#include <memory>
using namespace std;


LevelZero::LevelZero(string file) : file{file} {
    getBlockInFile(file);
}


int LevelZero::getLevel() {
    return 0;
}

bool LevelZero::getHeavy() {
    return false;
}

shared_ptr<Block> LevelZero::generateBlock(shared_ptr<Board> b,string type) {
    return createBlock(type == "any" ? getNext() : type, getLevel(),b);
}

void LevelZero::setRandom(bool r) {}

void LevelZero::setFile(string f) { file = f; }
