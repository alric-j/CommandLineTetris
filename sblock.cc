#include "sblock.h"
#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

SBlock::SBlock(int level,const shared_ptr<Board> b) : width{3}, height{2}, info{BlockInfo{BlockType::SBlock, Color::Green}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{0,3},{1,3},{1,2},{2,2}};
    board =b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);
}

string SBlock::render() const {
    string shape = " SS\nSS";
    return shape;
}

int SBlock::getWidth(){
    return width;
}

int SBlock::getHeight(){
    return height;
}
int SBlock::getLevel() {
    return level;
}

void SBlock::setWidth(int w) { width = w; }

void SBlock::setHeight(int h) { height = h; }

BlockInfo SBlock::getBlockInfo(){
    return info;
}

bool SBlock::isHeavy() {
    return this->heavy;
}

void SBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> SBlock::getCoord(){
    return coordinates;
}

void SBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}
