#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *a = (const unsigned char *)s1;
    const unsigned char *b = (const unsigned char *)s2;

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i] ? -1 : 1;
        }
    }

    return 0;
}
