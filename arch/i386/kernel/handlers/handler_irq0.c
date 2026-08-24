#include "../../interrupts/pic.h"
#include "../../interrupts/io.h"
#include "../../kernel/timer/pit.h"

void irq0_handler(void) {
   
    pit_handler(); 
}