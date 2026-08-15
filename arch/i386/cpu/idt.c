#include "idt.h"

// preenche struct etc amanha
extern void isr0(void);
extern void keyboard_isr(void);
extern void irq0_handler_stub(void);
struct idt_entry idt[256];
struct idt_ptr idtp;

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {

	idt[num].base_low = (base & 0xFFFF);
	idt[num].base_hi = (base >> 16) & 0xFFFF;

	idt[num].sel = sel;

	idt[num].always0 = 0;
	idt[num].flags = flags;

}
void idt_install(void) {

	idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
	idtp.base = (uint32_t)&idt;

  for (int i = 0; i < 256; i++) { // tire os handlers do for pelo amor de deus :(
        idt_set_gate(i, 0, 0, 0);
idt_set_gate(0,  (uint32_t)isr0,  0x08, 0x8E);
	idt_set_gate(32, (uint32_t)irq0_handler_stub, 0x08, 0x8E);
	idt_set_gate(33, (uint32_t)keyboard_isr, 0x08, 0x8E);

    idt_load();
}
}
