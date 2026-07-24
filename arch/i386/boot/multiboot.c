#include "multiboot.h"

extern void vga_print(const char *str);


void multiboot_init(uint32_t mb_addr)
{
    multiboot_info_t *mb = (multiboot_info_t *)mb_addr;


    if (!(mb->flags & MULTIBOOT_FLAG_MMAP))
    {
        vga_print("\n[ERRO] grub nao forneceu mapa de memoria (mmap)!");
    return;

    }
    vga_print("\n[ok] lendo mapa de memoria do multiboot");

multiboot_memory_map_t *mmap = (multiboot_memory_map_t *)mb->mmap_addr;
uint32_t mmap_end = mb->mmap_addr + mb->mmap_length;

while((uint32_t)mmap < mmap_end) {
    if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE) {

        vga_print("\nblk ram livre encontrada");
}
 else {
    vga_print("\nBlk Reservado/Hardware\n");
}
mmap = (multiboot_memory_map_t *)((uint32_t)mmap + mmap->size + sizeof(mmap->size));

}

}    

