#include "math.h"

double remainder(double x, double y)
{
    return __builtin_remainder(x, y);
}

float remainderf(float x, float y)
{
    return __builtin_remainderf(x, y);
}

long double remainderl(long double x, long double y)
{
    return __builtin_remainderl(x, y);
}
