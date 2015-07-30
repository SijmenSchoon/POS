#include "math.h"

double log10(double x)
{
    return __builtin_log10(x);
}

float log10f(float x)
{
    return __builtin_log10f(x);
}

long double log10l(long double x)
{
    return __builtin_log10l(x);
}
