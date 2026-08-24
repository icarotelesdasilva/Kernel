#include "../../interrupts/io.h"
#include "../../interrupts/pic.h" 

static uint64_t timer_ticks = 0;

void init_pit(uint32_t frequency) {
    uint32_t divisor = 1193182 / frequency;
    outb(0x43, 0x36);
    uint8_t low = (uint8_t)(divisor & 0xFF);
    uint8_t high = (uint8_t)((divisor >> 8) & 0xFF);
    outb(0x40, low);   
    outb(0x40, high);  
}

void pit_handler(void) {
    timer_ticks++;       
    pic_send_eoi(0);     
}
