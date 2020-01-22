#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "info.h"

class TextDisplay: public Observer {
    std::vector<std::vector<char>> board;
    int ROW;
    int COL;

public:
    TextDisplay();
    void notify(Info) override;
    ~TextDisplay();

    friend class Printer;
};

#endif
