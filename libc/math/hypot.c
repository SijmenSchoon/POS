#include "math.h"

double hypot(double x, double y)
{
    return __builtin_hypot(x, y);
}

float hypotf(float x, float y)
{
    return __builtin_hypotf(x, y);
}

long double hypotl(long double x, long double y)
{
    return __builtin_hypotl(x, y);
}
