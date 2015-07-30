#include "math.h"

double copysign(double x, double y)
{
    return __builtin_copysign(x, y);
}

float copysignf(float x, float y)
{
    return __builtin_copysignf(x, y);
}

long double copysignl(long double x, long double y)
{
    return __builtin_copysignl(x, y);
}
