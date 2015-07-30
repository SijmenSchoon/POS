#include "math.h"

int ilogb(double x)
{
    return __builtin_ilogb(x);
}

int ilogbf(float x)
{
    return __builtin_ilogbf(x);
}

int ilogbl(long double x)
{
    return __builtin_ilogbl(x);
}
