
## License
This project is protected under the **MIT License**. 
See the [LICENSE](LICENSE) file for more details.

[![Build
Kernel](https://github.com/icarotelesdasilva/kernel/actions/workflows/build.yml/badge.svg)](https://github.com/icarotelesdasilva/kernel/actions/workflows/build.yml)

Welcome to my hobby kernel, a place where this repository works liberally, that is, everything that is here works is being updated constantly, where
Visit my website using Replit! [hobby-kernel-hub](https://hobby-kernel-hub--kalilinuxicr.replit.app)
I put my skills into practice, current structure of the project:

```
├
── arch

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

│   │   │   └── interrupt.h

│   │   ├── kernel

│   │   │   └── kernel.c

│   │   ├── linker.ld

│   │   └── mm

│   └── Xtensa

│       ├── linker.ld

│       ├── makefile

│       └── start.S

├── grub

│   └── grub.cfg

├── include

├── LICENSE

├── makefile

├── map.md

└── README.md
```

 
 
