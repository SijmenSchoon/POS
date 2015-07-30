#include "math.h"

double exp2(double x)
{
    return __builtin_exp2(x);
}

float exp2f(float x)
{
    return __builtin_exp2f(x);
}

long double exp2l(long double x)
{
    return __builtin_exp2l(x);
}
