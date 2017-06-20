# make files
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.define.$(PLATFORM)
ifeq "$(PLATFORM)" "macos"
  TLOCK =
else
  TLOCK = mutex_timedlock.c
endif
SOURCES = print_ids.c thread_join.c wrlock.c $(TLOCK)
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out: %.c $(LIBAPUE)
	$(CC) -lpthread $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f *.out

include $(ROOT)/Make.libapue.inc

