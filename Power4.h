//
// Created by eii on 08/11/23.
//

#ifndef TP4_PLAY_POWER4_H
#define TP4_PLAY_POWER4_H

#include <iostream>

#include "GameGrid.h"

#define POWER4_NB_PLAYER 2
#define POWER4_WIDTH 7
#define POWER4_HEIGHT 6

using namespace std;
using namespace nsGame;

class Power4 : public GameGrid<POWER4_NB_PLAYER,POWER4_WIDTH,POWER4_HEIGHT>{

    static const char power4_form = 'O';

public:

    void init() override {

        string name0, name1;

        GameGrid::init();

        cout << "Give the name of the first player" << endl;
        cin >> name0;

        playerList[0] = new Player(name0, YELLOW);

        cout << "Give the name of the second player" << endl;
        cin >> name1;

        playerList[1] = new Player(name1, RED);

    }

    bool play(Player* player) override {

        int nbCol;

        cout << "----------------------------------------------------------------" << endl;
        cout << "Player : " << player->getName() << endl;
        cout << "Give a column number between 0 and 6" << endl;
        cin >> nbCol;

        for(int j=0; j<POWER4_HEIGHT; j++){
            if(grid[nbCol][j] == nullptr){
                grid[nbCol][j] = new Token(nbCol, j, player, power4_form);
                break;
            }
        }

        GameGrid::display();

        return true;

    }

    bool is4InRowBottom(Player* player, int i, int j) const{
        Token* token_current = grid[i][j];
        Token* token_below_1 = grid[i][j+1];
        Token* token_below_2 = grid[i][j+2];
        Token* token_below_3 = grid[i][j+3];
        if(token_current == nullptr || token_below_1 == nullptr || token_below_2 == nullptr || token_below_3 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_below_1->getPlayer()==player && token_below_2->getPlayer()==player && token_below_3->getPlayer()==player;
    }

    bool is4InRowRight(Player* player, int i, int j) const{
        Token* token_current = grid[i][j];
        Token* token_right_1 = grid[i+1][j];
        Token* token_right_2 = grid[i+2][j];
        Token* token_right_3 = grid[i+3][j];
        if(token_current == nullptr || token_right_1 == nullptr || token_right_2 == nullptr || token_right_3 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_right_1->getPlayer()==player && token_right_2->getPlayer()==player && token_right_3->getPlayer()==player;
    }

    bool is4InRowBottomRight(Player* player, int i, int j) const{
        Token* token_current = grid[i][j];
        Token* token_below_right_1 = grid[i+1][j+1];
        Token* token_below_right_2 = grid[i+2][j+2];
        Token* token_below_right_3 = grid[i+3][j+3];
        if(token_current == nullptr || token_below_right_1 == nullptr || token_below_right_2 == nullptr || token_below_right_3 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_below_right_1->getPlayer()==player && token_below_right_2->getPlayer()==player && token_below_right_3->getPlayer()==player;
    }

    bool is4InRowBottomLeft(Player* player, int i, int j) const{
        Token* token_current = grid[i][j];
        Token* token_below_left_1 = grid[i-1][j+1];
        Token* token_below_left_2 = grid[i-2][j+2];
        Token* token_below_left_3 = grid[i-3][j+3];
        if(token_current == nullptr || token_below_left_1 == nullptr || token_below_left_2 == nullptr || token_below_left_3 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_below_left_1->getPlayer()==player && token_below_left_2->getPlayer()==player && token_below_left_3->getPlayer()==player;
    }

    bool is4InRow(Player* player) const{

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

    Player* getWinner() const override{

        if(is4InRow(playerList[0])) {
            return playerList[0];
        }
        else if (is4InRow(playerList[1])) {
            return playerList[1];
        }
        else {
            return nullptr;
        }

    }

    bool isFinished() const override {

        bool res = GameGrid::isFinished();

        if(!res){
            for(int i=0; i<POWER4_WIDTH; i++){
                for(int j=0; j<POWER4_HEIGHT; j++){
                    if(grid[i][j] == nullptr){
                        return false;
                    }
                }
            }
            return true;
        }

        return res;

    }

};

#endif //TP4_PLAY_POWER4_H
