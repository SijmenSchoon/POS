#include <string.h>

void *memmove(void *dst, const void *src, size_t n)
{
    unsigned char *dstchar = (unsigned char *)dst;
    const unsigned char *srcchar = (const unsigned char *)src;

    if (dstchar < srcchar)
    {
        for (size_t i = 0; i < n; i++)
        {
            dstchar[i] = srcchar[i];
        }
    }
    else
    {
        for (size_t i = n; i != 0; i--)
        {
            dstchar[i - 1] = srcchar[i - 1];
        }
    }

    return dst;
}
