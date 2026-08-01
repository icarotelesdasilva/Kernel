global gdt_flush
gdt_flush:
MOV eax, [esp + 4]
lgdt [eax]
MOV ax, 0x10
    MOV ds, ax
    MOV es, ax
    MOV fs, ax
    MOV gs, ax
    MOV ss, ax

    jmp 0x08:.reload_cs

    .reload_cs:
    RET
    
