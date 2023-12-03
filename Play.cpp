//
// Created by mpressig on 29/08/2019.
//

#include "Play.h"
#include <iostream>

using namespace std;
using namespace nsGame;

void Play::run(){

    game->start();

    cout << "=================================================================" << endl;
    cout << "GAME START" << endl;

    while(!game->isFinished()){
        game->play(PLAYER1);
        if(game->isFinished()) break;
        game->play(PLAYER2);
    }

    cout << "WINNER IS : " << getWinner() << endl;
    cout << "GAME END" << endl;

}


