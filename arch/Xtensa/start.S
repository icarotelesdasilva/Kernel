.global _start
.section .iram0.text
.align 4

_start:
    MOVI    a4, 0x3FF4808C
    MOVI    a5, 0
    s32i    a5, a4, 0

icaro:

MOVI a2, 0x60000000

    MOVI    a4, 0x3FF5F064
    MOVI    a5, 0x50D83AA1
    s32i    a5, a4, 0

    MOVI    a4, 0x3FF5F048
    MOVI    a5, 0
    s32i    a5, a4, 0

    MOVI    a2, 0x3FF40000   
    MOVI    a3, 0x41        

print_loop:
    s32i    a3, a2, 0

    MOVI    a6, 2000000
delay:
    addi.n    a6, a6, -1
    bnez    a6, delay

    j       print_loop

    .literal_position
