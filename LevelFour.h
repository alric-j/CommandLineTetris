#ifndef BIQUADRIS_LEVELFOUR_H
#define BIQUADRIS_LEVELFOUR_H
#include <string>
#include <memory>
#include "Level.h"


class LevelFour : public Level {
    std::string file;
    bool random;
public:
    LevelFour(std::string);
    int getLevel() override;
    bool getHeavy() override;
    std::shared_ptr<Block> generateBlock(std::shared_ptr<Board>, std::string type = "any") override;
    void setRandom(bool) override;
    void setFile(string) override;
};


#endif //BIQUADRIS_LEVELFOUR_H
