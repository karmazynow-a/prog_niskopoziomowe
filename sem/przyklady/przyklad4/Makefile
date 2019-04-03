# Separate flags for building objects for DSOs and for the main
# executable.
#
CC = gcc
CCFLAGS = -pedantic -g -Wall -std=c99
CCOPT_SO = $(CCFLAGS) -fpic
CCOPT_EXE = $(CCFLAGS)

PLUGIN_DIR = plugins

all: main $(PLUGIN_DIR)/fun1.so

# The main program
CALC_SRC = $(wildcard *.c)
CALC_H = $(wildcard *.h)

%.o: %.c $(CALC_H)
	$(CC) -c $< $(CCOPT_EXE)

# Link with --export-dynamic, so that public symbols will be exposed to DSOs.
main: main.o
	$(CC) -o $@ $^ -ldl -Wl,--export-dynamic

#
# Plugins
#
$(PLUGIN_DIR)/fun1.o: $(PLUGIN_DIR)/fun1.c $(HTMLIZE_H)
	$(CC) -c $< -o $@ $(CCOPT_SO) -I.

$(PLUGIN_DIR)/fun1.so: $(PLUGIN_DIR)/fun1.o
	$(CC) -o $@ $^ -shared

clean:
	rm -rf core *.o *.a main plugins/*.o plugins/*.so 

