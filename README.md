
## License
This project is protected under the **MIT License**. 
See the [LICENSE](LICENSE) file for more details.

[![Build
Kernel](https://github.com/icarotelesdasilva/kernel/actions/workflows/build.yml/badge.svg)](https://github.com/icarotelesdasilva/kernel/actions/workflows/build.yml)

Welcome to my kernel project; this is where I publish changes to my kernel. Here is the current project structure:
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

 how to compile: ```make clean && make all```

If you want to start the ISO: ```make run```

Start in QEMU and generate logs: ```make dev```

# REQUIREMENTS:

Have a Linux system—or at least GCC and NASM installed—on any virtual machine, such as QEMU or VirtualBox.
 
