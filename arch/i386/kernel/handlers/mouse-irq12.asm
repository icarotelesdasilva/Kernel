[bits 32]
global irq12_stub
extern ps2_mouse_handle_interrupt

irq12_stub:
    pusha                      

    push dword 600              
    push dword 800              
    call ps2_mouse_handle_interrupt
    add esp, 8                  

    mov al, 0x20
    out 0xA0, al
    out 0x20, al

    popa                       
    iret                   