#include "math.h"

double logb(double x)
{
    return __builtin_logb(x);
}

float logbf(float x)
{
    return __builtin_logbf(x);
}

long double logbl(long double x)
{
    return __builtin_logbl(x);
}
