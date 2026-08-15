extern handler-0x08
global isr_double_fault

section .rodata
double_fault_str db "KERNEL PANIC: Double Fault (0x08)", 0

    push double_fault_str 
     call handler-0x08

     .hang:
    hlt
    jmp .hang
