program : main.o btree.o node.o
	g++ -O0 bin/main.o bin/btree.o bin/node.o -o bin/program

main.o : test\main.cpp src\btree.h
	g++ -c test\main.cpp -o bin\main.o

btree.o : src\btree.cpp src\btree.h
	g++ -c src\btree.cpp -o bin\btree.o

node.o : src\node.cpp src\node.h
	g++ -c src\node.cpp -o bin\node.o
