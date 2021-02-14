Chessviz.out: main.o ExceptionHandler.o Visualizer.o Consts.o
	g++ -o Chessviz.out main.o ExceptionHandler.o Visualizer.o Consts.o 

main.o: sources/main.cpp
	g++ -c sources/main.cpp

ExceptionHandler.o: sources/ExceptionHandler.cpp
	g++ -c sources/ExceptionHandler.cpp

Visualizer.o: sources/Visualizer.cpp
	g++ -c sources/Visualizer.cpp

Consts.o: sources/Consts.cpp
	g++ -c sources/Consts.cpp
