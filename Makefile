# make
ROOT = .
DIRS = $(shell ls -d */ | cut -f1 -d'/')
CC = gcc

all:
	for i in $(DIRS); do \
		if [ -f $$i/Makefile ]; then \
			(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
		fi \
	done

clean:
	for i in $(DIRS); do \
		if [ -f $$i/Makefile ]; then \
			(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
		fi \
	done
