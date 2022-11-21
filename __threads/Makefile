CC = gcc
# Wall: enable all compiler warning messages
CFLAGS = -Wall -Wextra
NO_EXT_FILES = $(shell find . -type f  ! -name "*.*" -and ! -name "Makefile")



all: A B C

B: B.c lib.o
	@echo B appelé
	$(CC) $(CFLAGS) -o $@ $^

C: C.c lib.o lib.h
	@echo C appelé
	$(CC) $(CFLAGS) -o $@ $^	

%.o:%.c %.h


.PHONY: clean
clean:
	rm -f $(NO_EXT_FILES)
	rm -f *.o

