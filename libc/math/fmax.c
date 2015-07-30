#include "math.h"

double fmax(double x, double y)
{
    return __builtin_fmax(x, y);
}

float fmaxf(float x, float y)
{
    return __builtin_fmaxf(x, y);
}

long double fmaxl(long double x, long double y)
{
    return __builtin_fmaxl(x, y);
}
