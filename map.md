
├── arch

│   ├── i386

│   │   ├── boot

│   │   │   ├── boot.asm

│   │   │   ├── multiboot.c

│   │   │   └── multiboot.h

│   │   ├── cpu

│   │   │   ├── gdt.asm

│   │   │   ├── gdt.c

│   │   │   ├── gdt_flush.s

│   │   │   ├── handler-irq0.c

│   │   │   ├── handler_keyboard.c

handler-keyboard-isr.asm
│   │   │   ├── idt.asm

│   │   │   ├── idt.c

│   │   │   └── idt.h

│   │   ├── drivers


│   │   │   ├── kernel_panic.c
│   │   │   ├── serial.asm


│   │   │   ├── serial_print.c

│   │   │   └── vga.c

│   │   ├── interrupts

│   │   │   ├── interrupt.asm

│   │   │   ├── interrupt.c

│   │   │   ├── interrupt.h

│   │   │   ├── io.h

│   │   │   ├── pic.c

│   │   │   └── pic.h

│   │   ├── kernel

│   │   │   └── kernel.c

│   │   ├── linker.ld

│   │   └── pmm

│   │       ├── pmm.c

│   │       └── pmm.h

│   └── Xtensa

│       ├── linker.ld

│       ├── makefile

│       └── start.S

├── grub

│   └── grub.cfg

├── LICENSE

├── logs_completos.txt

├── makefile

├── map.md

└── README.md





