PObj = obj/
PBin = bin/
PSrc = src/
Plib = $(PSrc)/Chessvizlib/
CC = g++
PHeaders = src/headers
CFlags = -Wall -Wextra -Werror -I $(PHeaders) -MMD

all:$(PBin)Chessviz.out

$(PBin)Chessviz.out: $(PObj)main.o $(PObj)chessvizlib.a
	$(CC) $(CFlags) -o $@ $^

$(PObj)chessvizlib.a: $(PObj)ChessBoard.o $(PObj)Piece.o
	ar rcs $@ $^

$(PObj)%.o: $(PSrc)%.cpp
	$(CC) $(CFlags) -c $< -o $@

.PHONY: clean all
clean:
	rm -rf $(PObj)*.*
	rm -rf $(PBin)*.*

-include $(PObj)main.d $(PObj)ChessBoard.d $(PObj)Pieces.d
