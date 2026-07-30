
; Copyright 2026 Icaro Teles da Silva Ribeiro @icarotelesdasilva

; Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

; The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

; THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


.global _start
.section .iram0.text
.align 4

_start:
    MOVI    a4, 0x3FF4808C
    MOVI    a5, 0
    s32i    a5, a4, 0

icaro:

MOVI a2, 0x60000000

    MOVI    a4, 0x3FF5F064
    MOVI    a5, 0x50D83AA1
    s32i    a5, a4, 0

    MOVI    a4, 0x3FF5F048
    MOVI    a5, 0
    s32i    a5, a4, 0

    MOVI    a2, 0x3FF40000   
    MOVI    a3, 0x41        

print_loop:
    s32i    a3, a2, 0

    MOVI    a6, 2000000
delay:
    addi.n    a6, a6, -1
    bnez    a6, delay

    j       print_loop

    .literal_position
