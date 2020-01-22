#include "Printer.h"
#include <sstream>

Printer::Printer() {
    p1level = 0;
    p2level = 0;
    p1score = 0;
    p2score = 0;
    highscore=0;
    p1nextBlock = nullptr;
    p2nextBlock = nullptr;
    td1 = nullptr;
    td2 = nullptr;
};

void Printer::setLevel(int player, int lvl) {
    if(player == 1) {
        p1level = lvl;
    }
    else{
        p2level =lvl;
    }
}

void Printer::setScore(int player, int score) {
    if(player == 1){
        p1score = score;
    }
    else{
        p2score =score;
    }
}

void Printer::setTextDisplay(int player,shared_ptr<TextDisplay> td) {
    if(player == 1){
        td1 = td;
    }
    else{
        td2  =td;
    }

}

void Printer::setHighScore(int hs){
    highscore=hs;
}

void Printer::print() {
    cout<<"Level:\t"<<p1level<<"\t\t"<<"Level:\t"<<p2level<<endl;
    cout<<"Score:\t"<<p1score<<"\t\t"<<"Score:\t"<<p2score<<endl;
    cout<<"HighScore: "<<highscore<<"\t\t"<<"HighScore: "<<highscore<<endl;
    cout<<"-----------"<<"\t\t"<<"-----------"<<endl;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++){
            cout << td1->board[i][j];
            }
        cout << "\t\t";
        for (int j = 0; j < 11; j++)
            cout << td2->board[i][j];
        cout<<endl;

    }
    cout<<"-----------"<<"\t\t"<<"-----------"<<endl;
    cout<<"Next:\t"<<" "<<"\t\t"<<"Next:\t"<<" "<<endl;
    int h1 = p1nextBlock->getHeight();
    int h2 = p2nextBlock->getHeight();
    istringstream s{p1nextBlock->render()};
    istringstream ss{p2nextBlock->render()};
    if(h1>h2) {
        for(int i = 0; i < h1; i++) {
            char c1, c2;
            while(s.get(c1)) {
                if(c1 == '\n') break;
                else cout << c1;
            }
            cout << "\t\t\t";
            while(ss.get(c2)) {
                if (c2 == '\n') break;
                else cout << c2;
            }
            cout << endl;
        }
    }
    else {
        for(int i = 0; i < h2; i++) {
            char c1, c2;
            while(s.get(c1)) {
                if(c1 == '\n') break;
                else cout << c1;
            }
            cout << "\t\t\t";
            while(ss.get(c2)) {
                if (c2 == '\n') break;
                else cout << c2;
            }
            cout << endl;
        }
    }
}

void Printer::setBlock(int player, shared_ptr<Block> block) {
    if(player == 1){
        p1nextBlock = block;
    }
    else{
        p2nextBlock = block;
    }

}

