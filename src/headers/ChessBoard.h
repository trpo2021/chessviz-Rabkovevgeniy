#pragma once
#include <Piece.h>

#include <iostream>
#include <string>

using namespace std;

class ChessBoard {
public:
    ChessBoard();

    void visualize_board();

    void do_chess_notation(string chess_notation);

    ~ChessBoard();

private:
    Piece* board[8][8];
    bool game_is_ended;
    int num_move;

    class Step {
    public:
        Step(string chess_notation);

        bool sintax_is_correct(string chess_notation);

        TypePieces type_piece_for_move;
        int x1, y1, x2, y2;
        TypeMove type_move;
        Specifiers specifiers;
        TypePieces type_piece_for_transformation;
    };
};
