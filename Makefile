CC=gcc
CFLAGS=-Wall -Wextra -I.

all: crc13

crc13: crc13.c main.c
	$(CC) $(CFLAGS) -o crc13 crc13.c main.c

clean:
	rm crc13


