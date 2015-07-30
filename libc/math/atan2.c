#include "math.h"

double atan2(double x, double y)
{
    return __builtin_atan2(x, y);
}

float atan2f(float x, float y)
{
    return __builtin_atan2f(x, y);
}

long double atan2l(long double x, long double y)
{
    return __builtin_atan2l(x, y);
}
