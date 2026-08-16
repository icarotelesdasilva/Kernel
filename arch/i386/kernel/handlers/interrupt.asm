; interrupts.asm
[bits 32]

global isr0
extern isr_handler

section .text

isr0:
push byte 0
push byte 0
pusha
call isr_handler
popa
add esp, 8
iret