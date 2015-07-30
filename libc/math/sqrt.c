#include "math.h"

double sqrt(double x)
{
    return __builtin_sqrt(x);
}

float sqrtf(float x)
{
    return __builtin_sqrtf(x);
}

long double sqrtl(long double x)
{
    return __builtin_sqrtl(x);
}
