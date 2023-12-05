//
// Created by maxime on 04/12/23.
//

#ifndef VARIOUS_GAMES_COLOR_H
#define VARIOUS_GAMES_COLOR_H

#include <string>
#include <map>

using namespace std;

enum Color {BLACK, RED, WHITE, YELLOW};

typedef map<Color,string> ColorMap;

ColorMap colorToString = {
        {BLACK, "\033[30m"},
        {RED, "\033[31m"},
        {WHITE, "\033[0m"},
        {YELLOW, "\033[33m"}
};


#endif //VARIOUS_GAMES_COLOR_H
