	#include <stddef.h>
#include "../../interrupts/io.h"
#include <stdint.h>
extern void outb(uint16_t port, uint8_t value);
extern uint8_t inb(uint16_t port);
extern void pic_send_eoi(uint8_t irq);
extern void keyboard_isr(void);


void keyboard_handler(void) {

    uint8_t scancode = inb(0x60);
if (!(scancode & 0x80)) {
        switch (scancode) {
            case 0x1E: 
            
                break;
            case 0x30: 
                break;
            case 0x2C: 
break;
}
}
  pic_send_eoi(1); // EOI
}