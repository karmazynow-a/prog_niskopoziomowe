# Separate flags for building objects for DSOs and for the main
# executable.
#
CC = gcc
CCFLAGS = -pedantic -g -Wall -std=c99
CCOPT_SO = $(CCFLAGS) -fpic
CCOPT_EXE = $(CCFLAGS)

PLUGIN_DIR = plugins

##TU UZUPEŁNIJ - zamień nazwy plugin1 i plugin2 na nazwy twoich wtyczek
all: main $(PLUGIN_DIR)/plugin1.so $(PLUGIN_DIR)/plugin2.so

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
##TU UZUPEŁNIJ jw
$(PLUGIN_DIR)/plugin1.o: $(PLUGIN_DIR)/plugin1.c $(HTMLIZE_H)
	$(CC) -c $< -o $@ $(CCOPT_SO) -I.

$(PLUGIN_DIR)/plugin1.so: $(PLUGIN_DIR)/plugin1.o
	$(CC) -o $@ $^ -shared

$(PLUGIN_DIR)/plugin2.o: $(PLUGIN_DIR)/plugin2.c $(HTMLIZE_H)
	$(CC) -c $< -o $@ $(CCOPT_SO) -I.

$(PLUGIN_DIR)/plugin2.so: $(PLUGIN_DIR)/plugin2.o
	$(CC) -o $@ $^ -shared

clean:
	rm -rf core *.o *.a main plugins/*.o plugins/*.so 

