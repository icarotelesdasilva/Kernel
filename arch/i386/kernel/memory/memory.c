#include "../../boot/multiboot.h"

extern uint32_t _fim_do_kernel;

void init_memory_system(uint32_t multiboot_addr) {
    multiboot_info_t *mbd = (multiboot_info_t *) multiboot_addr;

    uint32_t current_addr = mbd->mmap_addr;
    uint32_t limit_addr = mbd->mmap_addr + mbd->mmap_length;
    uint32_t max_ram_addr = 0;

    while (current_addr < limit_addr) {
        multiboot_memory_map_t *entry = (multiboot_memory_map_t *) current_addr;
        if (entry->type == 1) {
            uint32_t end_of_block = entry->addr + entry->len;
            if (end_of_block > max_ram_addr) max_ram_addr = end_of_block;
        }
        current_addr = current_addr + entry->size + 4;
    }

    pmm_max_pages = max_ram_addr / 4096;
    pmm_bitmap = (uint8_t *) (&_fim_do_kernel);

    for (uint32_t i = 0; i < pmm_max_pages; i++) {
        pmm_bitmap[i] = 1;
    }

    current_addr = mbd->mmap_addr;
    while (current_addr < limit_addr) {
        multiboot_memory_map_t *entry = (multiboot_memory_map_t *) current_addr;
        if (entry->type == 1) {
            uint32_t start_page = entry->addr / 4096;
            uint32_t num_pages = entry->len / 4096;

            for (uint32_t i = 0; i < num_pages; i++) {
                if ((start_page + i) < pmm_max_pages) {
                    pmm_bitmap[start_page + i] = 0;
                }
            }
        }
        current_addr = current_addr + entry->size + 4;
    }

    uint32_t end_of_protected_area = (uint32_t)(&_fim_do_kernel);
    uint32_t pages_to_protect = end_of_protected_area / 4096;

    for (uint32_t i = 0; i < pages_to_protect; i++) {
        pmm_bitmap[i] = 1;
    }
}