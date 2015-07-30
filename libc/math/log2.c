#include "math.h"

double log2(double x)
{
    return __builtin_log2(x);
}

float log2f(float x)
{
    return __builtin_log2f(x);
}

long double log2l(long double x)
{
    return __builtin_log2l(x);
}
