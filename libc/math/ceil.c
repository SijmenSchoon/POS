#include "math.h"

double ceil(double x)
{
    return __builtin_ceil(x);
}

float ceilf(float x)
{
    return __builtin_ceilf(x);
}

long double ceill(long double x)
{
    return __builtin_ceill(x);
}
