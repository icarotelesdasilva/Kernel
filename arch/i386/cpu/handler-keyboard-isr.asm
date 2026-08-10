global keyboard_isr
extern keyboard_handler

section .text

keyboard_isr:
    pushad

    push ds
    push es

    mov ax, 0x10
    mov ds, ax
    mov es, ax

    call keyboard_handler

    pop es
    pop ds

    popad

    iretd
