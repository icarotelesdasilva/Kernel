extern void init_serial(void);

/*
 * Kernel 
 * Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
*/


char *serial  = (char*)0x3F8;
int colunan = 0;
int linhan  = 0;

#include "../interrupts/io.h"
#include <stdint.h>

#define COM1_PORT 0x3F8

static int serial_ready(void) {
    return inb(COM1_PORT + 5) & 0x20;
}

void serial_putc(char c) {
    while (!serial_ready()) { }
    outb(COM1_PORT, (uint8_t)c);
}

void serial_print(const char *str) {
    while (*str) {
        if (*str == '\n') {
            serial_putc('\r');
        }
        serial_putc(*str);
        str++;
    }
}

static int serial_coluna = 0;
static int serial_linha = 0;

void serial_print_hex(uint32_t n) {
    char hex_chars[] = "0123456789ABCDEF";
    char buffer[11];
    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[10] = '\0';

    for (int i = 7; i >= 0; i--) {
        buffer[2 + i] = hex_chars[n & 0xF];
        n >>= 4;
    }

    serial_print(buffer);
}