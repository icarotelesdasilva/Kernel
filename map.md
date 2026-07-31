.

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

│   │   │   ├── idt.asm

│   │   │   ├── idt.c

│   │   │   └── idt.h

│   │   ├── drivers

│   │   │   ├── kernel_panic.c

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

├── makefile

├── map.md

└── README.md

11 directories, 29 files
