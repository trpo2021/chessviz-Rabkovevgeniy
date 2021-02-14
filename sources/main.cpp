#include <iostream>
#include <string>

#include "../headers/ExceptionHandler.h"
#include "../headers/Visualizer.h"
#include "Consts.cpp"

using namespace std;

int main()
{
    Pieces board[8][8]; // life array
    string input;
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
            board[i][j] = None;
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
    visualize_board(board);
    cout << endl;
    //-------------------deshifrations-------------------------------
    int num_move = 0;
    bool end_of_game = 1;
    TypePiece type_piece_for_muve;
    int i1, j1, i2, j2;
    TypeMove type_move;
    Specifiers specifiers;
    TypePiece type_piece_for_transformation;

    while (end_of_game) {
        num_move++;
        cin >> input;
        if (input == "0-0-0" || input == "0-0") {
        } else {
            switch (input[0]) {
            case 'K':
                type_piece_for_muve = King;
                break;
            case 'Q':
                type_piece_for_muve = Queen;
                break;
            case 'R':
                type_piece_for_muve = Rook;
                break;
            case 'B':
                type_piece_for_muve = Bishop;
                break;
            case 'N':
                type_piece_for_muve = Knight;
                break;
            default:
                type_piece_for_muve = Pawn;
                input.insert(0, "P");
                break;
            }

            i1 = (int)input[2] - 49;
            j1 = (int)input[1] - 97;

            switch (input[3]) {
            case '-':
                type_move = QuietMove;
                break;
            case 'x':
                type_move = Take;
                break;
            }

            i2 = (int)input[5] - 49;
            j2 = (int)input[4] - 97;

            if (6 < input.length())
                switch (input[6]) {
                case 'Q':
                    type_piece_for_transformation = Queen;
                    specifiers = Transformation;
                    break;
                case 'R':
                    type_piece_for_transformation = Rook;
                    specifiers = Transformation;
                    break;
                case 'B':
                    type_piece_for_transformation = Bishop;
                    specifiers = Transformation;
                    break;
                case 'N':
                    type_piece_for_transformation = Knight;
                    specifiers = Transformation;
                    break;
                case 'e':
                    specifiers = TakingOnThePass;
                    break;
                case '#':
                    specifiers = Checkmate;
                    end_of_game = 0;
                    break;
                case '+':
                    specifiers = Check;
                    break;
                }
            else
                specifiers = Ordinary;
        }
        //-------------------deshifrations-------------------------------
    }
}
