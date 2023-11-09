#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "crc13.h"

#define CRC13_CHUNK_SIZE    (16u)

int main(void)
{
    char data[CRC13_CHUNK_SIZE];
    uint16_t calculated_crc = 0;

    // Read as binary
    freopen(NULL, "rb", stdin);

    // Read until EOF or chunk if full
    do
    {
	size_t bytes_read = fread(data, 1, sizeof(data), stdin);
	if (ferror(stdin))
	{
	    printf("An error occurred!\n");
	    exit(1);
	}

	if (bytes_read)
	{
	    printf("L=%lu\n", bytes_read);
	    calculated_crc = crc13(data, bytes_read, calculated_crc);
   	    printf("CRC-13: 0x%X\n", calculated_crc);
	}

    } while (!feof(stdin));

    return 0;
}
