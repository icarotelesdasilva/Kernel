global syscall_handler
extern handler_syscall 
syscall_handler:

pushad
 push ds
 push es
 push fs
 push gs

 mov ax, 0x10
 mov ds, ax
 mov es, ax
 mov fs, ax
 mov gs, ax

push esp
call handler_syscall
add esp, 4

  pop gs
  pop fs
  pop es
  pop ds 
  popad
  iret