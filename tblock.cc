#include "tblock.h"
#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

TBlock::TBlock(int level,const shared_ptr<Board> b) : width{3}, height{2}, info{BlockInfo{BlockType::TBlock, Color::Purple}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{1,3},{0,2},{1,2},{2,2}};
    board =b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);
}

string TBlock::render() const {
    string shape = "TTT\n T";
    return shape;
}

int TBlock::getWidth(){
    return width;
}

int TBlock::getHeight(){
    return height;
}
int TBlock::getLevel() {
    return level;
}

void TBlock::setWidth(int w) { width = w; }

void TBlock::setHeight(int h) { height = h; }

BlockInfo TBlock::getBlockInfo(){
    return info;
}

bool TBlock::isHeavy() {
    return this->heavy;
}

void TBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> TBlock::getCoord(){
    return coordinates;
}

void TBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}
