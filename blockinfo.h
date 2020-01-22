#ifndef BLOCKINFO_H
#define BLOCKINFO_H

enum class BlockType { IBlock, JBlock, LBlock, OBlock, SBlock, ZBlock, TBlock, Empty, SingleBlock, BlindBlock };

enum class Color { Blue, Light_Blue, Orange, Yellow, Green, Purple, Red, None };

/*struct BlockInfo{
    BlockType blocktype;
    Color colour;
};*/

struct BlockInfo {
    BlockType type;
    Color color;
};

#endif
