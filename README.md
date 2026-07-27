# Hobby Kernel

A hobby operating system kernel built entirely from scratch by hand. Originally targeted for i386 architecture, it now features initial minimal support for Xtensa. Check out the [map.md](map.md) file for a complete overview of the project's structure.

[![Build Kernel](https://github.com/icarotelesdasilva/kernel/actions/workflows/build.yml/badge.svg)](https://github.com/icarotelesdasilva/kernel/actions/workflows/build.yml)



## Compilation & Execution

* **How to compile:** 
  ```bash
  make clean && make all
 ```bash
Start the ISO:
 
make run

Run in QEMU & generate logs:

make dev```


## Requirements
A Linux-based system (or a virtual machine running Linux) with the following tools installed:
 GCC (GNU Compiler Collection)
 NASM (Netwide Assembler)
 QEMU & Make

## License
This project is protected under the MIT License. See the LICENSE file for more details.

