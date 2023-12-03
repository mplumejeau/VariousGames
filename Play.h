//
// Created by mpressig on 29/08/2019.
//

#ifndef PLAY_GAME_H
#define PLAY_GAME_H

#include <memory>

#include "Game.h"
#include "Power4.h"
#include "TicTacToe.h"

#define TEST 1

namespace nsGame {

    class Play {

    protected :

        unique_ptr<Game> game;
        Color current_player_;
        Color winner_;

    public :

        Play():current_player_(PLAYER1),winner_(EMPTY) {};

        virtual ~Play(){};

        virtual void run() = 0;

        void display() const{
            return game->display();
        }

        Color getWinner(){
            return winner_ = game->getWinner();
        }

    };

}

#endif //POWER4_GAME_H
