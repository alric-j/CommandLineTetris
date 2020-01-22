#include "oblock.h"
#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

OBlock::OBlock(int level,const shared_ptr<Board> b) : width{2}, height{2}, info{BlockInfo{BlockType::OBlock, Color::Yellow}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{0,2},{0,3},{1,2},{1,3}};
    board =b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);
}

string OBlock::render() const {
    string shape = "OO\nOO";
    return shape;
}

int OBlock::getWidth(){
    return width;
}

int OBlock::getHeight(){
    return height;
}
int OBlock::getLevel() {
    return level;
}

void OBlock::setWidth(int w) { width = w; }

void OBlock::setHeight(int h) { height = h; }

BlockInfo OBlock::getBlockInfo(){
    return info;
}

bool OBlock::isHeavy() {
    return this->heavy;
}

void OBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> OBlock::getCoord(){
    return coordinates;
}

void OBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}
