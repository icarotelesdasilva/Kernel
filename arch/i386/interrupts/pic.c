#include "pic.h"
#include <stdint.h>
#include "io.h"


void pic_remap(uint8_t offset1, uint8_t offset2) {

    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    
}