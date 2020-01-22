#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <utility>
#include <string>
#include "blockinfo.h"  
#include  "Board.h"

using namespace std;

class Board;

class Block{

    /*int width;
    int height;
    BlockInfo blockinfo;
    vector<pair<int,int>> coordinates;
    bool heavy;*/
    protected:
    shared_ptr<Board> board;

public:
    Block();
    virtual int getWidth() =0;
    virtual int getHeight() =0;
    virtual int getLevel() = 0;
    virtual void setHeight(int) = 0;
    virtual void setWidth(int) = 0;
    virtual BlockInfo getBlockInfo() =0;
    virtual vector<pair<int, int>> getCoord() = 0;
    virtual void setCoord(vector<pair<int,int>>) = 0;
    //isHeavy() returns true if the block is heavy
    virtual bool isHeavy() =0;
    virtual void setHeavy(bool newHeavy) =0;


    // left() moves the block one space to the left and returns true if the action was successful
    bool left();
    // right() moves the block one space to the right and returns true if the action was successful
    bool right();
    // down() moves the block one space to the down and returns true if the action was successful
    bool down();
    // clockwise() rotates the block clockwise and returns true if the action was successful
    bool clockwise();
    // counterclockwise() rotates the block counterclockwise and returns true if the action was successful
    bool counterclockwise();
    //drop() drops the block to the bottom of the board and returns true if successful
    int drop();
    //minX returns the minimum X in the block pairs
    int minX();
    //minY returns the minimum Y in the block pairs
    int minY();


//
//    bool isClear();



    //void render() = 0;



    virtual string render() const = 0;

    virtual ~Block();
    friend std::ostream &operator<<(std::ostream &out, const Block &block);
};

#endif
