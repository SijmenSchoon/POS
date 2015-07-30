#include "math.h"

double fmin(double x, double y)
{
    return __builtin_fmin(x, y);
}

float fminf(float x, float y)
{
    return __builtin_fminf(x, y);
}

long double fminl(long double x, long double y)
{
    return __builtin_fminl(x, y);
}
