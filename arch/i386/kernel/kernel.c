#include "../pmm/pmm.h"
#include "../boot/multiboot.h"
#include "../interrupts/io.h"
#include "../interrupts/pic.h"
void init_gdt(void);
extern void pic_remap(uint8_t offset1, uint8_t offset2);

extern void kernel_panic(char *str);
extern void vga_print(const char* str);
extern void idt_install(void);











void kmain(uint32_t magic, uint32_t mb_addr) {
    if (magic != 0x2BADB002) {
        kernel_panic("magic nao foi carregado pelo fato de estar errado");
        return;
    }

    init_gdt();
    vga_print("\n[ok] gdt iniciada");
    
    idt_install();
    vga_print("\n[ok] idt iniciada.");
    
    vga_print("\n[ok] multiboot detectado");
    multiboot_init(mb_addr);

    vga_print("\nligando pmm");

    pmm_init(mb_addr);
vga_print("\n[ok] pmm ligado");
vga_print("\n[ok] ligando pic");
    
pic_remap(0x20, 0x28);
vga_print("\n[ok] pic ligado");

    vga_print("\n\nHello, Kernel!");


while(1) {

 asm volatile("hlt");

}

}


