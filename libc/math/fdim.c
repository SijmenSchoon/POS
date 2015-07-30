#include "math.h"

double fdim(double x, double y)
{
    return __builtin_fdim(x, y);
}

float fdimf(float x, float y)
{
    return __builtin_fdimf(x, y);
}

long double fdiml(long double x, long double y)
{
    return __builtin_fdiml(x, y);
}
