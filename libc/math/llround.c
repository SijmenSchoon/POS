#include "math.h"

long long int llround(double x)
{
    return __builtin_llround(x);
}

long long int llroundf(float x)
{
    return __builtin_llroundf(x);
}

long long int llroundl(long double x)
{
    return __builtin_llroundl(x);
}
