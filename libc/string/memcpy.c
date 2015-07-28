#include <string.h>

void *memcpy(void *restrict dst, void *restrict src, size_t n)
{
    unsigned char *dstchar = (unsigned char *)dst;
    const unsigned char *srcchar = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++)
    {
        dstchar[i] = srcchar[i];
    }
    return dst;
}
