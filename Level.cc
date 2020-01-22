#include "Level.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "singleblock.h"
#include <iostream>
#include <fstream>
#include <string>
#include "exception.h"
#include <stdio.h>
using namespace std;


void Level::getBlockInFile(std::string file) {
    ifstream infile;
    infile.open(file);
    string block;
    while(infile >> block){
        this->blockOrder.emplace_back(block);
    }
}

string Level::getNext() {
    pos = pos % blockOrder.size();
    return blockOrder.at(pos++);
}

shared_ptr<Block> Level::createBlock(string blockName, int lev, std::shared_ptr<Board> b) {
    try {
        if (blockName == "I") return std::shared_ptr<Block>(new IBlock{lev, b});
        else if (blockName == "J") return std::shared_ptr<Block>(new JBlock{lev, b});
        else if (blockName == "L") return std::shared_ptr<Block>(new LBlock{lev, b});
        else if (blockName == "O") return std::shared_ptr<Block>(new OBlock{lev, b});
        else if (blockName == "S") return std::shared_ptr<Block>(new SBlock{lev, b});
        else if (blockName == "Z") return std::shared_ptr<Block>(new ZBlock{lev, b});
        else if (blockName == "T") return std::shared_ptr<Block>(new TBlock{lev, b});
        else if (blockName == "*") return std::shared_ptr<Block>(new SingleBlock{});
    }
    catch(Exception &e) {
        throw e;
    }

}
