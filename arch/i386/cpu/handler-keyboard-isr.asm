global keyboard_isr
extern keyboard_handler
section .text

keyboard_isr:
PUSHAD
CALL keyboard_handler
POPA
IRET