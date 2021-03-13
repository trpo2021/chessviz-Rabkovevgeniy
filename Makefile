PathObj = ./obj/
PathSrc = ./src/
PathToChessvizlib = Chessvizlib/
CC = g++
PathHeaders = $(PathSrc)headers
CFlags = -Wall -Wextra -Werror -I $(PathHeaders)
ForMake = -MMD

Chessviz.out: $(PathObj)main.o $(PathObj)chessvizlib.a
	$(CC) $(CFlags) -o bin/$@ $^

$(PathObj)chessvizlib.a: $(PathObj)ExceptionHandler.o\
	$(PathObj)Visualizer.o
	ar rcs $@ $^

$(PathObj)ExceptionHandler.o: $(PathSrc)$(PathToChessvizlib)ExceptionHandler.cpp
	$(CC) $(CFlags) $(ForMake) -c $< -o $@


$(PathObj)Visualizer.o: $(PathSrc)$(PathToChessvizlib)Visualizer.cpp
	$(CC) $(CFlags) $(ForMake) -c $< -o $@

$(PathObj)main.o: $(PathSrc)main.cpp
	$(CC) $(CFlags) $(ForMake) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(PathObj)*.[oda] -f
	rm -r $(PathSrc)headers/*.h.* -f
	rm -r $(PathHeaders)$(PathToChessvizlib)/*.h.* -f
	rm -r bin/*.out -f

-include $(PathObj)Visualizer.d $(PathObj)ExceptionHandler.d $(PathObj)main.d
