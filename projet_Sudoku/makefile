bin/testeu: temp/sudoku.o temp/main.o
	g++ -o bin/sudoku temp/sudoku.o temp/main.o

temp/sudoku.o: src/sudoku.cpp
	g++ -o temp/sudoku.o -c src/sudoku.cpp -W -Wall -ansi -pedantic

temp/main.o: src/main.cpp include/sudoku.h
	g++ -o temp/main.o -c src/main.cpp -W -Wall -ansi -pedantic
