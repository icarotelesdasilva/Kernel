#ifndef PMM_H
#define PMM_H

#include <stdint.h>
#include "../../boot/multiboot.h"


extern uint8_t *pmm_bitmap;
extern uint32_t pmm_max_pages;


uintptr_t pmm_alloc_page(void);
void pmm_init_bitmap(void);
void pmm_free_page(uintptr_t physical_addr);

#endif