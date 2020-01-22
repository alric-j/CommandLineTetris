#include "player.h"
#include "Board.h"
#include "Level.h"
#include "LevelZero.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "LevelFour.h"
#include "Block.h"
#include "singleblock.h"
#include <memory>
#include <cmath>
#include <string>
#include "exception.h"
using namespace std;

void Player::render() {
    p->print();
}

Player::Player(bool txt, int seedVal, string file, int startLev, shared_ptr<Printer> printer, int PlayerNumber) {
    text = txt;
    PlayerNo = PlayerNumber;
    scriptfile = file;
    seed = seedVal;
    score = 0;
    p=printer;
    shared_ptr<TextDisplay> td{new TextDisplay()};
    board = make_shared<Board>(text,td);
    lev = startLev;
    setLevel(startLev, seed);
    currBlock = level->generateBlock(board, "any");
    nextBlock = level->generateBlock(board, "any");


    p->setBlock(PlayerNo,nextBlock);
    p->setTextDisplay(PlayerNo,td);
    turns = 1;
    blkCount =0;
}

void Player::forceBlock(shared_ptr<Player> p, shared_ptr<Block> b) {
    p->setCurrBlock(b);
}

int Player::getScore() {
    return score;
}

void Player::calcScore(int r, int b) {
    int rowCalc = lev + r;
    score += pow(rowCalc, 2) + pow(b, 2);
    p->setScore(PlayerNo,score);
}

int Player::getLevel() {
    return lev;
}

void Player::setLevel(int l, int s) {
    if(l == 0) {
        level = make_shared<LevelZero>(scriptfile);
    }
    else if(l == 1) {
        level = make_shared<LevelOne>();
    }
    else if(l == 2) {
        level = make_shared<LevelTwo>();
    }
    else if(l == 3) {
        level = make_shared<LevelThree>(scriptfile);
    }
    else if(l == 4) {
        level = make_shared<LevelFour>(scriptfile);
    }
    lev = level->getLevel();
    p->setLevel(PlayerNo,lev);
}

shared_ptr<Block> Player::getCurrBlock() {
    return currBlock;
}

shared_ptr<Block> Player::getNextBlock() {
    return nextBlock;
}

void Player::setCurrBlock(shared_ptr<Block> cb) {
    currBlock = cb;
}

void Player::setNextBlock(shared_ptr<Block> nb) {
    nextBlock = nb;
}

void Player::restart() {
    /*shared_ptr<Board> b2{new Board(text,td)};
    board.swap(b2);
    seed = 0;
    score = 0;
    lev = 0;
    setLevel(lev, 0);
    currBlock = level->generateBlock(board, "any");
    nextBlock = level->generateBlock(board, "any");*/
}

void Player::specialAction() {
    cout << "Apply special moves:\n1. blind\n2. heavy\n3. force" << endl;
    string s;
    cin >> s;
    if(s == "blind" || s == "1") {
        //board->blind();
    }
    else if(s == "heavy" || s == "2") {
        //throw "Call heavy for other player";
    }
    else {
        //throw "Call force for other player";
    }
}

void Player::action() {
    board->placeBlock(*currBlock);
    board->addBlock(currBlock);
    render();
    string error = "restart";
    string s;
    while(cin >> s) {
        if(s == "restart") {
           // restart();
           // throw Exception{error};
        }
        else if(s == "drop") {
            currBlock->drop();
            break;
        }
        else if(s == "down") {
            currBlock->down();
        }
        else if(s == "left") {
            currBlock->left();
        }
        else if(s == "right") {
            currBlock->right();
        }
        else if(s == "clockwise") {
            currBlock->clockwise();
        }
        else if(s == "counterclockwise") {
            currBlock->counterclockwise();
        }
        else if(s == "levelup") {
            setLevel(lev+1, seed);
        }
        else if(s == "leveldown") {
            setLevel(lev-1, seed);
        }
        else if(s == "norandom") {
            level->setRandom(false);
            level->setFile(scriptfile);
        }
        else if(s == "random") {
            level->setRandom(true);
        }
        render();
    }

    blkCount++;
    vector<int> points = board->clearRow(0, 0);
    if(!points[0] && blkCount>0 && blkCount%5==0 && lev == 4) {
        shared_ptr<SingleBlock> sb = make_shared<SingleBlock>();
    }
    else {
        blkCount = 0;
    }
    if(points[0]>0) {
        calcScore(points[0], points[1]);
    }
    if(points[0] >= 2) {
       // specialAction();
    }
    currBlock = nextBlock;
    try {
        nextBlock = level->generateBlock(board, "any");
    } catch(Exception &e) {
        throw e;
    }
    p->setBlock(PlayerNo, nextBlock);
    
}
