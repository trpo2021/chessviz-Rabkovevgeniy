#include <ChessBoard.h>
#include <Consts.h>
#include <Piece.h>
#include <gtest.h>

TEST(Piece, get_simbol_of_piece)
{
    // Arrange
    Piece white_pawn{Pawn, White};
    Piece black_pawn{Pawn, Black};
    Piece white_king{King, White};
    Piece black_king{King, Black};
    Piece white_queen{Queen, White};
    Piece black_queen{Queen, Black};
    Piece white_knight{Knight, White};
    Piece black_knight{Knight, Black};
    Piece white_rook{Rook, White};
    Piece black_rook{Rook, Black};
    Piece white_bishop{Bishop, White};
    Piece black_bishop{Bishop, Black};

    char white_pawn_c;
    char black_pawn_c;
    char white_king_c;
    char black_king_c;
    char white_queen_c;
    char black_queen_c;
    char white_knight_c;
    char black_knight_c;
    char white_rook_c;
    char black_rook_c;
    char white_bishop_c;
    char black_bishop_c;

    // Act
    white_pawn_c = white_pawn.get_simbol_of_pieces();
    black_pawn_c = black_pawn.get_simbol_of_pieces();
    white_king_c = white_king.get_simbol_of_pieces();
    black_king_c = black_king.get_simbol_of_pieces();
    white_queen_c = white_queen.get_simbol_of_pieces();
    black_queen_c = black_queen.get_simbol_of_pieces();
    white_knight_c = white_knight.get_simbol_of_pieces();
    black_knight_c = black_knight.get_simbol_of_pieces();
    white_rook_c = white_rook.get_simbol_of_pieces();
    black_rook_c = black_rook.get_simbol_of_pieces();
    white_bishop_c = white_bishop.get_simbol_of_pieces();
    black_bishop_c = black_bishop.get_simbol_of_pieces();

    // Assert
    EXPECT_EQ(white_pawn_c, 'P');
    EXPECT_EQ(black_pawn_c, 'p');
    EXPECT_EQ(white_king_c, 'K');
    EXPECT_EQ(black_king_c, 'k');
    EXPECT_EQ(white_queen_c, 'Q');
    EXPECT_EQ(black_queen_c, 'q');
    EXPECT_EQ(white_knight_c, 'N');
    EXPECT_EQ(black_knight_c, 'n');
    EXPECT_EQ(white_rook_c, 'R');
    EXPECT_EQ(black_rook_c, 'r');
    EXPECT_EQ(white_bishop_c, 'B');
    EXPECT_EQ(black_bishop_c, 'b');
}

TEST(Piece, get_type_of_piece)
{
    // Arrange
    Piece white_queen{Queen, White};
    TypePieces type;

    // Act
    type = white_queen.get_type_of_piece();

    // Assert
    EXPECT_EQ(type, Queen);
}

TEST(Piece, set_type_of_piece)
{
    // Arrange
    Piece white_queen{Queen, White};
    TypePieces type;

    // Act
    white_queen.set_type_of_piece(King);
    type = white_queen.get_type_of_piece();

    // Assert
    EXPECT_EQ(type, King);
}

TEST(Piece, set_color_of_piece)
{
    // Arrange
    Piece white_queen{Queen, White};
    ColorOfPieces color;

    // Act
    color = white_queen.get_color_of_piece();

    // Assert
    EXPECT_EQ(color, White);
}