#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static size_t print(const char *data, size_t l)
{
    const unsigned char *d = (const unsigned char *)data;
    for (size_t i = 0; i < l; i++)
    {
        putchar((int)d[i]);
    }
    return l;
}

int printf(const char *restrict format, ...)
{
    va_list parameters;
    va_start(parameters, format);

    int written = 0;
    bool rejected_bad_specifier = false;
    bool escaped = false;

    while (*format)
    {
        const char *format_start = format;

        if (*format != '%' || escaped)
        {
            escaped = false;
            putchar(*format++);
        }
        else if (rejected_bad_specifier)
        {
            format = format_start;
            escaped = true;
        }
        else
        {
            switch (*++format)
            {
            case '%':
                format++;
                escaped = true;
                break;

            case 'c':
                format++;
                putchar(va_arg(parameters, int));
                written++;
                break;

            case 's':
                format++;
                const char *s = va_arg(parameters, const char *);
                written += print(s, strlen(s));
                break;

            default:
                rejected_bad_specifier = true;
            }
        }
    }

    va_end(parameters);
    return written;
}
