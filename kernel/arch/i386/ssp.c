#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// TODO Fully randomize this
#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0x4e365603
#else
#define STACK_CHK_GUARD 0xefac6b44b3215446
#endif

uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

__attribute__((__noreturn__)) void __stack_chk_fail(void)
{
    printf("Stack overflow!\n");
    abort();
}
