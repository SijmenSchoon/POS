#include "math.h"

double tanh(double x)
{
    return __builtin_tanh(x);
}

float tanhf(float x)
{
    return __builtin_tanhf(x);
}

long double tanhl(long double x)
{
    return __builtin_tanhl(x);
}
