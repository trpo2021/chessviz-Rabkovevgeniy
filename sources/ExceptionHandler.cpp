#include "../headers/ExceptionHandler.h"
#include "../headers/Consts.h"
#include <string>

bool check_sintax_error(std::string input)
{
    if (input != "0-0-0" && input != "0-0")
        if (input.length() > 5) {
            if (input[0] != 'K' && input[0] != 'Q' && input[0] != 'R'
                && input[0] != 'B' && input[0] != 'N') {
                if (input[0] < 'a' || input[0] > 'h')
                    throw "extracted pieces type";
                else
                    input.insert(0, "P");
                if (input[1] < 'a' || input[1] > 'h')
                    if ((input[2] < '1' || input[2] > '8'))
                        throw "extracted simbol 1-8";
                if ((input[3] != '-' && input[3] != 'x'))
                    throw "extracted simbol x or -";
                if (input[4] < 'a' || input[4] > 'h')
                    throw "extracted simbol a-h";
                if ((input[5] < '1' || input[5] > '8'))
                    throw "extracted simbol 1-8";
            }
        }
    if (input.length() < 5)
        throw "notation too short";
    if (input.length() > 6) {
        if (input[6] != '#' && input[6] != '+' && input[6] != 'e'
            && input[6] != 'Q' && input[6] != 'R' && input[6] != 'B'
            && input[6] != 'N')
            throw "extracted # | + | e | Q | R | B | N";
        else {
            if (input[6] == 'e' && input[3] != 'x')
                throw "e.p. move mast be 'take'";
            if ((input[6] == 'Q' || input[6] == 'R' || input[6] == 'B'
                 || input[6] == 'N')
                && input[0] != 'P')
                throw "Only a pawn can transform";
        }
    }

    return 1;
}
