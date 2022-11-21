CC=gcc

#MAINS = copy_str.c \
#	file_descriptor.c \
#	file_pointer.c
#EXECS = $(MAINS:.c=)


#SRCS = utils.c
#OBJS = $(SRCS:.c=.o)

EXECS = file_descriptor file_pointer copy_str test
all:$(EXECS)

test: test.c utils.c utils.h
	$(CC) -o $@ $^

file_descriptor: file_descriptor.c utils.c utils.h
	$(CC) -o $@ $^

file_pointer: file_pointer.c utils.c utils.h
	$(CC) -o $@ $^

copy_str: copy_str.c
	$(CC) -o $@ $^


utils.o: utils.c utils.h
	$(CC) -c $<

clean:
	@rm -f $(EXECS) dir.o
	@rm -f dir/*
	@echo Binaries cleaned


#$(EXECS):$(MAINS) $(OBJS)
#	@echo echo @: $@
#	@echo echo ^: $^
#	$(CC) $^ -o $@ 
#
#$(OBJS):$(SRCS)
#	$(CC) -c $< $@
