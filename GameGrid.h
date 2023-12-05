//
// Created by eii on 08/11/23.
//

#ifndef TP4_PLAY_GAMET_H
#define TP4_PLAY_GAMET_H

#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Token.h"

using namespace std;
using namespace nsGame;

template <int N, int W, int H> class GameGrid : public Game {

protected :

    Token* grid[W][H];
    Player* playerList[N];

public :

    void start() override{

        cout << "=================================================================" << endl;
        cout << "GAME STARTS" << endl;

        init();

        while(!isFinished()){
            for(Player* p : playerList){
                play(p);
                if(isFinished()) break;
            }
        }

        Player* winner = getWinner();

        if(winner == nullptr){
            cout << "THERE IS NO WINNER" << endl;
        }
        else {
            cout << "WINNER IS : " << winner->getName() << endl;
        }

        cout << "GAME ENDS" << endl;

        end();

    }

    void init() override {

        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                grid[i][j] = nullptr;
            }
        }

        for(int i=0; i<N; i++){
            playerList[i] = nullptr;
        }

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

                Token* current_token = grid[i][j];

                if(current_token != nullptr){
                    cout <<  current_token->display() << colorToString[WHITE] << " | ";
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

        if(getWinner() != nullptr){
            return true;
        }

        return false;

    }

    void end() override {

        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                delete grid[i][j];
            }
        }

        for(int i=0; i<N; i++){
            delete playerList[i];
        }

    }

};

#endif //TP4_PLAY_GAMET_H
