/* The bootloader will look at this image and start execution at the symbol
   designated as the entry point. */
ENTRY(start)

/* Tell where the various sections of the object files will be put in the final
   kernel image. */
SECTIONS
{
	. = 1M;
	.bootstrap_text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.bootstrap_text)
	}

    . = 0xc0100000;
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.text)
    }

	/* Read-only data. */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* Read-write data (initialized) */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Read-write data (uninitialized) and stack */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
		*(.bootstrap_stack)
	}

	/* The compiler may produce other sections, by default it will put them in
	   a segment with the same name. Simply add stuff here as needed. */
}
