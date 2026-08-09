#include "../interrupts/io.h"
#include "../interrupts/pic.h"
#include "../boot/multiboot.h"
#include "pmm/pmm.h"

extern void pmm_init(multiboot_info_t* mbd);
uint32_t pmm_alock_page(void); 
extern void init_serial(void);
void init_gdt(void);
extern void pic_remap(uint8_t offset1, uint8_t offset2);
extern void serial_print(char *str);
extern void kernel_panic(char *str);
extern void vga_print(const char* str);
extern void idt_install(void);
extern void handler_keyboard(void);
extern void keyboard_handler(void);
extern void serial_print_hex(uint32_t n);




void kmain(uint32_t magic, uint32_t addr) {
    multiboot_info_t* mbd = (multiboot_info_t*) addr;
    uint32_t pagina_alocada; 

    init_gdt();
    idt_install();
    pic_remap(0x20, 0x28); 
    init_serial();
    
    pmm_init(mbd);

    pagina_alocada = pmm_alock_page();

    serial_print("pag alock in: 0x");
    serial_print_hex(pagina_alocada);
    serial_print("\n");
    
    serial_print("Hello from serial!\n");
    vga_print("Hello, Kernel!");

    while(1) {
        asm volatile("sti; hlt");
    }
}