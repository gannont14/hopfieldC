CC = gcc
# CFLAGS = -pedantic  -Wextra -Wall -lraylib
CFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -lm -lpthread

all: main

main: main.c utils.c hopfield.c grid.c
	$(CC) main.c utils.c hopfield.c grid.c -o main $(CFLAGS)

clean:
	rm -f main
