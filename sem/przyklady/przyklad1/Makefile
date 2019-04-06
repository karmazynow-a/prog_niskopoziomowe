CC = gcc
CCFLAGS = -pedantic -g -gdwarf -Wall -std=c99
LIB_DIR = lib

all: $(LIB_DIR)/liblib.a main 

main.o: main.c
	$(CC) -c $< $(CCFLAGS)

main: main.o
	$(CC) -o $@ $^ -L./lib -llib

$(LIB_DIR)/plik1.o: $(LIB_DIR)/plik1.c
	$(CC) -c $< -o $@ $(CCFLAGS) -I.

$(LIB_DIR)/plik2.o: $(LIB_DIR)/plik2.c
	$(CC) -c $< -o $@ $(CCFLAGS) -I.

#creating library
$(LIB_DIR)/liblib.a:  $(LIB_DIR)/plik1.o $(LIB_DIR)/plik2.o
	ar rc $(LIB_DIR)/liblib.a $(LIB_DIR)/plik1.o $(LIB_DIR)/plik2.o

clean:
	rm -rf core *.o *.a main lib/*.o lib/*.a
