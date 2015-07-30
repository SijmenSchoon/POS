#include "math.h"

double scalbn(double x, int exp)
{
    return __builtin_scalbn(x, exp);
}

float scalbnf(float x, int exp)
{
    return __builtin_scalbnf(x, exp);
}

long double scalbnl(long double x, int exp)
{
    return __builtin_scalbnl(x, exp);
}

double scalbln(double x, long int exp)
{
    return __builtin_scalbln(x, exp);
}

float scalblnf(float x, long int exp)
{
    return __builtin_scalblnf(x, exp);
}

long double scalblnl(long double x, long int exp)
{
    return __builtin_scalblnl(x, exp);
}
