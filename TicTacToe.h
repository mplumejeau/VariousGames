//
// Created by eii on 10/11/23.
//

#ifndef TP4_PLAY_TICTACTOE_H
#define TP4_PLAY_TICTACTOE_H

#include <iostream>

#include "GameT.h"

using namespace std;
using namespace nsGame;

class TicTacToe : public GameT<3,3> {

public:

    char getDisplayPlayer1() const override {
        return 'x';
    }

    char getDisplayPlayer2() const override {
        return 'o';
    }

    bool play(Color player) override {

        int nbCol;
        int nbLin;

        cout << "----------------------------------------------------------------" << endl;
        cout << "Player : " << player << endl;
        cout << "Give a column number between 0 and 2" << endl;
        cin >> nbCol;
        cout << "Give a line number between 0 and 2" << endl;
        cin >> nbLin;


        if(grid[nbCol][nbLin] == EMPTY){
            grid[nbCol][nbLin] = player;
        } else {
            cout << "This case is already taken" << endl << "sorry :(" << endl;
        }

        GameT<3, 3>::display();

        return true;

    }

    bool is3InRowBottom(Color player, int i, int j) const {
        return grid[i][j] == player && grid[i][j + 1] == player && grid[i][j + 2] == player;
    }

    bool is3InRowRight(Color player, int i, int j) const {
        return grid[i][j] == player && grid[i + 1][j] == player && grid[i + 2][j] == player;
    }

    bool is3InRowBottomRight(Color player, int i, int j) const {
        return grid[i][j] == player && grid[i + 1][j + 1] == player && grid[i + 2][j + 2] == player;
    }

    bool is3InRowBottomLeft(Color player, int i, int j) const {
        return grid[i][j] == player && grid[i - 1][j + 1] == player && grid[i - 2][j + 2] == player;
    }

    bool is3InRow(Color player) const {

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

    Color getWinner() const override {

        if (is3InRow(PLAYER1)) return PLAYER1;
        else if (is3InRow(PLAYER2)) return PLAYER2;
        else return EMPTY;

    }

};

#endif //TP4_PLAY_TICTACTOE_H

