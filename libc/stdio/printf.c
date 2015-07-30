#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static size_t print(const char *data, size_t l)
{
    const unsigned char *d = (const unsigned char *)data;
    for (size_t i = 0; i < l; i++)
    {
        putchar((int)d[i]);
    }
    return l;
}

static char *itoa(int i, char *b, const char *digits)
{
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

    int shifter = i;
    do
    {
        p++;
        shifter /= strlen(digits);
    } while (shifter != 0);

    *p = '\0';
    do
    {
        *--p = digits[i%strlen(digits)];
        i /= strlen(digits);
    } while (i);

    return b;
}

static char *utoa(unsigned int i, char *b, const char *digits)
{
    char *p = b;

    int shifter = i;
    do
    {
        p++;
        shifter /= strlen(digits);
    } while (shifter != 0);

    *p = '\0';
    do
    {
        *--p = digits[i%strlen(digits)];
        i /= strlen(digits);
    } while (i);

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
