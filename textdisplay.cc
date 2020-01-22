#include "textdisplay.h"
#include "info.h"
#include <iostream>
#include <vector>
using namespace std;

TextDisplay::TextDisplay() {
    ROW = 18;
    COL = 11;
    for (int i = 0; i < ROW; i++) {
        vector<char> cells;
        for (int j = 0; j < COL; j++) {        
            cells.push_back(' ');
        }    
        board.push_back(cells);
    }
}

TextDisplay::~TextDisplay() {}

void TextDisplay::notify(Info i) {
    if(i.x < 0 || i.x > 10 || i.y < 0 || i.y > 17) return;

    if(i.type.type == BlockType::Empty)
        board[i.y][i.x] = ' ';
    else if(i.type.type == BlockType::IBlock)
        board[i.y][i.x] = 'I';
    else if(i.type.type == BlockType::JBlock)
        board[i.y][i.x] = 'J';
    else if(i.type.type == BlockType::LBlock)
        board[i.y][i.x] = 'L';
    else if(i.type.type == BlockType::OBlock)
        board[i.y][i.x] = 'O';
    else if(i.type.type == BlockType::SBlock)
        board[i.y][i.x] = 'S';
    else if(i.type.type == BlockType::ZBlock)
        board[i.y][i.x] = 'Z';
    else if(i.type.type == BlockType::TBlock)
        board[i.y][i.x] = 'T';
    else if(i.type.type == BlockType::SingleBlock)
        board[i.y][i.x] = '*';
    else if(i.type.type == BlockType::BlindBlock)
        board[i.y][i.x] = '?';
}
