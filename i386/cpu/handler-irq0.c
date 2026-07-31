#include "../interrupts/io.h"
void irq0_handler(void) {

// This handler was placed for when it enabled the interruptions irq 0 sent it to idt but idt did not know what to do: (emergency update).*/

outb(0x20, 0x20); // Send EOI to PIC

}