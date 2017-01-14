# make files
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.define.$(PLATFORM)
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f *.out

include $(ROOT)/Make.libapue.inc
