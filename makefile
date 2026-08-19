# Kernel-Ícaro (vmicaro)
# Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)

.PHONY: all run dev clean

ASM = nasm
CC = gcc
LD = ld -m elf_i386
GRUB_DIR = $(CURDIR)/tools
GRUB_MKRESCUE = $(GRUB_DIR)/bin/grub-mkrescue
GRUB_MODULES = $(GRUB_DIR)/lib/grub/i386-pc
CONVERT = convert
CFLAGS = -m32 -ffreestanding -nostdlib -fno-pic -Iinclude

OBJ=arch/i386/boot/boot.o \
    arch/i386/cpu/gdt.o \
    arch/i386/cpu/gdt_flush.o \
    arch/i386/cpu/idt.o \
    arch/i386/cpu/idt_load.o \
    arch/i386/drivers/kernel_panic.o \
    arch/i386/drivers/serial.o \
    arch/i386/drivers/serial_print.o \
    arch/i386/drivers/vga.o \
    arch/i386/kernel/handlers/handler_0x00.o \
    arch/i386/kernel/handlers/handler_irq0.o \
    arch/i386/kernel/handlers/handler_0x08.o \
    arch/i386/kernel/handlers/keyboard_handler.o \
    arch/i386/kernel/handlers/handler_central.o \
    arch/i386/kernel/handlers/mouse-irq12.o \
    arch/i386/drivers/mouse.o \
    arch/i386/interrupts/pic.o \
    arch/i386/kernel/kernel.o \
    arch/i386/kernel/memory/memory.o \
    arch/i386/kernel/pmm/pmm.o \
    arch/i386/kernel/vmm/vmm.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(ASM) -f elf32 $< -o $@

%.o: %.s
	$(ASM) -f elf32 $< -o $@

arch/i386/cpu/idt_load.o: arch/i386/cpu/idt.asm
	$(ASM) -f elf32 $< -o $@

arch/i386/kernel/handlers/interrupt_asm.o: arch/i386/kernel/handlers/interrupt.asm
	$(ASM) -f elf32 $< -o $@

vmicaro: $(OBJ)
	$(LD) -T arch/i386/linker.ld $(OBJ) -o vmicaro

vmicaro.iso: vmicaro
	mkdir -p isodir/boot/grub
	cp vmicaro isodir/boot/vmicaro
	cp grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o vmicaro.iso isodir/

all: vmicaro.iso

clean:
	rm -f $(OBJ) vmicaro vmicaro.iso
	rm -rf isodir/

dev: vmicaro.iso
	qemu-system-x86_64 \
		-cdrom vmicaro.iso \
		-d int,cpu_reset,guest_errors \
		-D logs_completos.txt \
		-no-reboot -no-shutdown

run: vmicaro.iso
	qemu-system-x86_64 -cdrom vmicaro.iso