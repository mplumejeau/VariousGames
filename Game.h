//
// Created by eii on 08/11/23.
//

#ifndef TP4_PLAY_GAME_H
#define TP4_PLAY_GAME_H

namespace nsGame {

    enum Color {EMPTY, PLAYER1, PLAYER2};

    class Game {

    public:

        virtual bool isFinished() const = 0;
        virtual Color getWinner() const = 0;
        virtual void display() const = 0;
        virtual void start() = 0;
        virtual bool play(Color player) = 0;

    };

}

#endif //TP4_PLAY_GAME_H