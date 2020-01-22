#include "jblock.h"
#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

JBlock::JBlock(int level,const shared_ptr<Board> b) : width{3}, height{2}, info{BlockInfo{BlockType::JBlock, Color::Blue}}, level{level} {
    string error = "Not Valid Position To Initialize";
    vector<pair<int, int>> temp = {{0,2},{1,2},{2,2},{2,3}};
    board =b;
    for(auto &p: temp) {
        if (board->validPos(p.first, (p.second))) continue;
        else throw Exception{error};
    }
    coordinates.swap(temp);
}

string JBlock::render() const {
    string shape = "J\nJJJ";
    return shape;
}

int JBlock::getWidth(){
    return width;
}

int JBlock::getHeight(){
    return height;
}
int JBlock::getLevel() {
    return level;
}

void JBlock::setWidth(int w) { width = w; }

void JBlock::setHeight(int h) { height = h; }

BlockInfo JBlock::getBlockInfo(){
    return info;
}

bool JBlock::isHeavy() {
    return this->heavy;
}

void JBlock::setHeavy(bool newHeavy) {
    heavy = newHeavy;
}
vector<pair<int, int>> JBlock::getCoord(){
    return coordinates;
}

void JBlock::setCoord(vector<pair<int,int>> newCoord){
    coordinates.clear();
    coordinates.swap(newCoord);
}

