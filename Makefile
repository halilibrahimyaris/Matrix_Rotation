all: matrixops

matrixops: main.o matrixops.o
	gcc main.o matrixops.o -o matrixops

main.o: main.c
	gcc -c main.c

matrixops.o: matrixOps.c matrixOps.h
	gcc -c matrixOps.c

clean:
	del *.o matrixops.exe

run:
	matrixops.exe 20 30 -1 50 2