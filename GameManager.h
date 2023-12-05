//
// Created by maxime on 05/12/23.
//

#ifndef VARIOUS_GAMES_GAMEMANAGER_H
#define VARIOUS_GAMES_GAMEMANAGER_H

#include <memory>

#include "Power4.h"
#include "TicTacToe.h"

class GameManager {

private:

    int gameId;
    unique_ptr<Game> game;

public:

    void startPlaying(){

        begin_selection:

        cout << "=================================================================" << endl;
        cout << "SELECTION OF THE GAME AMONG :" << endl;
        cout << "POWER 4 : 0" << endl;
        cout << "TIC TAC TOE : 1" << endl;

        cout << "Enter ID corresponding to the game you want to play" << endl;
        cin >> gameId;

        switch (gameId) {
            case 0 :
                game = make_unique<Power4>();
                game->start();
                break;

            case 1 :
                game = make_unique<TicTacToe>();
                game->start();
                break;

            default :
                cout << "Invalid game ID" << endl;
                cout << "Try again" << endl;
                goto begin_selection;
        }


    }

};


#endif //VARIOUS_GAMES_GAMEMANAGER_H
