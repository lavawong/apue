# make files
ROOT=..
CFLAGS=-ansi -I$(ROOT)/include -Wall -std=c99 -DMACOS -D_DARWIN_C_SOURCE $(EXTRA)
LIBOBJS=$(ROOT)/lib/apue.c
CC=gcc
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out:$(LIBOBJS) %.c
	$(CC) $(CFLAGS) $^ -o $@

print:
	@echo $(SOURCES)

clean:
	rm -f *.out
