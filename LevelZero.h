#ifndef BIQUADRIS_LEVELZERO_H
#define BIQUADRIS_LEVELZERO_H
#include <string>
#include <memory>
#include "Level.h"


class LevelZero : public Level {
    std::string file;
public:

    LevelZero(std::string);
    int getLevel() override;
    bool getHeavy() override;
    std::shared_ptr<Block> generateBlock(std::shared_ptr<Board>, std::string type = "any") override;
    void setRandom(bool) override;
    void setFile(string) override;

};


#endif //BIQUADRIS_LEVELZERO_H
