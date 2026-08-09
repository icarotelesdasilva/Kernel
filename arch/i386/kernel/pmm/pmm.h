#ifndef PMM_H
#define PMM_H
#define TOTAL_SIZE 4096
#define TOTAL_PAGES 1024

#include <stdint.h>
#include "../../boot/multiboot.h"

uint32_t pmm_allock();

#endif