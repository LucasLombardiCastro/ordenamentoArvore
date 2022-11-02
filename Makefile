all: main.o
	gcc main.o -o main.bin -std=c99 -Wall
		 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o main.bin

run:
	./main.bin