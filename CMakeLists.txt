set(PSRC src/)

project(Chessviz)

add_executable(Chessviz.out
${PSRC}main.cpp
${PSRC}headers/ChessBoard.h
)

add_library(chessvizlib 
${PSRC}Piece.cpp
${PSRC}ChessBoard.cpp
${PSRC}headers/Consts.h
${PSRC}headers/Piece.h
${PSRC}headers/ChessBoard.h
)

target_link_libraries(Chessviz.out
chessvizlib
)

include_directories(${PSRC}/headers)