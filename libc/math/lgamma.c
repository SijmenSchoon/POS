#include "math.h"

double lgamma(double x)
{
    return __builtin_lgamma(x);
}

float lgammaf(float x)
{
    return __builtin_lgammaf(x);
}

long double lgammal(long double x)
{
    return __builtin_lgammal(x);
}
