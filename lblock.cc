#include "lblock.h"
#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

LBlock::LBlock(int level,const shared_ptr<Board> b) : width{3}, height{2}, info{BlockInfo{BlockType::LBlock, Color::Orange}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{2,2},{0,3},{1,3},{2,3}};
    board =b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);


}

string LBlock::render() const {
    string shape = "  L\nLLL";
    return shape;
}

int LBlock::getWidth(){
    return width;
}

int LBlock::getHeight(){
    return height;
}
int LBlock::getLevel() {
    return level;
}

void LBlock::setWidth(int w) { width = w; }

void LBlock::setHeight(int h) { height = h; }

BlockInfo LBlock::getBlockInfo(){
    return info;
}

bool LBlock::isHeavy() {
    return this->heavy;
}

void LBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> LBlock::getCoord(){
    return coordinates;
}

void LBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}
