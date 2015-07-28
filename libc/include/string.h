#ifndef LIBC_STRING_H
#define LIBC_STRING_H

#include <sys/cdefs.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

int memcmp(const void *s1, const void *s2, size_t n);
void *memcpy(void *restrict dst, void *restrict src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
size_t strlen(const char *s);

#ifdef __cplusplus
}
#endif

#endif
