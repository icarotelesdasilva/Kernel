section .text

COM1_PORT equ 0x3F8

global init_serial
init_serial:
    ; clean interrupts
    MOV dx, COM1_PORT + 1
    MOV al, 0x00
    OUT dx, al

    ; enable dlab
    MOV dx, COM1_PORT + 3
    MOV al, 0x80
    OUT dx, al

    ; define speed 115200
    MOV dx, COM1_PORT + 0
    MOV al, 0x01
    OUT dx, al
    MOV dx, COM1_PORT + 1
    MOV al, 0x00
    OUT dx, al

    ; LCR
    MOV dx, COM1_PORT + 3
    MOV al, 0x03
    OUT dx, al

    ; FIFO
    MOV dx, COM1_PORT + 2
    MOV al, 0x03
    OUT dx, al

    ; MCR
    MOV dx, COM1_PORT + 4
    MOV al, 0x08
    OUT dx, al

    RET

.section .note.GNU-stack,"",@progbits

