//
// Created by maxime on 05/12/23.
//

#ifndef VARIOUS_GAMES_GAMEMANAGER_H
#define VARIOUS_GAMES_GAMEMANAGER_H

#include "Power4.h"
#include "TicTacToe.h"

class GameManager {

private:

    Power4 p4;
    TicTacToe ttt;

public:

    void chooseGame(){

        cout << "SELECTION OF THE GAME AMONG :" << endl;

    }

};


#endif //VARIOUS_GAMES_GAMEMANAGER_H
