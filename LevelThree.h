#ifndef BIQUADRIS_LEVELTHREE_H
#define BIQUADRIS_LEVELTHREE_H
#include <string>
#include <memory>
#include "Level.h"


class LevelThree : public Level {
    std::string file;
    bool random;
public:
    LevelThree(std::string);
    int getLevel() override;
    bool getHeavy() override;
    std::shared_ptr<Block> generateBlock(std::shared_ptr<Board>, std::string type = "any") override;
    void setRandom(bool) override;
    void setFile(string) override;
};


#endif //BIQUADRIS_LEVELTHREE_H
