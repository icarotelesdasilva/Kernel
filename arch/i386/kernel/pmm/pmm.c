#include "pmm.h"
#define TOTAL_SIZE 4096
#define TOTAL_PAGES 1024

static uint8_t pmm_memory[TOTAL_PAGES];
extern void serial_print(const char *str);
 extern void kernel_panic(const char *str);

void pmm_init() {

    for (int i = 0; i < TOTAL_PAGES; i++) {
        pmm_memory[i] = 0;


    }
int pag_reserved = 256;

if (pag_reserved > TOTAL_PAGES) {
    kernel_panic("PMM: Bookings covers more than the total pages!");
}

for (int i = 0; i < pag_reserved; i++) {
pmm_memory[i] = 1;
}
}
uint32_t pmm_allock() {
for (int i = 0; i < TOTAL_PAGES; i++) {
        if (pmm_memory[i] == 0) {
            pmm_memory[i] = 1;
            return i * TOTAL_SIZE;
        }
    }

    kernel_panic("PMM: out of physical memory (Out of Memory!)");
    return 0; 
}


void pmm_free_page(uint32_t paddr) {
int i = paddr / TOTAL_SIZE;
    
   if (i < 0 || i >= TOTAL_PAGES) {
        kernel_panic("PMM: Attempted to free an out-of-bounds address!");
        return;
    }
    if (pmm_memory[i] == 0) {
        kernel_panic("PMM: Double-free detected! Page is already free.");
        return;
    }

    pmm_memory[i] = 0;


}
