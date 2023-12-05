//
// Created by maxime on 04/12/23.
//

#ifndef VARIOUS_GAMES_TOKEN_H
#define VARIOUS_GAMES_TOKEN_H

#include "Player.h"

class Token {

protected:

    int x_pos;
    int y_pos;
    Player* player;
    char form;

public:

    Token(int x, int y, Player* p, char f): x_pos(x), y_pos(y), player(p), form(f) {}

    Player* getPlayer() const {
        return player;
    }

    void setPlayer(Player* p) {
        player = p;
    }

    virtual string display() {
        return colorToString[player->getColor()] + form;
    }

};


#endif //VARIOUS_GAMES_TOKEN_H
