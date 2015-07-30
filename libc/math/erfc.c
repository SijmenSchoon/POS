#include "math.h"

double erfc(double x)
{
    return __builtin_erfc(x);
}

float erfcf(float x)
{
    return __builtin_erfcf(x);
}

long double erfcl(long double x)
{
    return __builtin_erfcl(x);
}
