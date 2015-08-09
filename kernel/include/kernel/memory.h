#ifndef KERNEL_MEMORY
#define KERNEL_MEMORY

#include <stdint.h>

#define PAGE_GLOBAL         0b100000000

// Stores the page size for the entry. For PAGE_SIZE_4M, PSE has to be enabled.
#define PAGE_SIZE_4K        0b00000000
#define PAGE_SIZE_4M        0b10000000

// Set by the CPU when a page was written to. Must be cleared by the OS.
#define PAGE_DIRTY          0b01000000

// Used to discover whether a page has been accessed. The bit will only be set
// by the CPU, and it's up to the OS to clear it.
#define PAGE_ACCESSED       0b00100000

// Disables caching for that page
#define PAGE_CACHE_DISABLED 0b00010000

// Enables/disables write-through abilities of the page
#define PAGE_WRITE_THROUGH  0b00001000
#define PAGE_WRITE_BACK     0b00000000

#define PAGE_PRIV_USER      0b00000100
#define PAGE_PRIV_SUPERUSER 0b00000000

#define PAGE_READ_WRITE     0b00000010
#define PAGE_READ_ONLY      0b00000000

#define PAGE_PRESENT        0b00000001

#endif
