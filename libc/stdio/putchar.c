#include <stdio.h>

#if defined(__is_pos_kernel)
#include <kernel/tty.h>
#endif

int putchar(int i)
{
#if defined(__is_pos_kernel)
    char c = (char)i;
    terminal_write(&c, sizeof(c));
#else
    // TODO Implement write syscall
#endif
    return i;
}
