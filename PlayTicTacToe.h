//
// Created by eii on 10/11/23.
//

#ifndef TP4_PLAY_PLAYTICTACTOE_H
#define TP4_PLAY_PLAYTICTACTOE_H

#include "Play.h"

class PlayTicTacToe : public Play{

public :

    PlayTicTacToe():Play(){
        game = make_unique<TicTacToe>();
    }

    void run() override{
        Play::run();
    }

};

#endif //TP4_PLAY_PLAYTICTACTOE_H
