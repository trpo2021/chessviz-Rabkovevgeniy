Chessviz.out: main.o ExceptionHandler.o Visualizer.o
	g++ -Wall -Werror -o Chessviz.out main.o ExceptionHandler.o Visualizer.o

clean:
	rm *.o


main.o: sources/main.cpp
	g++ -Wall -Werror -c sources/main.cpp

ExceptionHandler.o: sources/ExceptionHandler.cpp
	g++ -Wall -Werror -c sources/ExceptionHandler.cpp

Visualizer.o: sources/Visualizer.cpp
	g++ -Wall -Werror -c sources/Visualizer.cpp
