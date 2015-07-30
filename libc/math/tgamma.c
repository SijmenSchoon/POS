#include "math.h"

double tgamma(double x)
{
    return __builtin_tgamma(x);
}

float tgammaf(float x)
{
    return __builtin_tgammaf(x);
}

long double tgammal(long double x)
{
    return __builtin_tgammal(x);
}
