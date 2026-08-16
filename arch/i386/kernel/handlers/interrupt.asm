; interrupts.asm
[bits 32]

global isr0
extern isr_handler

section .text

isr0:

call isr_handler