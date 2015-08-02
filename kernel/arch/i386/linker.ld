ENTRY(start)

phys = 0x00100000;
offset = 0xc0000000;
virt = offset + phys;
SECTIONS
{
    . = virt;

    .text ALIGN(0x1000) : AT(ADDR(.text) - offset)
    {
        *(.multiboot)
        *(.text)
        *(.rodata)

    }

    .data ALIGN(4K) : AT(ADDR(.data) - offset)
    {
        *(.data)
    }

    .bss ALIGN(4K) : AT(ADDR(.bss) - offset)
    {
        *(COMMON)
        *(.bss)
        *(.bootstrap_stack)
        . = ALIGN(0x1000);
        *(.pagedir)
        . += 1024;
    }
}
