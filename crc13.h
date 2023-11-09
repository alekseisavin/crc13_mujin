/**
 * @file    crc13.h
 * @brief   Function prototypes for CRC13
 */
#ifndef CRC13_H
#define CRC13_H

#include <stdint.h>

void crc13_table_init(void);
uint16_t crc13(char* data, size_t length, uint16_t crc);

#endif /* crc13.h */

