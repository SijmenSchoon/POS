// Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             // align loaded modules on page boundaries
.set MEMINFO,  1<<1             // provide memory map
.set FLAGS,    ALIGN | MEMINFO  // this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       // 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) // checksum of above, to prove we are multiboot

// Declare a header as in the Multiboot Standard.
.section .multiboot
multiboot:
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

// Reserve a stack for the initial thread.
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 // 16 KiB
stack_top:

.section .pagedir
boot_page_dir:

// The kernel entry point.
.section .text
.global start
start:
	// Create a boot page dir
	// Fill with 0x00000002s
	mov $1024, %ecx
	mov (boot_page_dir - 0xc0000000), %edx
.loop:
	movl $0x00000002, (%edx)
	add $4, %edx
	loop .loop
	// Define two pages
	movl $0x00000083, (boot_page_dir - 0xc0000000)
	movl $0x00000083, (boot_page_dir - 0xc0000000) + 768*4

	mov $(boot_page_dir - 0xc0000000), %ecx
	mov %ecx, %cr3

	mov %cr4, %ecx
	or $0x00000010, %ecx
	mov %ecx, %cr4

	mov %cr0, %ecx
	or $0x80000000, %ecx
	mov %ecx, %cr0

	lea higher_half, %ecx
	jmp *%ecx

higher_half:
	// Get rid of the first page, we don't need it anymore
	movl $0x00000002, boot_page_dir
	invlpg 0

	// Initialize the stack
	movl $stack_top, %esp

	// Initialize the core kernel before running the global constructors.
	call kernel_early

	// Call the global constructors.
	call _init

	// Transfer control to the main kernel.
	call kernel_main

	// Hang if kernel_main unexpectedly returns.
	cli
.Lhang:
	hlt
	jmp .Lhang
//.size start, . - start
