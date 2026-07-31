CROSS_COMPILE ?= xtensa-esp32-elf-
CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)ld

SRCS   := start.S
OBJS   := start.o
LINKER := linker.ld
TARGET := vmicaro_xtensa.elf

CFLAGS  := -ffreestanding -O0 -Wall -nostdlib
LDFLAGS := -T $(LINKER) -nostdlib

.PHONY: all clean

all: $(TARGET)

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f *.o $(TARGET)
