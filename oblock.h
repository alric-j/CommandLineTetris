#ifndef OBLOCK_H
#define OBLOCK_H
#include <vector>
#include <utility>
#include <string>
#include "Block.h"
#include "blockinfo.h"

class OBlock : public Block {
    int width, height;
    BlockInfo info;
    int level;
    int heavy;
    vector<pair<int, int>> coordinates;

    public:
    OBlock(int,const shared_ptr<Board>);
    std::string render() const override;
    int getWidth() override;
    int getHeight() override;
    int getLevel() override;
    void setWidth(int) override;
    void setHeight(int) override;
    BlockInfo getBlockInfo() override;
    //isHeavy() returns true if the block is heavy
    bool isHeavy() override;
    void setHeavy(bool newHeavy) override ;
    std::vector<std::pair<int,int>> getCoord() override;
    void setCoord(vector<pair<int,int>>) override;
};

#endif
