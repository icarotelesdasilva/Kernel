#include "../../boot/multiboot.h"
#include <stdint.h>
extern void serial_print(const char *str);
extern void serial_print_hex(uint32_t n);
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
