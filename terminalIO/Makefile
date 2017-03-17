# make files
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.define.$(PLATFORM)
SOURCES = .c hostent.c
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -lrt

clean:
	rm -f *.out

include $(ROOT)/Make.libapue.inc

