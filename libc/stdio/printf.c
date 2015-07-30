#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

static size_t print(const char *data, size_t l)
{
#ifdef __is_pos_kernel
    extern void terminal_write(const char *, size_t);
    terminal_write(data, l);
    return l;
#else
    for (size_t i = 0; i < l; i++)
    {
        putchar((int)data[i]);
    }
    return l;
#endif
}

static char *itoa(int i, char *b, const char *digits)
{
    int base = strlen(digits);
    char *p = b;

    if (i == INT_MIN)
    {
#define S(x) #x
#define S_(x) S(x)
        memcpy(b, S_(INT_MIN), strlen(S_(INT_MIN)) - 1);
        return b;
    }

    if (i < 0)
    {
        *p++ = '-';
        i = -i;
    }

    int tmp = i;
    do
    {
        p++;
    } while (tmp /= base);

    *p = '\0';
    do
    {
        *--p = digits[i%base];
    } while (i /= base);

    return b;
}

static char *utoa(unsigned int i, char *b, const char *digits)
{
    int base = strlen(digits);
    char *p = b;

    int tmp = i;
    do
    {
        p++;
    } while (tmp /= base);

    *p = '\0';
    do
    {
        *--p = digits[i%base];
    } while (i /= base);

    return b;
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

            case 'd':
                format++;
                char d[128];
                itoa(va_arg(parameters, int), d, "0123456789");
                written += print(d, strlen(d));
                break;

            case 's':
                format++;
                const char *s = va_arg(parameters, const char *);
                written += print(s, strlen(s));
                break;

            case 'x':
                format++;
                char x[128];
                utoa(va_arg(parameters, int), x, "0123456789abcdef");
                written += print(x, strlen(x));
                break;

            default:
                rejected_bad_specifier = true;
            }
        }
    }

    va_end(parameters);
    return written;
}
