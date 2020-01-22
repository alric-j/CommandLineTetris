#include <fstream>
#include <stdio.h>
#include <iostream>
#include "player.h"
#include <string>
#include <sstream>
#include <memory>
#include "Board.h"
#include "exception.h"
//#include <lib

using namespace std;

void render(Player &p1, Player &p2) {
    cout << "Level: " << p1.getLevel() << "    ";
    cout << "Level: " << p2.getLevel() << "    " << endl;
    cout << "Score: " << p1.getScore() << "    ";
}

int main(int argc, char *argv[]) {
    int highscore = 0;
    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";
    int startlevel = 0;
    int seed = 0;
    int counter = 0;
    bool onlyText = false;
    bool playable = true;
    bool newGame = false;


    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-text") {
            onlyText = true;
        } else if (arg == "-seed") {
            ++i;
            stringstream(argv[i]) >> seed;
            srand(seed);
        } else if (arg == "-scriptfile1") {
            ++i;
            stringstream(argv[i]) >> scriptfile1;
        } else if (arg == "-scriptfile2") {
            ++i;
            stringstream(argv[i]) >> scriptfile2;
        } else if (arg == "startlevel") {
            ++i;
            stringstream(argv[i]) >> startlevel;
        }
    }
    //TODO: we need to make a constructor for Player that ideally takes these fields as well
    shared_ptr<Printer> p{new Printer()};
    unique_ptr<Player> player1 = make_unique<Player>(onlyText, seed, scriptfile1, startlevel, p, 1);
    unique_ptr<Player> player2 = make_unique<Player>(onlyText, seed, scriptfile2, startlevel, p, 2);
//    p->print();
//    player1->render();
//    player2->render();

    do {

        while (playable) {
            if (counter % 2 == 0) {
                try {
                    player1->action();
                }
                catch (Exception &e) {
                    if (e.getErrorMessage() == "restart") {
                        player2->restart();
                        counter = 0;
                    } else if (e.getErrorMessage() == "Not Valid Position To Initialize") {
                        playable = false;
                    }

                }
                if (highscore < player1->getScore()) {
                    highscore = player1->getScore();
                }
                ++counter;
            } else {
                try {
                    player2->action();
                }
                catch (Exception &e) {
                    if (e.getErrorMessage() == "restart") {
                        player1->restart();
                        counter = 0;
                    } else if (e.getErrorMessage() == "Not Valid Position To Initialize") {
                        playable = false;
                    }
                }

                if (highscore < player2->getScore()) {
                    highscore = player2->getScore();
                }
                ++counter;
            }
        }

        if (player1->getScore() > player2->getScore()) {
            cout << "Player 1 Wins!!!" << endl;
        } else if (player1->getScore() == player2->getScore()) {
            cout << "It's a Tie!!!";
        } else {
            cout << "Player 2 Wins!!!";
        }

        cout << "Do you want to start a New Game Y/N" << endl;
        string inp;
        if (inp == "y" || inp == "Y") {
            newGame = true;
            player1->restart();
            player2->restart();
            counter = 0;
            playable = true;
        } else {
            newGame = false;
        }
    } while (newGame);


    cout << "Thanks for playing!" << endl;
    return 0;

}
