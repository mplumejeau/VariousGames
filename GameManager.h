//
// Created by maxime on 05/12/23.
//

#ifndef VARIOUS_GAMES_GAMEMANAGER_H
#define VARIOUS_GAMES_GAMEMANAGER_H

#include "Power4.h"
#include "TicTacToe.h"

class GameManager {

private:

    int gameId;
    Power4* p4;          // gameId = 0
    TicTacToe* ttt;      // gameId = 1

public:

    void startGame(){

        cout << "SELECTION OF THE GAME AMONG :" << endl;
        cout << "POWER 4 : 0" << endl;
        cout << "TIC TAC TOE : 1" << endl;

        cout << "Enter ID corresponding to the game you want to play" << endl;
        cin >> gameId;

        switch (gameId) {
            case 0 : p4 = new Power4();
                     p4->start();
                     delete p4;
            case 1 : ttt = new TicTacToe();
                     ttt->start();
                     delete ttt;
        }

    }

};


#endif //VARIOUS_GAMES_GAMEMANAGER_H
