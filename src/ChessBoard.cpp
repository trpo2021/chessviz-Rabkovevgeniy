#include <ChessBoard.h>

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

ChessBoard::ChessBoard()
{
    board[0][0] = new Piece(Rook, Black);
    board[0][1] = new Piece(Knight, Black);
    board[0][2] = new Piece(Bishop, Black);
    board[0][3] = new Piece(Queen, Black);
    board[0][4] = new Piece(King, Black);
    board[0][5] = new Piece(Bishop, Black);
    board[0][6] = new Piece(Knight, Black);
    board[0][7] = new Piece(Rook, Black);
    for (int i = 0; i < 8; i++)
        board[1][i] = new Piece(Pawn, Black);
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = nullptr;
    for (int i = 0; i < 8; i++)
        board[6][i] = new Piece(Pawn, White);
    board[7][0] = new Piece(Rook, White);
    board[7][1] = new Piece(Knight, White);
    board[7][2] = new Piece(Bishop, White);
    board[7][3] = new Piece(Queen, White);
    board[7][4] = new Piece(King, White);
    board[7][5] = new Piece(Bishop, White);
    board[7][6] = new Piece(Knight, White);
    board[7][7] = new Piece(Rook, White);
}

void ChessBoard::visualize_board()
{
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == nullptr)
                cout << "  ";
            else
                cout << board[i][j]->get_simbol_of_pieces() << " ";
        }
        cout << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

ChessBoard::~ChessBoard()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            delete board[i][j];
}

int ChessBoard::num_move = 0;

ChessBoard::Step::Step(string chess_notation)
{
    ChessBoard::num_move++;

    sintax_is_correct(chess_notation);

    if (chess_notation != "0-0-0" && chess_notation != "0-0") {
        switch (chess_notation[0]) {
        case 'K':
            this->type_piece_for_move = King;
            break;
        case 'Q':
            this->type_piece_for_move = Queen;
            break;
        case 'R':
            this->type_piece_for_move = Rook;
            break;
        case 'B':
            this->type_piece_for_move = Bishop;
            break;
        case 'N':
            this->type_piece_for_move = Knight;
            break;
        default:
            this->type_piece_for_move = Pawn;
            chess_notation.insert(0, "P");
            break;
        }

        this->x1 = 7 - ((int)chess_notation[2] - 49);
        this->y1 = (int)chess_notation[1] - 97;

        switch (chess_notation[3]) {
        case '-':
            this->type_move = QuietMove;
            break;
        case 'x':
            this->type_move = Take;
            break;
        }

        this->x2 = 7 - ((int)chess_notation[5] - 49);
        this->y2 = (int)chess_notation[4] - 97;

        if (6 < chess_notation.length())
            switch (chess_notation[6]) {
            case 'Q':
                this->type_piece_for_transformation = Queen;
                this->specifiers = Transformation;
                break;
            case 'R':
                this->type_piece_for_transformation = Rook;
                this->specifiers = Transformation;
                break;
            case 'B':
                this->type_piece_for_transformation = Bishop;
                this->specifiers = Transformation;
                break;
            case 'N':
                this->type_piece_for_transformation = Knight;
                this->specifiers = Transformation;
                break;
            case 'e':
                this->specifiers = TakingOnThePass;
                break;
            case '#':
                this->specifiers = Checkmate;
                break;
            case '+':
                this->specifiers = Check;
                break;
            }
        else
            this->specifiers = Ordinary;
    } else if (chess_notation == "0-0-0")
        this->specifiers = LongR;
    else
        this->specifiers = ShortR;
}

bool ChessBoard::Step::sintax_is_correct(string chess_notation)
{
    if (chess_notation != "0-0-0" && chess_notation != "0-0")
        if (chess_notation.length() > 5) {
            if (chess_notation[0] != 'K' && chess_notation[0] != 'Q'
                && chess_notation[0] != 'R' && chess_notation[0] != 'B'
                && chess_notation[0] != 'N') {
                if (chess_notation[0] < 'a' || chess_notation[0] > 'h')
                    throw "extracted pieces type";
                else
                    chess_notation.insert(0, "P");
                if (chess_notation[1] < 'a' || chess_notation[1] > 'h')
                    if ((chess_notation[2] < '1' || chess_notation[2] > '8'))
                        throw "extracted simbol 1-8";
                if ((chess_notation[3] != '-' && chess_notation[3] != 'x'))
                    throw "extracted simbol x or -";
                if (chess_notation[4] < 'a' || chess_notation[4] > 'h')
                    throw "extracted simbol a-h";
                if ((chess_notation[5] < '1' || chess_notation[5] > '8'))
                    throw "extracted simbol 1-8";
            }
        }
    if (chess_notation.length() < 5)
        throw "notation too short";
    if (chess_notation.length() > 6) {
        if (chess_notation[6] != '#' && chess_notation[6] != '+'
            && chess_notation[6] != 'e' && chess_notation[6] != 'Q'
            && chess_notation[6] != 'R' && chess_notation[6] != 'B'
            && chess_notation[6] != 'N')
            throw "extracted # | + | e | Q | R | B | N";
        else {
            if (chess_notation[6] == 'e' && chess_notation[3] != 'x')
                throw "e.p. move mast be 'take'";
            if ((chess_notation[6] == 'Q' || chess_notation[6] == 'R'
                 || chess_notation[6] == 'B' || chess_notation[6] == 'N')
                && chess_notation[0] != 'P')
                throw "Only a pawn can transform";
        }
    }

    return 1;
}

void ChessBoard::do_chess_notation(string chess_notation)
{
    if (game_is_ended)
        throw "Game was ended";
    Step step(chess_notation);
    if (board[step.x1][step.y1] == nullptr)
        throw "Pice on the board, does not fit the notation ";
    if (board[step.x1][step.y1]->get_type_of_piece()
        != step.type_piece_for_move)
        throw "Pice on the board, does not fit the notation ";
    if (step.specifiers == Checkmate)
        game_is_ended = true;
    if (step.specifiers != LongR && step.specifiers != ShortR) {
        if (step.type_move == QuietMove
            && (step.specifiers == Ordinary || step.specifiers == Check
                || step.specifiers == Checkmate))
            Swap(board[step.x1][step.y1], board[step.x2][step.y2]);
        if (step.type_move == Take && step.specifiers != TakingOnThePass) {
            Swap(board[step.x1][step.y1], board[step.x2][step.y2]);
            delete board[step.x1][step.y1];
            board[step.x1][step.y1] = nullptr;
        }
        if (step.type_move == Take && step.specifiers == TakingOnThePass) {
            board[step.x2][step.y2] = board[step.x1][step.y1];
            delete board[step.x1][step.y2];
            board[step.x1][step.y2] = nullptr;
        }
        if (step.specifiers == Transformation) {
            Swap(board[step.x1][step.y1], board[step.x2][step.y2]);
            board[step.x2][step.y2]->set_type_of_piece(
                    step.type_piece_for_transformation);
        }
    } else if (step.specifiers == LongR) {
        if (num_move % 2 == 1) {
            Swap(board[7][2], board[7][4]);
            Swap(board[7][3], board[7][0]);
        } else {
            Swap(board[0][2], board[0][4]);
            Swap(board[0][3], board[0][0]);
        }
    } else {
        if (num_move % 2 == 1) {
            Swap(board[7][6], board[7][4]);
            Swap(board[7][5], board[7][7]);
        } else {
            Swap(board[0][6], board[0][4]);
            Swap(board[0][5], board[0][7]);
        }
    }
}
