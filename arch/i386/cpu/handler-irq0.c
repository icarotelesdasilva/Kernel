#include "../interrupts/io.h"
#include "../interrupts/pic.h"
void irq0_handler(void) {

/* 
 * This handler was placed for when it enabled the interruptions 
 * IRQ 0 sent it to IDT, but IDT did not know what to do.
 */


 // Send EOI to PIC
 pic_send_eoi(0); 

}