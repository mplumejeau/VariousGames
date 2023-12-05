//
// Created by eii on 08/11/23.
//

#ifndef TP4_PLAY_GAME_H
#define TP4_PLAY_GAME_H

#include <map>

#include "Player.h"

using namespace std;

namespace nsGame {

    class Game {

    public:

        virtual void start() = 0;

        virtual void init() = 0;
        virtual Player* getWinner() const = 0;
        virtual bool isFinished() const = 0;
        virtual bool play(Player* player) = 0;
        virtual void display() const = 0;
        virtual void end() = 0;

    };

}

#endif //TP4_PLAY_GAME_H