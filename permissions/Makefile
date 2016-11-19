# make files
ROOT=..
CFLAGS = -I$(ROOT)/include -O
COBJS= $(ROOT)/lib/apue.c 
CC=gcc
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.out
