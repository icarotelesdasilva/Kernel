#include "../pmm/pmm.h"
#include "../boot/multiboot.h"
#include "../interrupts/io.h"
#include "../interrupts/pic.h"
extern void init_serial(void);
void init_gdt(void);
extern void pic_remap(uint8_t offset1, uint8_t offset2);
extern void serial_print(char *str);
extern void kernel_panic(char *str);
extern void vga_print(const char* str);
extern void idt_install(void);
extern void handler_keyboard(void);
extern void keyboard_handler(void);







void kmain(uint32_t magic, uint32_t mb_addr) {
    if (magic != 0x2BADB002) {
        kernel_panic("magic nao foi carregado pelo fato de estar errado");
        return;
    }


    init_gdt();
    idt_install();
    multiboot_init(mb_addr);
    pmm_init(mb_addr);
    pic_remap(0x20, 0x28); // inicializing all  services
    init_serial();
    
    serial_print("Hello from serial!\n");
    vga_print("Hello, Kernel!");


while(1) {

 asm volatile("hlt");

}

}


