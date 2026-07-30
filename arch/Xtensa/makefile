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

# Copyright 2026 Icaro Teles da Silva Ribeiro @icarotelesdasilva

# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
