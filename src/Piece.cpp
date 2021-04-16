#include <Piece.h>

Piece::Piece(TypePieces type, ColorOfPieces color)
{
    this->type = type;
    this->color = color;
}

TypePieces Piece::get_type_of_piece()
{
    return this->type;
}

ColorOfPieces Piece::get_color_of_piece()
{
    return this->color;
}

void Piece::set_type_of_piece(TypePieces type)
{
    this->type = type;
}

char Piece::get_simbol_of_pieces()
{
    switch (this->type) {
    case Pawn:
        return this->color == White ? 'P' : 'p';
        break;
    case King:
        return this->color == White ? 'K' : 'k';
        break;
    case Queen:
        return this->color == White ? 'Q' : 'q';
        break;
    case Bishop:
        return this->color == White ? 'B' : 'b';
        break;
    case Knight:
        return this->color == White ? 'N' : 'n';
        break;
    case Rook:
        return this->color == White ? 'R' : 'r';
        break;
    default:
        return '!';
    }
}
