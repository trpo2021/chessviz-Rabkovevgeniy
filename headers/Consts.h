#pragma once

enum Pieces {
    None,
    Pawn_w,
    King_w,
    Queen_w,
    Bishop_w,
    Knight_w,
    Rook_w,
    Pawn_b,
    King_b,
    Queen_b,
    Bishop_b,
    Knight_b,
    Rook_b
};

enum TypePiece {
    none,
    Pawn,
    King,
    Queen,
    Bishop,
    Knight,
    Rook,
};
enum TypeMove {
    QuietMove,
    Take,
};

enum Specifiers {
    Ordinary,
    Checkmate,
    Check,
    TakingOnThePass,
    Transformation,
};
