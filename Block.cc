#include "Block.h"
#include "Board.h"
#include <algorithm>
#include <cmath>
using namespace std;

/*void Block::setBoard(shared_ptr<Board> b){
    board = b;
}*/

Block::Block() { }

Block::~Block() {  }

bool Block::left(){
    //clears the current block off the board
    board->clearBlock(*this);
    vector<pair<int, int>> newCoord;
    vector<pair<int, int>> initCoord = this->getCoord();

    for(auto &p: initCoord) {
        if (board->validPos(p.first-1, p.second)){
            newCoord.emplace_back(p.first - 1, p.second);
        }
        else{
            board->placeBlock(*this);
            return false;
        }

    }


    this->setCoord(newCoord);

    //places the new version of the block on the board
    board->placeBlock(*this);
    return true;
}

bool Block::right(){
    // TODO: maybe have this take a vector and a block type instead of a whole block object
    board->clearBlock(*this);
    vector<pair<int, int>> newCoord;
    vector<pair<int, int>> initCoord = this->getCoord();
    for(auto &p: initCoord) {
        if (board->validPos(p.first +1, p.second )){
            newCoord.emplace_back(p.first +1, p.second );
        }
        else{
            board->placeBlock(*this);
            return false;
        }

    }

    this->setCoord(newCoord);
    // TODO: maybe have this take a vector and a block type instead of a whole block object
    board->placeBlock(*this);
    return true;
}

bool Block::down(){
    // TODO: maybe have this take a vector and a block type instead of a whole block object
    board->clearBlock(*this);
    vector<pair<int, int>> newCoord;
    vector<pair<int, int>> initCoord = this->getCoord();
    for(auto &p: initCoord) {
        if (board->validPos(p.first, p.second + 1)){
            newCoord.emplace_back(p.first , p.second + 1);
        }
        else{
            board->placeBlock(*this);
            return false;
        }

    }

    this->setCoord(newCoord);
    // TODO: maybe have this take a vector and a block type instead of a whole block object
    board->placeBlock(*this);
    return true;
}


int Block::drop(){
    // TODO maybe there's a better way to implement this?
    int total = 0;
    while(this->down()){
        total++;
    }

    return total;
}


bool sortPair(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

bool Block::clockwise() {
    if(this->getBlockInfo().type == BlockType::OBlock) return true;
    int iWidth = getWidth();
    int iHeight = getHeight();
    int minx = this->minX();
    int miny = this->minY();
    int heightDiff = abs(iHeight-iWidth);
    bool map[iHeight][iWidth];
    for(int i = 0; i< iHeight;i++){
        for(int j = 0; j<iWidth ;j++){
            map[i][j] = false;
        }
    }

    for(auto &p: this->getCoord()){
        map[p.second - miny][p.first - minx] = true;
    }
    bool rotatedmap[iWidth][iHeight];
    for (int i=0; i<iHeight; i++){
        for (int j=0;j<iWidth; j++) {
            rotatedmap[j][iHeight - 1 - i] = map[i][j];
        }
    }
    this->setWidth(iHeight);
    this->setHeight(iWidth);
    vector<pair<int, int>> newCoord;
    for(int i = 0; i < this->getHeight(); i++) {
        for(int j = 0; j < this->getWidth(); j++) {
            if(rotatedmap[i][j]) {
                if(iWidth > iHeight) {
                    pair<int, int> val = {j+minx, i+miny-heightDiff};
                    newCoord.emplace_back(val);
                }
                else {
                    pair<int, int> val = {j+minx, i+miny+heightDiff};
                    newCoord.emplace_back(val);
                }
            }
        }
    }
    board->clearBlock(*this);
    vector<pair<int, int>> res;
    for(auto &p: newCoord) {
        if (board->validPos(p.first, p.second)){
            res.emplace_back(p.first , p.second);
        }
        else{
            board->placeBlock(*this);
            return false;
        }

    }

    this->setCoord(res);
    board->placeBlock(*this);
    return true;
}

bool Block::counterclockwise() {
    if(this->getBlockInfo().type == BlockType::OBlock) return true;
    int iWidth = getWidth();
    int iHeight = getHeight();
    int minx = this->minX();
    int miny = this->minY();
    int heightDiff = abs(iHeight-iWidth);
    bool map[iHeight][iWidth];
    for(int i = 0; i< iHeight;i++){
        for(int j = 0; j<iWidth ;j++){
            map[i][j] = false;
        }
    }

    for(auto &p: this->getCoord()){
        map[p.second - miny][p.first - minx] = true;
    }
    bool rotatedmap[iWidth][iHeight];
    for (int i=0; i<iWidth; i++){
        for (int j=0;j<iHeight; j++) {
            rotatedmap[i][j] = map[j][iWidth-i-1];
        }
    }
    this->setWidth(iHeight);
    this->setHeight(iWidth);
    vector<pair<int, int>> newCoord;
    for(int i = 0; i < this->getHeight(); i++) {
        for(int j = 0; j < this->getWidth(); j++) {
            if(rotatedmap[i][j]) {
                if(iWidth > iHeight) {
                    pair<int, int> val = {j+minx, i+miny-heightDiff};
                    newCoord.emplace_back(val);
                }
                else {
                    pair<int, int> val = {j+minx, i+miny+heightDiff};
                    newCoord.emplace_back(val);
                }
            }
        }
    }
    board->clearBlock(*this);
    vector<pair<int, int>> res;
    for(auto &p: newCoord) {
        if (board->validPos(p.first, p.second)){
            res.emplace_back(p.first , p.second);
        }
        else{
            board->placeBlock(*this);
            return false;
        }

    }

    this->setCoord(res);
    board->placeBlock(*this);
    return true;
}

int Block::minX(){
    int smallest = 11;
    for(auto &p:this->getCoord()){
        if(p.first<smallest){
            smallest = p.first;
        }
    }
    return smallest;
}

int Block::minY(){
    int smallest = 17;
    for(auto &p:this->getCoord()){
        if(p.second<smallest){
            smallest = p.second;
        }
    }
    return smallest;
}

ostream &operator<<(std::ostream &out, const Block &block) {
    out << block.render();
    return out;
}
