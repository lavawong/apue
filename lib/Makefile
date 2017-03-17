# apue lib
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.define.$(PLATFORM)
# SOURCES = $(wildcard *.c)
# OBJS = $(patsubst %.c,%.o,$(SOURCES))
SOURCES = %.c
OBJS = error.o tellwait.o system.o pr_exit.o err_exit.o

LIBMISC=libapue.a

all: $(OBJS)
	$(AR) -rcs $(LIBMISC) $?

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean

clean:
	-rm *.o
	-rm *.a
