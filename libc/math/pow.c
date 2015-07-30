#include "math.h"

double pow(double x, double y)
{
    return __builtin_pow(x, y);
}

float powf(float x, float y)
{
    return __builtin_powf(x, y);
}

long double powl(long double x, long double y)
{
    return __builtin_powl(x, y);
}
