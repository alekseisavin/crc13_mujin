#include <stdio.h>
#include <stdlib.h>
#include "crc13.h"

int main(void)
{
    char *data = NULL;
    size_t length = 0u;
    ssize_t chars_read = getline(&data, &length, stdin);

    if (chars_read == -1)
    {
        printf("Error reading input\n");
        free(data);
        return 1;
    }

    if (data[chars_read - 1u] == '\n')
    {
        data[chars_read - 1u] = '\0';
    }

    printf("CRC-13: 0x%X\n", crc13(data, chars_read - 1u));

    free(data);

    return 0;
}
