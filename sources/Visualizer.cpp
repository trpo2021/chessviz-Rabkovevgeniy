#include "../headers/Visualizer.h"
#include "Consts.cpp"
#include <iostream>

char get_simbol_pieces(Pieces a);

void visualize_board(Pieces board[][8])
{
    for (int i = 0; i < 8; i++) {
        std::cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            std::cout << get_simbol_pieces(board[i][j]) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  a b c d e f g h" << std::endl;
}

char get_simbol_pieces(Pieces a)
{
    switch (a) {
    case none:
        return ' ';
        break;
    case Pawn_w:
        return 'P';
        break;
    case King_w:
        return 'K';
        break;
    case Queen_w:
        return 'Q';
        break;
    case Bishop_w:
        return 'B';
        break;
    case Knight_w:
        return 'N';
        break;
    case Rook_w:
        return 'R';
        break;
    case Pawn_b:
        return 'p';
        break;
    case King_b:
        return 'k';
        break;
    case Queen_b:
        return 'q';
        break;
    case Bishop_b:
        return 'b';
        break;
    case Knight_b:
        return 'n';
        break;
    case Rook_b:
        return 'r';
        break;
    }
}
