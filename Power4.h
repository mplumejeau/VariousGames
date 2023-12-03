//
// Created by eii on 08/11/23.
//

#ifndef TP4_PLAY_POWER4_H
#define TP4_PLAY_POWER4_H

#include <iostream>

#include "GameT.h"

using namespace std;
using namespace nsGame;

class Power4 : public GameT<7,6>{

public:


    char getDisplayPlayer1() const override{
        return 'y';
    }

    char getDisplayPlayer2() const override{
        return 'r';
    }

    bool play(Color player) override{

        int nbCol;

        cout << "----------------------------------------------------------------" << endl;
        cout << "Player : " << player << endl;
        cout << "Give a column number between 0 and 6" << endl;
        cin >> nbCol;

        for(int j=0; j<7; j++){
            if(grid[nbCol][j] == EMPTY){
                grid[nbCol][j] = player;
                break;
            }
        }

        GameT<7, 6>::display();

        return true;

    }

    bool is4InRowBottom(Color player, int i, int j) const{
        return grid[i][j]==player && grid[i][j+1]==player && grid[i][j+2]==player && grid[i][j+3]==player;
    }

    bool is4InRowRight(Color player, int i, int j) const{
        return grid[i][j]==player && grid[i+1][j]==player && grid[i+2][j]==player && grid[i+3][j]==player;
    }

    bool is4InRowBottomRight(Color player, int i, int j) const{
        return grid[i][j]==player && grid[i+1][j+1]==player && grid[i+2][j+2]==player && grid[i+3][j+3]==player;
    }

    bool is4InRowBottomLeft(Color player, int i, int j) const{
        return grid[i][j]==player && grid[i-1][j+1]==player && grid[i-2][j+2]==player && grid[i-3][j+3]==player;
    }

    bool is4InRow(Color player) const{

        // test 4 in row bottom on the whole grid
        for(int i=0; i<7; i++){
            for(int j=0; j<3; j++){
                if(is4InRowBottom(player,i,j)){
                    return true;
                }
            }
        }

        // test 4 in row right on the whole grid
        for(int i=0; i<4; i++){
            for(int j=0; j<6; j++){
                if(is4InRowRight(player,i,j)){
                    return true;
                }
            }
        }

        // test 4 in row bottom right on the whole grid
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(is4InRowBottomRight(player,i,j)){
                    return true;
                }
            }
        }

        // test 4 in row right on the whole grid
        for(int i=3; i<7; i++){
            for(int j=0; j<3; j++){
                if(is4InRowBottomLeft(player,i,j)){
                    return true;
                }
            }
        }

        return false;

    }

    Color getWinner() const override{

        if(is4InRow(PLAYER1)) return PLAYER1;
        else if (is4InRow(PLAYER2)) return PLAYER2;
        else return EMPTY;

    }

};

#endif //TP4_PLAY_POWER4_H
