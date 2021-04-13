cmake_minimum_required(VERSION 3.16)

set(PSRC src/)

project(Chessviz VERSION 1)

#Build gtest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gtest"
"google test"
)

#Main target
add_executable(
Chessviz.out
${PSRC}main.cpp
${PSRC}headers/ChessBoard.h
)

#Test target
add_executable(
test_list
test/test_list.cpp
)

#Build chessvizlib
add_library(chessvizlib 
${PSRC}Piece.cpp
${PSRC}ChessBoard.cpp
${PSRC}headers/Consts.h
${PSRC}headers/Piece.h
${PSRC}headers/ChessBoard.h
)

#Adding main source to test target 
target_include_directories(
test_list PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#Add link to lib for test target
target_link_libraries(
test_list PRIVATE
gtest 
gtest_main 
chessvizlib
)

#Add link to lib for main target
target_link_libraries(
Chessviz.out
chessvizlib
)

#Add include dirs
include_directories(
${PSRC}/headers
gtest/googletest/include/gtest
)