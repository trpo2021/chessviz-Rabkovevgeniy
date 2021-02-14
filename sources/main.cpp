#include <iostream>
#include <string>

#include "../headers/ExceptionHandler.h"
#include "../headers/Visualizer.h"
#include "Consts.cpp"

using namespace std;

template <typename T>
void Swap(T& a, T& b);

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
    bool end_of_game = 0;
    TypePiece type_piece_for_move;
    int i1, j1, i2, j2;
    TypeMove type_move;
    Specifiers specifiers;
    TypePiece type_piece_for_transformation;

    while (!end_of_game) {
        num_move++;
        cin >> input;
        cin >> input;
        try {
            check_sintax_error(input);
        } catch (string what_hapenned) {
            cout << endl
                 << "Error " << what_hapenned << endl
                 << "in move " << num_move / 2 + 1 << ". " << input << endl;
            return 1;
        }
        if (input != "0-0-0" && input != "0-0") {
            switch (input[0]) {
            case 'K':
                type_piece_for_move = King;
                break;
            case 'Q':
                type_piece_for_move = Queen;
                break;
            case 'R':
                type_piece_for_move = Rook;
                break;
            case 'B':
                type_piece_for_move = Bishop;
                break;
            case 'N':
                type_piece_for_move = Knight;
                break;
            default:
                type_piece_for_move = Pawn;
                input.insert(0, "P");
                break;
            }

            i1 = 7 - ((int)input[2] - 49);
            j1 = (int)input[1] - 97;

            switch (input[3]) {
            case '-':
                type_move = QuietMove;
                break;
            case 'x':
                type_move = Take;
                break;
            }

            i2 = 7 - ((int)input[5] - 49);
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
                    end_of_game = 1;
                    break;
                case '+':
                    specifiers = Check;
                    break;
                }
            else
                specifiers = Ordinary;
        }
        //-------------------deshifrations-------------------------------
        //-------------------manipulations-------------------------------
        if (input != "0-0-0" && input != "0-0") {
            if (type_move == QuietMove
                && (specifiers == Ordinary || specifiers == Check
                    || specifiers == Checkmate))
                Swap(board[i1][j1], board[i2][j2]);
            if (type_move == Take && specifiers != TakingOnThePass) {
                Swap(board[i1][j1], board[i2][j2]);
                board[i1][j1] = None;
            }
            if (type_move == Take && specifiers == TakingOnThePass) {
                board[i2][j2] = board[i1][j1];
                board[i1 - 1][j1] = None;
            }
            if (specifiers == Transformation) {
                if (num_move % 2 == 1) {
                    switch (type_piece_for_transformation) {
                    case Queen:
                        board[i2][j2] = Queen_w;
                        break;
                    case Rook:
                        board[i2][j2] = Rook_w;
                        break;
                    case Bishop:
                        board[i2][j2] = Bishop_w;
                        break;
                    case Knight:
                        board[i2][j2] = Knight_w;
                        break;
                    }
                } else {
                    switch (type_piece_for_transformation) {
                    case Queen:
                        board[i2][j2] = Queen_b;
                        break;
                    case Rook:
                        board[i2][j2] = Rook_b;
                        break;
                    case Bishop:
                        board[i2][j2] = Bishop_b;
                        break;
                    case Knight:
                        board[i2][j2] = Knight_b;
                        break;
                    }
                }
                board[i1][j1] = None;
            }
        } else if (input == "0-0-0") {
            if (num_move % 2 == 1) {
                board[7][2] = King_w;
                board[7][3] = Rook_w;
                board[7][0] = None;
                board[7][4] = None;
            } else {
                board[0][2] = King_b;
                board[0][3] = Rook_b;
                board[0][0] = None;
                board[0][4] = None;
            }
        } else {
            if (num_move % 2 == 1) {
                board[7][6] = King_w;
                board[7][5] = Rook_w;
                board[7][7] = None;
                board[7][4] = None;
            } else {
                board[0][2] = King_b;
                board[0][3] = Rook_b;
                board[0][0] = None;
                board[0][4] = None;
            }
        }
        //-------------------manipulations-------------------------------
        visualize_board(board);
        cout << endl;
    }
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
