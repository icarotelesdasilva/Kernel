#ifndef PMM_H
#define PMM_H

#include <stdint.h>
#include "../../boot/multiboot.h"

void pmm_init(multiboot_info_t* mbd);
uint32_t pmm_alock_page(void);
#endif