#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <memory>
#include <string>
#include "Printer.h"

// forward declaration
class Board;
class Block;
class Level;

// player class
class Player {
    // private fields
    std::shared_ptr<Board> board;
    int PlayerNo;
    shared_ptr<Printer> p;
    shared_ptr<TextDisplay> td;
    bool text;
    int score;
    int seed;
    std::string scriptfile;
    int lev;
    std::shared_ptr<Level> level;
    std::shared_ptr<Block> currBlock;
    std::shared_ptr<Block> nextBlock;
    int turns;
    int blkCount;

    public:
    // ctor
    Player(bool, int, std::string, int startLev =0, shared_ptr<Printer> p = nullptr , int PlayerNumber=1);
    
    // player actions
    void startgame();
    void render();
    void forceBlock(std::shared_ptr<Player>, std::shared_ptr<Block>);
    int getScore();
    void calcScore(int r, int b);
    int getLevel();
    void setLevel(int, int);
    std::shared_ptr<Block> getCurrBlock();
    std::shared_ptr<Block> getNextBlock();
    void setCurrBlock(std::shared_ptr<Block>);
    void setNextBlock(std::shared_ptr<Block>);
    void restart();
    void action();

    void specialAction();
};

#endif
