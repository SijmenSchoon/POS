#include "math.h"

double log1p(double x)
{
    return __builtin_log1p(x);
}

float log1pf(float x)
{
    return __builtin_log1pf(x);
}

long double log1pl(long double x)
{
    return __builtin_log1pl(x);
}
