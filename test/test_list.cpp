#include <ChessBoard.h>
#include <Consts.h>
#include <Piece.h>
#include <gtest.h>

TEST(Piece, get_simbol_of_piece)
{
    // Arrange
    Piece a{Pawn, White};
    char b;

    // Act
    b = a.get_simbol_of_pieces();

    // Assert
    ASSERT_EQ(b, 'P');
}