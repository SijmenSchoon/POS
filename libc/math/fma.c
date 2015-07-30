#include "math.h"

double fma(double x, double y, double z)
{
    return __builtin_fma(x, y, z);
}

float fmaf(float x, float y, float z)
{
    return __builtin_fmaf(x, y, z);
}

long double fmal(long double x, long double y, long double z)
{
    return __builtin_fmal(x, y, z);
}
