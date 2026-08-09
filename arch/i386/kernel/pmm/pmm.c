#include "pmm.h"
#include "../../boot/multiboot.h"
#include <stdint.h>
extern void serial_print(const char *str);
extern void serial_print_hex(uint32_t n);
#define PAGE_SIZE 4096
static uint8_t* pmm_bitmap;
static uint32_t total_pages;

void pmm_init(multiboot_info_t* mbd) {
 
 uint32_t mmap_addr = mbd->mmap_addr;
 
 uint32_t mmap_length = mbd->mmap_length;
 mmap_entry_t* entry = (mmap_entry_t*) mmap_addr;
 serial_print("[PMM] cleaning map grub...\n");


 while ((uint32_t) entry < mmap_addr + mmap_length) {
      if (entry->type == 1) {
            serial_print("RAM find in: 0x");
            serial_print_hex(entry->addr_low);
            serial_print(" | Tam: 0x");
            serial_print_hex(entry->len_low); 
            serial_print("\n");
        }


	

entry = (mmap_entry_t*) ((uint32_t) entry + entry->size + sizeof(uint32_t));
   

}
}

uint32_t pmm_alock_page() {
    uint32_t bitmap_size_bytes = total_pages / 8;

    for (uint32_t i = 0; i < bitmap_size_bytes; i++) {
        if (pmm_bitmap[i] != 0xFF) {
            for (uint32_t j = 0; j < 8; j++) {
                if (!(pmm_bitmap[i] & (1 << j))) {
                    pmm_bitmap[i] |= (1 << j);
                    return (i * 8 + j) * PAGE_SIZE;
                }
            }
        }
    }
    return 0;
}