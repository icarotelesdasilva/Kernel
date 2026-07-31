#include "pic.h"
#include <stdint.h>
#include "io.h"


void pic_remap(uint8_t offset1, uint8_t offset2) {
// pic remap inicialization
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, offset1);
    outb(0xA1, offset2);

    // pic remap 
     outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x00);
    outb(0xA1, 0x00);
}