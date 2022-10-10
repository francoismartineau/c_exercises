# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
CC=gcc
CFLAGS=-I.			# crée automatiquement les .o à partir de .c correspondants
DEPS = stack.h		# dépendera aussi du .h

%.o: %.c $(DEPS)				# pour que les .o dépendent aussi du .h
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o stack.o
	$(CC) -o bin/$@ main.o stack.o