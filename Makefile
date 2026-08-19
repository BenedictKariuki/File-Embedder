CFLAGS=-O2 -Wall -std=c2x
LDFLAGS=-lbu

.PHONY: clean

embed: embed.o
	cc $(CFLAGS) $^ -o $@ $(LDFLAGS)

embed.o: embed.c embed.h
	cc $(CFLAGS) -c $<

clean:
	rm -f *.o embed
