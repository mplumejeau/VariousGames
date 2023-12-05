//
// Created by maxime on 04/12/23.
//

#ifndef VARIOUS_GAMES_PLAYER_H
#define VARIOUS_GAMES_PLAYER_H

#include "Color.h"

using namespace std;

class Player {

protected:

    string name;
    Color color;

public:

    Player(){
        name = "";
        color = WHITE;
    }

    Player(string n, Color c): name(n), color(c) {}

    string getName() const { return name; }
    Color getColor() const { return color;}

    void setName(string n) { name = n; };
    void setColor(Color c) { color = c; };

};


#endif //VARIOUS_GAMES_PLAYER_H
