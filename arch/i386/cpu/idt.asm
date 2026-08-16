global idt_load
extern idtp ; lembrar de chamar handlers novos aqui
global irq0_handler_stub
extern irq0_handler 

irq0_handler_stub:
pushad
call irq0_handler
popad
iret

section .text
idt_load:
    lidt [idtp]
    ret
