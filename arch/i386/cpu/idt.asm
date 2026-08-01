global idt_load
extern idtp
global irq0_handler_stub
extern irq0_handler 

irq0_handler_stub:
PUSHAD
CALL irq0_handler
POPAD
IRET

section .text
idt_load:
    lidt [idtp]
    RET
