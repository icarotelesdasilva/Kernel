#include "../interrupts/io.h"
#include "../interrupts/pic.h"
#include "../boot/multiboot.h"
#include "pmm/pmm.h"
#include "vmm/vmm.h"
extern void irq12_stub(void);
void mouse_register_interrupt(void);
void ps2_mouse_init(int screen_width, int screen_height);
void unmask_mouse_irq(void);
void ps2_mouse_handle_interrupt(int screen_width, int screen_height);
extern void ps2_mouse_get_state(void);
extern uintptr_t pmm_alloc_page(void);
extern void pmm_free_page(uintptr_t paddr);
extern void init_memory_system(uint32_t multiboot_addr); 
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
       if (magic != 0x2BADB002) {
        kernel_panic("My magic number is wrong!");
    }
    init_gdt();
    pic_remap(0x20, 0x28); 
    idt_install();
    mouse_register_interrupt();
    ps2_mouse_init(800, 600);
    unmask_mouse_irq();
    
    init_serial();
    
    init_memory_system(addr);
    
    uint32_t pagina1 = pmm_alloc_page();
    serial_print("Page allocated in: 0x");
    serial_print_hex(pagina1);
    serial_print("\n");

    uint32_t pagina2 = pmm_alloc_page();
    serial_print("Second page allocated on: 0x");
    serial_print_hex(pagina2);
    serial_print("\n");

    serial_print("Releasing the front page...\n");
    pmm_free_page(pagina1);

    uint32_t pagina3 = pmm_alloc_page();
    serial_print("New Allocated Page (must repurpose): 0x");
    serial_print_hex(pagina3);
    serial_print("\n"); 
    vmm_init(); 
    serial_print("Hello from serial!\n");
    vga_print("Hello, Kernel!");


    while(1) {
        asm volatile("sti; hlt");
    }
}