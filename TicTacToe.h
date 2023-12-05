//
// Created by eii on 10/11/23.
//

#ifndef TP4_PLAY_TICTACTOE_H
#define TP4_PLAY_TICTACTOE_H

#include <iostream>

#include "GameGrid.h"

#define TTT_NB_PLAYER 2
#define TTT_WIDTH 3
#define TTT_HEIGHT 3

using namespace std;
using namespace nsGame;

class TicTacToe : public GameGrid<TTT_NB_PLAYER,TTT_WIDTH,TTT_HEIGHT> {

    static const char ttt_form_player0 = 'X';
    static const char ttt_form_player1 = '0';

public:

    void init() override {

        string name0, name1;

        GameGrid::init();

        cout << "Give the name of the first player" << endl;
        cin >> name0;

        playerList[0] = new Player(name0, WHITE);

        cout << "Give the name of the second player" << endl;
        cin >> name1;

        playerList[1] = new Player(name1, WHITE);

    }

    bool play(Player* player) override {

        int nbCol;
        int nbRow;

        cout << "----------------------------------------------------------------" << endl;
        cout << "Player : " << player->getName() << endl;
        cout << "Give a column number between 0 and 2" << endl;
        cin >> nbCol;
        cout << "Give a line number between 0 and 2" << endl;
        cin >> nbRow;


        if(grid[nbCol][nbRow] == nullptr){
            // ugly switch on player to associate the right form to the token
            if(player == playerList[0]){
                grid[nbCol][nbRow] = new Token(nbCol, nbRow, player, ttt_form_player0);
            } else {
                grid[nbCol][nbRow] = new Token(nbCol, nbRow, player, ttt_form_player1);
            }
        } else {
            cout << "This case is already taken" << endl;
        }

        GameGrid::display();

        return true;

    }

    bool is3InRowBottom(Player* player, int i, int j) const {
        Token* token_current = grid[i][j];
        Token* token_below_1 = grid[i][j+1];
        Token* token_below_2 = grid[i][j+2];
        if(token_current == nullptr || token_below_1 == nullptr || token_below_2 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_below_1->getPlayer()==player && token_below_2->getPlayer()==player;
    }

    bool is3InRowRight(Player* player, int i, int j) const {
        Token* token_current = grid[i][j];
        Token* token_right_1 = grid[i+1][j];
        Token* token_right_2 = grid[i+2][j];
        if(token_current == nullptr || token_right_1 == nullptr || token_right_2 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_right_1->getPlayer()==player && token_right_2->getPlayer()==player;
    }

    bool is3InRowBottomRight(Player* player, int i, int j) const {
        Token* token_current = grid[i][j];
        Token* token_below_right_1 = grid[i+1][j+1];
        Token* token_below_right_2 = grid[i+2][j+2];
        if(token_current == nullptr || token_below_right_1 == nullptr || token_below_right_2 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_below_right_1->getPlayer()==player && token_below_right_2->getPlayer()==player;
    }

    bool is3InRowBottomLeft(Player* player, int i, int j) const {
        Token* token_current = grid[i][j];
        Token* token_below_left_1 = grid[i-1][j+1];
        Token* token_below_left_2 = grid[i-2][j+2];
        if(token_current == nullptr || token_below_left_1 == nullptr || token_below_left_2 == nullptr){
            return false;
        }
        return token_current->getPlayer()==player && token_below_left_1->getPlayer()==player && token_below_left_2->getPlayer()==player;
    }

    bool is3InRow(Player* player) const {

        // test 3 in row bottom on the whole grid
        for (int i = 0; i < 3; i++) {
            if (is3InRowBottom(player, i, 0)) {
                return true;
            }
        }

        // test 3 in row right on the whole grid
        for (int j = 0; j < 3; j++) {
            if (is3InRowRight(player, 0, j)) {
                return true;
            }
        }

        // test 3 in row bottom right on the whole grid
        if (is3InRowBottomRight(player, 0, 0)) {
            return true;
        }

        // test 3 in row right on the whole grid
        if (is3InRowBottomLeft(player, 2, 0)) {
            return true;
        }

        return false;

    }

    Player* getWinner() const override {

        if(is3InRow(playerList[0])) {
            return playerList[0];
        }
        else if (is3InRow(playerList[1])) {
            return playerList[1];
        }
        else {
            return nullptr;
        }

    }

    bool isFinished() const override {

        bool res = GameGrid::isFinished();

        if(!res){
            for(int i=0; i<TTT_WIDTH; i++){
                for(int j=0; j<TTT_HEIGHT; j++){
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

#endif //TP4_PLAY_TICTACTOE_H

