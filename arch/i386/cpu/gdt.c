#include <stdint.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_middle;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  base_high;
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct tss_entry_struct {
    uint32_t link;
    uint32_t esp0;
    uint32_t ss0;
    uint32_t esp1, ss1, esp2, ss2, cr3, eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi, es, cs, ss, ds, fs, gs, ldt;
    uint16_t trap, io_map_base; 
} __attribute__((packed));


struct gdt_entry gdt[6];
struct gdt_ptr gp;
struct tss_entry_struct tss_entry;

extern void gdt_flush(uint32_t);
extern void tss_flush(void);

uint8_t kernel_stack_for_tss[4096];

void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    gdt[num].base_low    = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high   = (base >> 24) & 0xFF;

    gdt[num].limit_low   = (limit & 0xFFFF);
    gdt[num].granularity = (limit >> 16) & 0x0F;

    gdt[num].granularity |= gran & 0xF0;
    gdt[num].access       = access;
}

void write_tss(int num) {
    uint32_t base = (uint32_t)&tss_entry;
    uint32_t limit = sizeof(tss_entry);
    
    gdt_set_gate(num, base, limit, 0xE9, 0x00);
    
    uint8_t *p = (uint8_t*)&tss_entry;
    for(uint32_t i = 0; i < sizeof(tss_entry); i++) p[i] = 0;
    
    tss_entry.ss0  = 0x10;
    tss_entry.esp0 = (uint32_t)kernel_stack_for_tss + 4096; 
    tss_entry.io_map_base = sizeof(tss_entry);
}

void init_gdt()
{
    gp.limit = (sizeof(struct gdt_entry) * 6) - 1;
    gp.base  = (uint32_t)&gdt;

    gdt_set_gate(0, 0, 0, 0, 0);
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
    
    write_tss(5);
    
    gdt_flush((uint32_t)&gp);
    tss_flush();
}
