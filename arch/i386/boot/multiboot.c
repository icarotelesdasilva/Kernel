/* Copyright 2026 Icaro Teles da Silva Ribeiro @icarotelesdasilva

* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/


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

