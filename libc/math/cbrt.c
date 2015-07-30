#include "math.h"

double cbrt(double x)
{
    return __builtin_cbrt(x);
}

float cbrtf(float x)
{
    return __builtin_cbrtf(x);
}

long double cbrtl(long double x)
{
    return __builtin_cbrtl(x);
}
