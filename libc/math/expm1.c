#include "math.h"

double expm1(double x)
{
    return __builtin_expm1(x);
}

float expm1f(float x)
{
    return __builtin_expm1f(x);
}

long double expm1l(long double x)
{
    return __builtin_expm1l(x);
}
