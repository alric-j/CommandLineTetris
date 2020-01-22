#ifndef BIQUADRIS_LEVEL_H
#define BIQUADRIS_LEVEL_H
#include <string>
#include <vector>
#include <memory>
#include "Block.h"

class Board;

class Level {
    std::vector<std::string> blockOrder;
    int pos;

protected:
    void getBlockInFile(std::string file);

    std::string getNext();
    std::shared_ptr<Block> createBlock(std::string, int, std::shared_ptr<Board>);

public:

    virtual int getLevel() = 0;
    virtual bool getHeavy() = 0;
    virtual std::shared_ptr<Block> generateBlock(std::shared_ptr<Board>, std::string type = "any") = 0;
    virtual void setRandom(bool) = 0;
    virtual void setFile(string) = 0;
};


#endif //BIQUADRIS_LEVEL_H
