#include "math.h"

double nexttoward(double x, long double y)
{
    return __builtin_nexttoward(x, y);
}

float nexttowardf(float x, long double y)
{
    return __builtin_nexttowardf(x, y);
}

long double nexttowardl(long double x, long double y)
{
    return __builtin_nexttowardl(x, y);
}
