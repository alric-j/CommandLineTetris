#ifndef CELL_H
#define CELL_H
#include <memory>
#include "info.h"
#include "subject.h"

// cell class
class Cell : public Subject {
    // private fields

    Info info;


public:
    // ctor
    Cell(int, int, BlockInfo);

    // cell actions
    void setCoord(int col, int row);
    void setType(BlockInfo);
    Info getInfo();
    BlockInfo getType();
};

#endif
