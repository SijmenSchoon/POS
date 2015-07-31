#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <kernel/tty.h>

void kernel_early()
{
    terminal_initialize();
}

void kernel_main()
{
    volatile int variable = 0;
    printf("%cello %s%c\n", toupper('h'), "world", '!');
    printf("addr: %x\n", (unsigned int)&variable);
    printf("Test\n");
}
