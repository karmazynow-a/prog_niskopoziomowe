#!/usr/bin/env bash

all: main

main:	
	#utowrzenie plików obiektowych
	cd lib; gcc -c *.c 
	
	#utowrzenie biblioteki za pomocą archivera
	cd lib; ar rcs libfun1.a fun1.o 
	cd lib; ar rcs libfun2.a fun2.o 

	#kompilacja programu głównego
	gcc main.c -L./lib -lfun2 -lfun1

clean:
	rm -rf core  ./a.out ./*.o ./*.a ./lib/*.o ./lib/*.a

.PHONY: all clean