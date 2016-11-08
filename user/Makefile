# make files
ROOT=..
CFLAGS=-ansi -I$(ROOT)/include -Wall -DMACOS -D_DARWIN_C_SOURCE $(EXTRA)
LIBOBJS=$(ROOT)/lib/apue.c
CC=gcc
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out:$(LIBOBJS) %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.out
