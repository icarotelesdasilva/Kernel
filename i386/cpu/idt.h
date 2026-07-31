	#ifndef IDT_H
	#define IDT_H
	#include <stdint.h>

	struct idt_entry { // abre o molde onde vai ter dentro do idt_entry

	uint16_t base_low;
	uint16_t sel;
	uint8_t  always0;
	uint8_t  flags;
	uint16_t base_hi;
	} __attribute__((packed)); // diz ao compilador para nao mexer aqui

	struct idt_ptr {
	uint16_t limit;
	uint32_t base;




	}__attribute__((packed));

	extern void idt_load(void);
	extern void idt_install(void);

#endif
