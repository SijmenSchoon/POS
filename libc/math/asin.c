#include "math.h"

double asin(double x)
{
    return __builtin_asin(x);
}

float asinf(float x)
{
    return __builtin_asinf(x);
}

long double asinl(long double x)
{
    return __builtin_asinl(x);
}
