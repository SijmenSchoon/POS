#include "math.h"

double nextafter(double x, double y)
{
    return __builtin_nextafter(x, y);
}

float nextafterf(float x, float y)
{
    return __builtin_nextafterf(x, y);
}

long double nextafterl(long double x, long double y)
{
    return __builtin_nextafterl(x, y);
}
