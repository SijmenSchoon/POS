#include "math.h"

double fmod(double x, double y)
{
    return __builtin_fmod(x, y);
}

float fmodf(float x, float y)
{
    return __builtin_fmodf(x, y);
}

long double fmodl(long double x, long double y)
{
    return __builtin_fmodl(x, y);
}
