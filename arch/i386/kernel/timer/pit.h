#ifndef PIT_H
#define PIT_H

#include <stdint.h>

void init_pit(uint32_t frequency);
void pit_handler(void); 

#endif
