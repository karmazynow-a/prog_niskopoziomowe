# Separate flags for building objects for DSOs and for the main
# executable.
#
CC = gcc
CCFLAGS = -pedantic -g -Wall -std=c99
CCOPT_SO = $(CCFLAGS) -fpic
CCOPT_EXE = $(CCFLAGS)

CLIB_DIR = clib
PLUGIN_DIR = plugins

all: calculator $(PLUGIN_DIR)/add.so $(PLUGIN_DIR)/sub.so

# The main program
CALC_SRC = $(wildcard *.c)
CALC_H = $(wildcard *.h)

%.o: %.c $(CALC_H)
	$(CC) -c $< $(CCOPT_EXE)

# Link with --export-dynamic, so that public symbols will be exposed to DSOs.
calculator: main.o calculator.o plugin_manager.o plugin_discovery.o
	$(CC) -o $@ $^ -ldl -Wl,--export-dynamic

#
# Plugins
#
$(PLUGIN_DIR)/add.o: $(PLUGIN_DIR)/add.c $(HTMLIZE_H)
	$(CC) -c $< -o $@ $(CCOPT_SO) -I.

$(PLUGIN_DIR)/add.so: $(PLUGIN_DIR)/add.o
	$(CC) -o $@ $^ -shared

$(PLUGIN_DIR)/sub.o: $(PLUGIN_DIR)/sub.c $(HTMLIZE_H)
	$(CC) -c $< -o $@ $(CCOPT_SO) -I.

$(PLUGIN_DIR)/sub.so: $(PLUGIN_DIR)/sub.o
	$(CC) -o $@ $^ -shared

clean:
	rm -rf core *.o *.a calculator plugins/*.o plugins/*.so 

