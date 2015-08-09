#include <stdio.h>
#include <stdlib.h>
#include <panic.h>

__attribute__((__noreturn__)) void abort()
{
    // TODO Add proper kernel panic
    panic("abort()");
    while (1);
    __builtin_unreachable();
}
