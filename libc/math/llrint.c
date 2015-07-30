#include "math.h"

long long int llrint(double x)
{
    return __builtin_llrint(x);
}

long long int llrintf(float x)
{
    return __builtin_llrintf(x);
}

long long int llrintl(long double x)
{
    return __builtin_llrintl(x);
}
