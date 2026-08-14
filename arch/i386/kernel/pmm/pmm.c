#include <stdint.h>

extern void kernel_panic(const char *str);

uint8_t *pmm_bitmap;
uint32_t pmm_max_pages;

uint32_t pmm_alloc_page(void) {
    for (uint32_t i = 0; i < pmm_max_pages; i++) {
        if (pmm_bitmap[i] == 0) {
            pmm_bitmap[i] = 1; 
            return i * 4096;  
    }
    }
    
    kernel_panic("My memory is gone!");
    return 0; 
}

void pmm_free_page(uintptr_t physical_addr) {
    uint32_t page_index = physical_addr / 4096;
    if (page_index < pmm_max_pages) {
        pmm_bitmap[page_index] = 0; 
}
}