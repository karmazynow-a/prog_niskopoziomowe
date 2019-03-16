#!/usr/bin/env bash

#folder z biblioteką
cd lib

#utowrzenie plików obiektowych
gcc -c *.c

#utowrzenie biblioteki za pomocą archivera
ar rcs liblib.a plik1.o plik2.o

#folder główny
cd ..

#kompilacja programu głównego
gcc main.c -L./lib -llib
