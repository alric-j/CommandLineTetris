#ifndef BIQUADRIS_LEVELONE_H
#define BIQUADRIS_LEVELONE_H
#include <string>
#include <memory>
#include "Level.h"


class LevelOne : public Level {
public:
    LevelOne();
    int getLevel() override;
    bool getHeavy() override;
    std::shared_ptr<Block> generateBlock(std::shared_ptr<Board>, std::string type = "any") override;
    void setRandom(bool) override;
    void setFile(string) override;
};


#endif //BIQUADRIS_LEVELONE_H
