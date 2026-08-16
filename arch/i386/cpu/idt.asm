global idt_load
extern idtp ; lembrar de chamar handlers novos aqui

section .text
idt_load:
    lidt [idtp]
    ret
