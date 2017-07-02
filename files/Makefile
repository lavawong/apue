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

# getpid: getpid.c $(COBJS) 
#     $(CC)  $(CFLAGS) $^ -o $@.out

# child_exec: getpid.c $(COBJS) 
#     $(CC)  $(CFLAGS) $^ -o $@.out

clean:
	rm -f *.out
