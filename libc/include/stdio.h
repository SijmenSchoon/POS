#ifndef LIBC_STDIO_H
#define LIBC_STDIO_H

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C"
{
#endif

int printf(const char *restrict format, ...);
int putchar(int c);
int puts(const char *s);

#ifdef __cplusplus
}
#endif

#endif
