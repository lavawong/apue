# apue lib
ROOT=..
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))
LIBMISC = $(ROOT)/lib/libapue.a

apue.o: apue.c
	gcc -ansi -I$(ROOT)/include -Wall -DMACOS -D_DARWIN_C_SOURCE -c $^ -o $@

clean:
	rm *.o