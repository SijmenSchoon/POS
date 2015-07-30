#include "math.h"

double nearbyint(double x)
{
    return __builtin_nearbyint(x);
}

float nearbyintf(float x)
{
    return __builtin_nearbyintf(x);
}

long double nearbyintl(long double x)
{
    return __builtin_nearbyintl(x);
}
