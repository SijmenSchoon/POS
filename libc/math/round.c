#include "math.h"

double round(double x)
{
    return __builtin_round(x);
}

float roundf(float x)
{
    return __builtin_roundf(x);
}

long double roundl(long double x)
{
    return __builtin_roundl(x);
}
