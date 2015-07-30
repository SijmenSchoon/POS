#include "math.h"

double erf(double x)
{
    return __builtin_erf(x);
}

float erff(float x)
{
    return __builtin_erff(x);
}

long double erfl(long double x)
{
    return __builtin_erfl(x);
}
