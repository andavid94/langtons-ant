output: main.o Ant.o inputValidation.o menu.o
	g++ main.o Ant.o inputValidation.o menu.o -o output

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp
	g++ -c Ant.cpp

inputValidation.o: inputValidation.cpp
	g++ -c inputValidation.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm *.o output
