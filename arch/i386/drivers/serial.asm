section .text

COM1_PORT equ 0x3F8

global init_serial
init_serial:

    ; clean interrupts
    mov dx, COM1_PORT + 1
    mov al, 0x00
    out dx, al

    ; enable dlab
    mov dx, COM1_PORT + 3
    mov al, 0x80
    out dx, al

    ; define speed 115200
    mov dx, COM1_PORT + 0
    mov al, 0x01
    out dx, al
    mov dx, COM1_PORT + 1
    mov al, 0x00
    out dx, al

    ; LCR
    mov dx, COM1_PORT + 3
    mov al, 0x03
    out dx, al

    ; FIFO
    mov dx, COM1_PORT + 2
    mov al, 0x03
    out dx, al

    ; MCR
    mov dx, COM1_PORT + 4
    mov al, 0x08
    out dx, al

    ret