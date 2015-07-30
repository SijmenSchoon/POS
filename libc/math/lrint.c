#include "math.h"

long int lrint(double x)
{
    return __builtin_lrint(x);
}

long int lrintf(float x)
{
    return __builtin_lrintf(x);
}

long int lrintl(long double x)
{
    return __builtin_lrintl(x);
}
