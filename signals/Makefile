# make files
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.define.$(PLATFORM)
#$(wildcard *.c)
SOURCES = 
OBJS = $(patsubst %.c,%.out,$(SOURCES))

all: $(OBJS)

%.out: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDFLAGS)

clean:
	rm -f *.out

include $(ROOT)/Make.libapue.inc

