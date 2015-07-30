#include "math.h"

double fabs(double x)
{
    return __builtin_fabs(x);
}

float fabsf(float x)
{
    return __builtin_fabsf(x);
}

long double fabsl(long double x)
{
    return __builtin_fabsl(x);
}
