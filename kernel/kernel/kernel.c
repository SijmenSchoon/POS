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
    printf("%cello %s%c\n", toupper('h'), "world", '!');
    printf("%x\n", 0xdeadbeef);

}
