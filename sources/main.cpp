#include <iostream>

#include "../headers/ExceptionHandler.h"
#include "../headers/Visualizer.h"
#include "Consts.cpp"

using namespace std;

int main()
{
    Pieces board[8][8]{}; // life array
    //------------------------------zapolnenie---------------------------
    board[0][0] = Rook_b;
    board[0][1] = Knight_b;
    board[0][2] = Bishop_b;
    board[0][3] = Queen_b;
    board[0][4] = King_b;
    board[0][5] = Bishop_b;
    board[0][6] = Knight_b;
    board[0][7] = Rook_b;

    for (int i = 0; i < 8; i++)
        board[1][i] = Pawn_b;
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = none;
    for (int i = 0; i < 8; i++)
        board[6][i] = Pawn_w;

    board[7][0] = Rook_w;
    board[7][1] = Knight_w;
    board[7][2] = Bishop_w;
    board[7][3] = Queen_w;
    board[7][4] = King_w;
    board[7][5] = Bishop_w;
    board[7][6] = Knight_w;
    board[7][7] = Rook_w;
    //-----------------------------zapolnenie------------------------------
}
