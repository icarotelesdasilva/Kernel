extern handler_0x08
global isr_double_fault
section .rodata
double_fault_str db "KERNEL PANIC: Double Fault (0x08)", 0
global keyboard_isr
extern keyboard_handler
global isr0
extern isr_handler
global irq0_isr
extern irq0_handler
extern current
extern next

irq0_isr:
    pusha
    push ds
    push es
    mov eax, [current]
    mov [eax + 4], esp
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    call irq0_handler
    mov eax, [next]
    mov esp, [eax + 4]
    pop es
    pop ds
    popa
    iret

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

isr_double_fault:
cli
add esp, 4
push double_fault_str 
call handler_0x08


.hang:
hlt
jmp .hang



isr0:
push byte 0         
push byte 0         
pusha               
mov ax, ds          
push eax
call isr_handler   
pop eax
popa                
add esp, 8          
iret