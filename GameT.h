//
// Created by eii on 08/11/23.
//

#ifndef TP4_PLAY_GAMET_H
#define TP4_PLAY_GAMET_H

#include <iostream>

#include "Game.h"

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

using namespace std;
using namespace nsGame;

template <int W, int H> class GameT : public Game{

protected :

    Color grid[W][H];

public :

    void start() override{

        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                grid[i][j] = EMPTY;
            }
        }

    }

    virtual char getDisplayPlayer1() const{
        return '1';
    }

    virtual char getDisplayPlayer2() const{
        return '2';
    }

    void display() const override{

        cout << endl;
        for(int i=0; i<W; i++){
            cout << "----";
        }
        cout << "-" << endl;

        for(int j=H-1; j>=0; j--){

            cout << "| ";

            for(int i=0; i<W; i++){

                if(grid[i][j] == PLAYER1){
                    cout << YELLOW << getDisplayPlayer1() << RESET << " | ";
                }
                else if(grid[i][j] == PLAYER2){
                    cout << RED << getDisplayPlayer2() << RESET << " | ";
                }
                else {
                    cout << "  | ";
                }

            }

            cout << endl;
            for(int i=0; i<W; i++){
                cout << "----";
            }
            cout << "-" << endl;

        }

    }

    bool isFinished() const override{

        if(getWinner() != EMPTY){
            return true;
        }

        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                if(grid[i][j] == EMPTY){
                    return false;
                }
            }
        }

        return true;

    }

};

#endif //TP4_PLAY_GAMET_H
