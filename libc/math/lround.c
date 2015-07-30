#include "math.h"

long int lround(double x)
{
    return __builtin_lround(x);
}

long int lroundf(float x)
{
    return __builtin_lroundf(x);
}

long int lroundl(long double x)
{
    return __builtin_lroundl(x);
}
