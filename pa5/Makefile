#Makefile for Graph ADT and related modules.
#	make		makes FindComponents
#	make GraphTest	makes GraphTest
#	make ListTest	makes ListTest
#	make clean	removes all object and executable files

FindComponents : FindComponents.o Graph.o List.o
	gcc -o FindComponents FindComponents.o Graph.o List.o

GraphTest : GraphTest.o Graph.o List.o
	gcc -o GraphTest GraphTest.o Graph.o List.o

ListTest : ListTest.o List.o
	gcc -o ListTest ListTest.o List.o

FindComponents.o : FindComponents.c Graph.h List.h
	gcc -c -ansi -Wall FindComponents.c

GraphTest.o : GraphTest.c Graph.h List.h
	gcc -c -ansi -Wall GraphTest.c

ListTest.o : ListTest.c List.h
	gcc -c -ansi -Wall ListTest.c

Graph.o : Graph.c Graph.h List.h
	gcc -c -ansi -Wall Graph.c

List.o : List.c List.h
	gcc -c -ansi -Wall List.c
