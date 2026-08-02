#include "multiboot.h"
extern void serial_print(const char *str);
extern void vga_print(const char *str);
extern void kernel_panic(char *str);

void multiboot_init(uint32_t mb_addr)
{
    multiboot_info_t *mb = (multiboot_info_t *)mb_addr;


    if (!(mb->flags & MULTIBOOT_FLAG_MMAP))
    {
        kernel_panic("\n[ERRO] grub nao forneceu mapa de memoria (mmap)!");
    return;

    }
   

multiboot_memory_map_t *mmap = (multiboot_memory_map_t *)mb->mmap_addr;
uint32_t mmap_end = mb->mmap_addr + mb->mmap_length;

while((uint32_t)mmap < mmap_end) {
    if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE) {

        serial_print("\nblk ram livre encontrada");
}
 else {
    serial_print("\nBlk Reservado/Hardware\n");
}
mmap = (multiboot_memory_map_t *)((uint32_t)mmap + mmap->size + sizeof(mmap->size));

}

}    

