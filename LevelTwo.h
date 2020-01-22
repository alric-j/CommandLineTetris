#ifndef BIQUADRIS_LEVELTWO_H
#define BIQUADRIS_LEVELTWO_H
#include <string>
#include <memory>
#include "Level.h"


class LevelTwo : public Level {
public:
    LevelTwo();
    int getLevel() override;
    bool getHeavy() override;
    std::shared_ptr<Block> generateBlock(std::shared_ptr<Board>, std::string type = "any") override;
    void setRandom(bool) override;
    void setFile(string) override;
};


#endif //BIQUADRIS_LEVELTWO_H
