#include "math.h"

double nan(const char *tagp)
{
    return __builtin_nan(tagp);
}

float nanf(const char *tagp)
{
    return __builtin_nanf(tagp);
}

long double nanl(const char *tagp)
{
    return __builtin_nanl(tagp);
}
