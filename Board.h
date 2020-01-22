#ifndef BIQUADRIS_BOARD_H
#define BIQUADRIS_BOARD_H
#include "cell.h"
#include <vector>
#include <memory>
#include "textdisplay.h"
using namespace std;

class Block;
class Board{
    vector<vector<Cell>> board_cells;
    bool text;

    vector<shared_ptr<Block>> blocks;
    shared_ptr<TextDisplay> td;

public:
    Board(bool,shared_ptr<TextDisplay> td);
    bool validPos(int row, int col);
    void clearBlock(Block &block);
    void placeBlock(Block &block);
    void addBlock(shared_ptr<Block>);
    bool isRowFull(int row);
    vector<int> clearRow(int numRowsFull, int numBlocksClear);
    int isClearBlock(int row, int col, BlockInfo type);
    void dropBlocks();
    bool isPlayable();
    void blind();

};

#endif //BIQUADRIS_BOARD_H
