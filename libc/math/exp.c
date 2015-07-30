#include "math.h"

double exp(double x)
{
    return __builtin_exp(x);
}

float expf(float x)
{
    return __builtin_expf(x);
}

long double expl(long double x)
{
    return __builtin_expl(x);
}
