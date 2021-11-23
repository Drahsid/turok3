# Tools
CC := gcc
CFLAGS := -I. -Wall -Wextra -Wno-unused-parameter -pedantic -Ofast -s

# Not sure if n64crc has a repo somewhere that I should pull as a submodule
PROGRAMS := n64crc lnkconv/lnkconv

default: all

all: $(PROGRAMS)

n64crc:
	$(CC) $(CFLAGS) -o $@ $@.c

lnkconv/lnkconv:
	$(CC) $(CFLAGS) -o $@ lnkconv/main.c

clean:
	rm -f *.o
	rm -f $(PROGRAMS)

.PHONY: all
