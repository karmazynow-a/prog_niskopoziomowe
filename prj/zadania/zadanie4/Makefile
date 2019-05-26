CC = gcc
CCFLAGS = -pedantic -g -Wall -std=c99
LIB_DIR = lib

all: $(LIB_DIR)/liblib.a main 

main.o: main.c
	$(CC) -c $< $(CCFLAGS)

main: main.o
	$(CC) -o $@ $^ -L./lib -llib

clean:
	rm -rf core *.o  main
