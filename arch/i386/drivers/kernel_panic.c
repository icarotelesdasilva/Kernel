/*
 * Kernel 
 * Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
 */

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_COLOR 0x4F

extern char *vga;
extern int coluna;
extern int linha;

__attribute__((noreturn)) void kernel_panic(const char *str) {
    volatile char *screen = (volatile char *)0xB8000;
    int row = 0;
    int col = 0;

    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i += 2) {
        screen[i] = ' ';
        screen[i + 1] = VGA_COLOR;
    }

    while (*str != '\0') {
        char c = *str;

        if (c == '\n') {
            row++;
            col = 0;
        } else {
            if (row >= VGA_HEIGHT) {
                row = VGA_HEIGHT - 1;
            }
            if (col >= VGA_WIDTH) {
                col = 0;
                row++;
            }
            if (row >= VGA_HEIGHT) {
                row = 0;
            }

            int pos = (row * VGA_WIDTH + col) * 2;
            screen[pos] = c;
            screen[pos + 1] = VGA_COLOR;
            col++;
        }

        if (col >= VGA_WIDTH) {
            col = 0;
            row++;
        }
        if (row >= VGA_HEIGHT) {
            row = 0;
        }

        str++;
    }

    while (1) {
        __asm__ __volatile__("hlt");
    }
}
