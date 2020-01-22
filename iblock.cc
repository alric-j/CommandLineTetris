#include "iblock.h"
#include <iostream>
#include <string>
#include "exception.h"

using namespace std;

IBlock::IBlock(int level,const shared_ptr<Board> b) : width{4}, height{1}, info{BlockInfo{BlockType::IBlock, Color::Light_Blue}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{0,3},{1,3},{2,3},{3,3}};
    board = b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);
    //board->placeBlock(*this);

}

string IBlock::render() const {
    string shape = "IIII";
    return shape;
}

int IBlock::getWidth(){
    return width;
}

int IBlock::getHeight(){
    return height;
}
int IBlock::getLevel() {
    return level;
}

void IBlock::setWidth(int w) { width = w; }

void IBlock::setHeight(int h) { height = h; }

BlockInfo IBlock::getBlockInfo(){
    return info;
}

bool IBlock::isHeavy() {
    return this->heavy;
}

void IBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> IBlock::getCoord(){
    return coordinates;
}

void IBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}


