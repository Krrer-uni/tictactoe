# Makefile

CC = g++
CFLAGS = -Wextra

all : main

main: main.o lib.o
	$(CC) $(CFLAGS) -o $@ $^ 
%.o : %.cpp 
	$(CC) $(CFLAGS) -c $^ 