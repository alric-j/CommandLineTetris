#include "singleblock.h"
#include <iostream>
#include <string>
using namespace std;

SingleBlock::SingleBlock() : width{1}, height{1}, info{BlockInfo{BlockType::SingleBlock, Color::Yellow}} {
    coordinates = {{5,0}};
    while(this->drop()){}
}

string SingleBlock::render() const {
    string shape = "*";
    return shape;
}
int SingleBlock::getWidth(){
    return width;
}

int SingleBlock::getHeight(){
    return height;
}
int SingleBlock::getLevel() {
    return -1;
}

void SingleBlock::setWidth(int w) { width = w; }

void SingleBlock::setHeight(int h) { height = h; }

BlockInfo SingleBlock::getBlockInfo(){
    return info;
}

bool SingleBlock::isHeavy() {
    return this->heavy;
}

void SingleBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> SingleBlock::getCoord(){
    return coordinates;
}

void SingleBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}
