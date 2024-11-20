CC = gcc
CFLAGS = -o

all: main

main: main.c function.c
	$(CC) main.c function.c $(CFLAGS) QuizGame

clean:
	rm -f QuizGame
