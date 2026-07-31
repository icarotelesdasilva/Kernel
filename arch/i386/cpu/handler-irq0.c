#include "../interrupts/io.h"
#include "../interrupts/pic.h"
void irq0_handler(void) {

// This handler was placed for when it enabled the interruptions irq 0 sent it to idt but idt did not know what to do: (emergency update).*/

 // Send EOI to PIC
 pic_send_eoi(0); 

}