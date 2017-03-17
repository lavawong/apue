# make files
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.define.$(PLATFORM)
SOURCES = print_ids.c thread_join.c wrlock.c mutex_timedlock.c
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out: %.c $(LIBAPUE)
	$(CC) -lpthread $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDFLAGS)

clean:
	rm -f *.out

include $(ROOT)/Make.libapue.inc

