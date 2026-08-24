```⁠
loumain
============

A hobby operating system kernel built entirely from scratch by hand. 
Originally targeted for i386 architecture, it now features initial 
minimal support for Xtensa.

Quick Start
-----------

* How to compile: make clean && make all
* Start the ISO: make run
* Run in QEMU & generate logs: make dev



Features 
--------

Interrupt management, dynamic memory management, paging among many other things (It wouldn't fit here).



Segurity
--------
The loumain is frequently tested on actual hardware and in emulators before being released; issues are diagnosed, and everything undergoes multiple rounds of testing.


Requirements
------------

A Linux-based system (or a virtual machine running Linux) with:
* GCC (GNU Compiler Collection)
* NASM (Netwide Assembler)
* QEMU & Make

License
-------

This project is protected by the MIT License.

