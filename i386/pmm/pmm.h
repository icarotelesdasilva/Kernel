#ifndef PMM_H
#define PMM_H

#include <stdint.h>
#include <stddef.h>

#define PAGE_SIZE 4096

void pmm_init(uintptr_t mb_addr);
void* pmm_alloc_block(void);
void pmm_free_block(void* ptr);

#endif
