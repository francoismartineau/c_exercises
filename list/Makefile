CC=gcc
CFLAGS=-I.
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o list.o
	$(CC) -o bin/$@ main.o list.o