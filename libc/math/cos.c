#include "math.h"

double cos(double x)
{
    return __builtin_cos(x);
}

float cosf(float x)
{
    return __builtin_cosf(x);
}

long double cosl(long double x)
{
    return __builtin_cosl(x);
}
