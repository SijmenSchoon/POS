#include "math.h"

double atan(double x)
{
    return __builtin_atan(x);
}

float atanf(float x)
{
    return __builtin_atanf(x);
}

long double atanl(long double x)
{
    return __builtin_atanl(x);
}
