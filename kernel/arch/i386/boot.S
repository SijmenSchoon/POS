# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
multiboot:
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .bootstrap_text
boot_page_dir:
.long 0x00000083			# Entry 0
.fill 767, 4, 0
.long 0x00000083			# Entry 767
.fill 255, 4, 0

.global start
.type start, @function
start:
	mov $boot_page_dir, %ecx
	mov %ecx, %cr3

	mov %cr4, %ecx
	or $0x00000010, %ecx
	mov %ecx,%cr4

	mov %cr0, %ecx
	or $0x80000000, %ecx
	mov %ecx, %cr0

	push $higher_half
	ret

.section .text:
higher_half:
	movl $stack_top, %esp

	# Initialize the core kernel before running the global constructors.
	call kernel_early

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
.Lhang:
	hlt
	jmp .Lhang
#.size start, . - start
