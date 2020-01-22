#include "zblock.h"
#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

ZBlock::ZBlock(int level,const shared_ptr<Board> b) : width{3}, height{2}, info{BlockInfo{BlockType::ZBlock, Color::Red}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{0,2},{1,2},{1,3},{2,3}};
    board =b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);
}

string ZBlock::render() const {
    string shape = "ZZ\n ZZ";
    return shape;
}

int ZBlock::getWidth(){
    return width;
}

int ZBlock::getHeight(){
    return height;
}
int ZBlock::getLevel() {
    return level;
}

void ZBlock::setWidth(int w) { width = w; }

void ZBlock::setHeight(int h) { height = h; }

BlockInfo ZBlock::getBlockInfo(){
    return info;
}

bool ZBlock::isHeavy() {
    return this->heavy;
}

void ZBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> ZBlock::getCoord(){
    return coordinates;
}

void ZBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}
