#pragma once

enum TypePieces { Pawn, King, Queen, Bishop, Knight, Rook };

enum ColorOfPieces { Black, White };

enum TypeMove { QuietMove, Take };

enum Specifiers {
    Ordinary,
    Checkmate,
    Check,
    TakingOnThePass,
    Transformation,
    LongR,
    ShortR
};
