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

# getpid: getpid.c $(COBJS) 
#     $(CC)  $(CFLAGS) $^ -o $@.out

# child_exec: getpid.c $(COBJS) 
#     $(CC)  $(CFLAGS) $^ -o $@.out

clean:
	rm -f *.out
	rm -f *.hole
