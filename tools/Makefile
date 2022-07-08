# Tools
CC := gcc
CFLAGS := -I. -Wall -Wextra -Wno-unused-parameter -pedantic -Ofast -s

# Not sure if n64crc has a repo somewhere that I should pull as a submodule
ifeq ($(OS),Windows_NT)
PROGRAMS := n64crc
else
PROGRAMS := n64crc lnkconv
endif

default: all

all: $(PROGRAMS)

n64crc:
	$(CC) $(CFLAGS) -o $@ $@.c

lnkconv:
	make -C pcsx-redux
	make -C pcsx-redux psyq-obj-parser
	mv pcsx-redux/psyq-obj-parser psyq-obj-parser

clean:
	rm -f *.o
	rm -f $(PROGRAMS)

.PHONY: all
