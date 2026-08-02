extern void init_serial(void);

/*
 * Kernel-Ícaro (vmicaro)
 * Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
*/


char *serial  = (char*)0x3F8;
int colunan = 0;
int linhan  = 0;

#include "../interrupts/io.h"
#include <stdint.h>

#define COM1_PORT 0x3F8

static inline uint8_t inb(uint16_t port) {
    uint8_t val;
    asm volatile ("inb %1, %0" : "=a"(val) : "Nd"(port));
    return val;
}

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