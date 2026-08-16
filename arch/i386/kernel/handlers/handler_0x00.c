#include "interrupt.h"

extern void kernel_panic(char *str);

void isr_handler(registers_t regs) {
    switch (regs.int_no) {
        case 0:
            kernel_panic("Division by zero");
            break;
        default:
            kernel_panic("Unhandled interrupt/exception");
            break;
    }
}