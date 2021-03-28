#pragma once
#include <Consts.h>

class Piece {
public:
    Piece(TypePieces type, ColorOfPieces color);

    TypePieces get_type_of_piece();

    ColorOfPieces get_color_of_piece();

    void set_type_of_piece(TypePieces type);

    char get_simbol_of_pieces();

private:
    TypePieces type;

    ColorOfPieces color;

    bool is_used;
};
