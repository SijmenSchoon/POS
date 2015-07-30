#include "math.h"

double rint(double x)
{
    return __builtin_rint(x);
}

float rintf(float x)
{
    return __builtin_rintf(x);
}

long double rintl(long double x)
{
    return __builtin_rintl(x);
}
