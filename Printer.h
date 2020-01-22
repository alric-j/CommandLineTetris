
#ifndef SIMPLE_EXAMPLE_PRINTER_H
#define SIMPLE_EXAMPLE_PRINTER_H

#include "textdisplay.h"
#include "Block.h"

using namespace std;

class Printer{
int p1level;
int p2level;
int p1score;
int p2score;
int highscore;
shared_ptr<Block> p1nextBlock;
shared_ptr<Block> p2nextBlock;
shared_ptr<TextDisplay> td1;
shared_ptr<TextDisplay> td2;
public:
    Printer();
    void setLevel(int player, int lvl);
    void setScore(int player, int score);
    void setTextDisplay(int player, shared_ptr<TextDisplay> td);
    void setBlock(int player, shared_ptr<Block> block);
    void setHighScore(int hs);
    void print();
};

#endif //SIMPLE_EXAMPLE_PRINTER_H
