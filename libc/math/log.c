#include "math.h"

double log(double x)
{
    return __builtin_log(x);
}

float logf(float x)
{
    return __builtin_logf(x);
}

long double logl(long double x)
{
    return __builtin_logl(x);
}
