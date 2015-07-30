#include "math.h"

double remquo(double x, double y, int *quo)
{
    return __builtin_remquo(x, y, quo);
}

float remquof(float x, float y, int *quo)
{
    return __builtin_remquof(x, y, quo);
}

long double remquol(long double x, long double y, int *quo)
{
    return __builtin_remquol(x, y, quo);
}
