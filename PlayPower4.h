//
// Created by eii on 10/11/23.
//

#ifndef TP4_PLAY_PLAYPOWER4_H
#define TP4_PLAY_PLAYPOWER4_H

#include "Play.h"

class PlayPower4 : public Play{

public :

    PlayPower4():Play(){
        game = make_unique<Power4>();
    }

    void run() override{
        Play::run();
    }

};

#endif //TP4_PLAY_PLAYPOWER4_H
