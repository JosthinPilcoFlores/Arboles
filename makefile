all: main.o tree.o
	gcc -g main.o tree.o -o test1
tree.o: tree.c tree.h
	gcc -g tree.c tree.h
main.o: main.c tree.h
	gcc -g main.c
