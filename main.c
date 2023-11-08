#include <stdio.h>
#include <stdlib.h>
#include "crc13.h"

#define CRC13_CHUNK_SIZE    (16u)

int main(void)
{
    char *data = NULL;
    size_t length = 0u;
    ssize_t chars_read = getline(&data, &length, stdin);
    uint16_t calculated_crc = 0u;

    if (chars_read == -1)
    {
        printf("Error reading input\n");
        free(data);
        return 1;
    }

    if (data[chars_read - 1u] == '\n')
    {
        data[chars_read - 1u] = '\0';
        chars_read--;
    }

    for (size_t i = 0u; i < chars_read; i += CRC13_CHUNK_SIZE)
    {
        size_t chunk_length = (i + CRC13_CHUNK_SIZE <= chars_read) ? CRC13_CHUNK_SIZE : chars_read;

        calculated_crc ^= crc13(data + i, chunk_length);

        printf("CRC-13: 0x%X\n", calculated_crc);
    }

    free(data);

    return 0;
}
