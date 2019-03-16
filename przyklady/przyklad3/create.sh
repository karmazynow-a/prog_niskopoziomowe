#!/usr/bin/env bash

#folder z biblioteką
cd lib

#utowrzenie plików obiektowych
gcc -c *.c

#utowrzenie biblioteki za pomocą archivera
ar rcs liblib1.a plik1.o
ar rcs liblib2.a plik2.o

#folder główny
cd ..

#kompilacja programu głównego
#źle
#gcc main.c -L./lib -llib1 -llib2
#dobrze
gcc main.c -L./lib -llib2 -llib1
