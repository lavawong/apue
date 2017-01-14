# make files
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.out,$(SOURCES))
	
all: $(OBJS)

%.out:$(LIBOBJS) %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.out
