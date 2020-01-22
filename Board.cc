#include "Board.h"
#include "cell.h"
#include "Block.h"


Board::Board(bool text, shared_ptr<TextDisplay> td) : text{text}, td{td}{
    //setting up the initial board of empty cell

    vector<Cell> row;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            row.emplace_back(j, i, BlockInfo{BlockType::Empty, Color::None});
            row[j].attach(td);
        }
        board_cells.emplace_back(row);
        row.clear();
    }
}

bool Board::validPos(int col, int row) {
    if(col < 0 || col > 10 || row < 0 || row > 17){
        return false;
    }
    Info inf = board_cells[row][col].getInfo();
    return inf.type.type == BlockType::Empty;
}

void Board::clearBlock(Block &block) {
    vector<pair<int, int>> coords = block.getCoord();
    //setting every cell to empty on the board
    for (auto &p: coords) {
        board_cells[p.second][p.first].setType(BlockInfo{BlockType::Empty, Color::None});
        board_cells[p.second][p.first].notifyObservers(true);
    }
}

void Board::placeBlock(Block &block) {
    BlockInfo inf = block.getBlockInfo();
    int width = block.getWidth();
    if(inf.type == BlockType::IBlock){
    }

    vector<pair<int, int>> coords = block.getCoord();
    //setting every cell to empty on the board
    for (auto &p: coords) {
        board_cells[p.second][p.first].setType(block.getBlockInfo());

        board_cells[p.second][p.first].notifyObservers(false);

    }

}

void Board::addBlock(shared_ptr<Block> b) {
    blocks.emplace_back(b);
    
}

bool Board::isRowFull(int row) {
    for (int i = 0; i < 11; ++i) {
        if (board_cells[row][i].getInfo().type.type == BlockType::Empty) {
            return false;
        }
    }
    return true;
}

int Board::isClearBlock(int row, int col, BlockInfo type){
    int pointsAccumulated = 0;
    int count = 0;
    vector<shared_ptr<Block>> tempBlocks;
    vector<int> indexstore;
    for(int i = 0; i < blocks.size(); i++){
        auto &block = blocks[i];

        if(block->getBlockInfo().type == type.type){
            tempBlocks.emplace_back(block);
            indexstore.push_back(i);
            
        }
    }
    for(int j =0;j <tempBlocks.size();j++){
        auto &tempBlock = tempBlocks[j];
        for(int i = 0; i < tempBlock->getCoord().size(); i++){

            if(tempBlock->getCoord()[i].first == col && tempBlock->getCoord()[i].second == row){
                count = i;
                if(tempBlock->getCoord().size() == 1){
                    pointsAccumulated += tempBlock->getLevel() + 1;
                    vector<pair<int,int>> buffer = tempBlock->getCoord();
                    buffer.erase(buffer.begin());
                    tempBlock->setCoord(buffer);
                    blocks.erase(blocks.begin() + indexstore[j]);
                    indexstore.erase(indexstore.begin()+j);
                }else{
                vector<pair<int,int>> tempCoord = tempBlock->getCoord();
                tempCoord.erase(tempCoord.begin() + count);
                tempBlock->setCoord(tempCoord);
                }
            }
        }
    }
    return pointsAccumulated;
}

void Board::dropBlocks() {
    int total = 0;
    for(auto &block : blocks){
        total += block->drop();
    }
    if(total > 0){
        dropBlocks();
    }
}

vector<int> Board::clearRow(int numRowsFull, int numBlocksClear){
    bool noRowsFull = true;
    for(int row = 3; row < 18; row++){
        if(isRowFull(row)){
            numRowsFull++;
            for(int col = 0; col < 11; col++){
                
                numBlocksClear += isClearBlock(row, col, board_cells[row][col].getInfo().type);
                board_cells[row][col].setType(BlockInfo{BlockType::Empty, Color::None});
                board_cells[row][col].notifyObservers(true);
            }
            dropBlocks();
            --row;
        }
    }
    for(int row = 3; row < 18; row++){
        if(isRowFull(row)){
            noRowsFull = false;
        }
    }
    if(noRowsFull){
        vector<int> result = {numRowsFull, numBlocksClear};
        return result;
    } else {
        clearRow(numRowsFull, numBlocksClear);
    }
}


