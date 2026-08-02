; interrupts.asm
[bits 32]

global isr0
extern isr_handler

section .text

%macro ISR_NOERRCODE 1
  global isr%1
  isr%1:
    CLI          
    PUSH dword 0 
    PUSH dword %1
    JMP isr_common_stub
%endmacro

ISR_NOERRCODE 0

isr_common_stub:
    PUSHA        

    MOV ax, ds          
    PUSH eax

    MOV ax, 0x10        
    MOV ds, ax
    MOV es, ax
    MOV fs, ax
    MOV gs, ax

    CALL isr_handler    

    POP eax             
    MOV ds, ax
    MOV es, ax
    MOV fs, ax
    MOV gs, ax

    POPA                
    add esp, 8          
    STI  
IRET

section .note.GNU-stack noalloc noexec nowrite progbits
