CC = gcc
CCFLAGS = -pedantic -g -Wall -std=c99
LIB_DIR = lib

all: $(LIB_DIR)/liblib1.a $(LIB_DIR)/liblib2.a main 

main.o: main.c
	$(CC) -c $< -o $@ $(CCFLAGS) 

main: main.o
	$(CC) -o $@ $^ -L./lib -llib2 -llib1 #ok
#	$(CC) -o $@ $^ -L./lib -llib1 -llib2  #not ok 

#linker wchodzi do lib1 i widzi definicję shout, ale nie jest ona na liście niezdefiniowanych symboli
#wiec go nie potrzebuje i pomija, dopiero w pliku lib2 potrzebna jest definicja
# i jest dodawany do listy ale juz jest za późno

$(LIB_DIR)/plik1.o: $(LIB_DIR)/plik1.c
	$(CC) -c $< -o $@ $(CCFLAGS) -I.

$(LIB_DIR)/plik2.o: $(LIB_DIR)/plik2.c
	$(CC) -c $< -o $@ $(CCFLAGS) -I.

#creating library
$(LIB_DIR)/liblib1.a:  $(LIB_DIR)/plik1.o
	ar rc $(LIB_DIR)/liblib1.a $(LIB_DIR)/plik1.o

$(LIB_DIR)/liblib2.a:  $(LIB_DIR)/plik2.o
	ar rc $(LIB_DIR)/liblib2.a $(LIB_DIR)/plik2.o

clean:
	rm -rf core *.o *.a main lib/*.o lib/*.a