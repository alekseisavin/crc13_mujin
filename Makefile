CC=gcc
CFLAGS=-I.

crc13: crc13.c main.c
	$(CC) $(CFLAGS) -o crc13 crc13.c main.c
