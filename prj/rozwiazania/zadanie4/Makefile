CC = gcc
CCFLAGS = -pedantic -g -w -std=c99
#opcja -w ukrywa -Wimplicit-function-declaration warningi, które
#	pojawiają sie przez brak pliku nagłówkowego
#	co jest konieczne aby zadanie miało sens
#	generalnie stosowanie -w jest niezalecane,tylko w wyjątkowych sytuacjach
LIB_DIR = lib

all: $(LIB_DIR)/liblib.a main 

main.o: main.c
	$(CC) -c $< $(CCFLAGS)

main: main.o
	$(CC) -o $@ $^ -L./lib -llib

$(LIB_DIR)/plik1.o: $(LIB_DIR)/plik1.c
	$(CC) -c $< -o $@ $(CCFLAGS) -I.

#creating library
$(LIB_DIR)/liblib.a:  $(LIB_DIR)/plik1.o
	ar rc $(LIB_DIR)/liblib.a $(LIB_DIR)/plik1.o

clean:
	rm -rf core *.o *.a main lib/*.o lib/*.a
