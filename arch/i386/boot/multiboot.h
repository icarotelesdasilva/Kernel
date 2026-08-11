#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include <stdint.h>

typedef struct multiboot_memory_map {
    uint32_t size;
    uint32_t addr;
    uint32_t addr_high;
    uint32_t len;
    uint32_t len_high;
    uint32_t type;
} __attribute__((packed)) multiboot_memory_map_t;

typedef struct multiboot_info {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t syms[4];
    uint32_t mmap_length;
    uint32_t mmap_addr;
} __attribute__((packed)) multiboot_info_t;

extern uint8_t *pmm_bitmap;
extern uint32_t pmm_max_pages;
extern uint32_t kernel_end;

void init_memory_system(uint32_t multiboot_addr);

#endif