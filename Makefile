# Makefile for the simulation program
CFLAGS = -Wall -Werror -g -std=gnu99 -Iinclude

# Target executable
TARGET = main

# Build target
$(TARGET): obj/main.o obj/simulation.o
	gcc $(CFLAGS) -o $(TARGET) obj/main.o obj/simulation.o -lgsl -lgslcblas -lm

# Compile main.o
obj/main.o: src/main.c include/simulation.h | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

# Compile simulation.o
obj/simulation.o: src/simulation.c include/simulation.h | obj
	gcc $(CFLAGS) -c src/simulation.c -o obj/simulation.o

# Clean build
clean:
	rm -rf obj $(TARGET)

