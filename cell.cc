#include <memory>
#include "cell.h"


Cell::Cell(int x, int y, BlockInfo type) :info{x,y,type} {}

void Cell::setCoord(int col, int row ) {
    info.x = col;
    info.y = row;
}

void Cell::setType(BlockInfo b) {
    info.type = b;
}

Info Cell::getInfo() {
    return info;
}

BlockInfo Cell::getType() {
    return info.type;
}
