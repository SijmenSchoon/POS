#include <stdio.h>

#if defined(__is_pos_kernel)
#include <kernel/tty.h>
#endif

int putchar(int i)
{
#if defined(__is_pos_kernel)
    terminal_put_char(i);
#else
    // TODO Implement write syscall
#endif
    return i;
}
