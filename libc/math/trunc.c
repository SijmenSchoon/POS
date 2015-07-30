#include "math.h"

double trunc(double x)
{
    return __builtin_trunc(x);
}

float truncf(float x)
{
    return __builtin_truncf(x);
}

long double truncl(long double x)
{
    return __builtin_truncl(x);
}
