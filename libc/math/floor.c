#include "math.h"

double floor(double x)
{
    return __builtin_floor(x);
}

float floorf(float x)
{
    return __builtin_floorf(x);
}

long double floorl(long double x)
{
    return __builtin_floorl(x);
}
