#ifndef LIBC_MATH_H
#define LIBC_MATH_H

// acos.c
double acos(double x);
float acosf(float x);
long double acosl(long double x);

// asin.c
double asin(double x);
float asinf(float x);
long double asinl(long double x);

// atan.c
double atan(double x);
float atanf(float x);
long double atanl(long double x);

// atan2.c
double atan2(double y, double x);
float atan2f(float y, float x);
long double atan2l(long double y, long double x);

// cos.c
double cos(double x);
float cosf(float x);
long double cosl(long double x);

// sin.c
double sin(double x);
float sinf(float x);
long double sinl(long double x);

// tan.c
double tan(double x);
float tanf(float x);
long double tanl(long double x);

// acosh.c
double acosh(double x);
float acoshf(float x);
long double acoshl(long double x);

// asinh.c
double asinh(double x);
float asinhf(float x);
long double asinhl(long double x);

// atanh.c
double atanh(double x);
float atanhf(float x);
long double atanhl(long double x);

// cosh.c
double cosh(double x);
float coshf(float x);
long double coshl(long double x);

// sinh.c
double sinh(double x);
float sinhf(float x);
long double sinhl(long double x);

// tanh.c
double tanh(double x);
float tanhf(float x);
long double tanhl(long double x);

// exp.c
double exp(double x);
float expf(float x);
long double expl(long double x);

// exp2.c
double exp2(double x);
float exp2f(float x);
long double exp2l(long double x);

// expm1.c
double expm1(double x);
float expm1f(float x);
long double expm1l(long double x);

// frexp.c
double frexp(double value, int *exp);
float frexpf(float value, int *exp);
long double frexpl(long double value, int *exp);

// ilogb.c
int ilogb(double x);
int ilogbf(float x);
int ilogbl(long double x);

// ldexp.c
double ldexp(double x, int exp);
float ldexpf(float x, int exp);
long double ldexpl(long double x, int exp);

// log.c
double log(double x);
float logf(float x);
long double logl(long double x);

// log10.c
double log10(double x);
float log10f(float x);
long double log10l(long double x);

// log1p.c
double log1p(double x);
float log1pf(float x);
long double log1pl(long double x);

// log2.c
double log2(double x);
float log2f(float x);
long double log2l(long double x);

// logb.c
double logb(double x);
float logbf(float x);
long double logbl(long double x);

// modf.c
double modf(double value, double *iptr);
float modff(float value, float *iptr);
long double modfl(long double value, long double *iptr);

// scalbn.c
double scalbn(double x, int n);
float scalbnf(float x, int n);
long double scalbnl(long double x, int n);
double scalbln(double x, long int n);
float scalblnf(float x, long int n);
long double scalblnl(long double x, long int n);

// cbrt.c
double cbrt(double x);
float cbrtf(float x);
long double cbrtl(long double x);

// fabs.c
double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);

// hypot.c
double hypot(double x, double y);
float hypotf(float x, float y);
long double hypotl(long double x, long double y);

// pow.c
double pow(double x, double y);
float powf(float x, float y);
long double powl(long double x, long double y);

// sqrt.c
double sqrt(double x);
float sqrtf(float x);
long double sqrtl(long double x);

// erf.c
double erf(double x);
float erff(float x);
long double erfl(long double x);

// erfc.c
double erfc(double x);
float erfcf(float x);
long double erfcl(long double x);

// lgamma.c
double lgamma(double x);
float lgammaf(float x);
long double lgammal(long double x);

// tgamma.c
double tgamma(double x);
float tgammaf(float x);
long double tgammal(long double x);

// ceil.c
double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

// floor.c
double floor(double x);
float floorf(float x);
long double floorl(long double x);

// nearbyint.c
double nearbyint(double x);
float nearbyintf(float x);
long double nearbyintl(long double x);

// rint.c
double rint(double x);
float rintf(float x);
long double rintl(long double x);

// lrint.c
long int lrint(double x);
long int lrintf(float x);
long int lrintl(long double x);

// llrint.c
long long int llrint(double x);
long long int llrintf(float x);
long long int llrintl(long double x);

// round.c
double round(double x);
float roundf(float x);
long double roundl(long double x);

// lround.c
long int lround(double x);
long int lroundf(float x);
long int lroundl(long double x);

// llround.c
long long int llround(double x);
long long int llroundf(float x);
long long int llroundl(long double x);

// trunc.c
double trunc(double x);
float truncf(float x);
long double truncl(long double x);

// fmod.c
double fmod(double x, double y);
float fmodf(float x, float y);
long double fmodl(long double x, long double y);

// remainder.c
double remainder(double x, double y);
float remainderf(float x, float y);
long double remainderl(long double x, long double y);

// remquo.c
double remquo(double x, double y, int *quo);
float remquof(float x, float y, int *quo);
long double remquol(long double x, long double y, int *quo);

// copysign.c
double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);

// nan.c
double nan(const char *tagp);
float nanf(const char *tagp);
long double nanl(const char *tagp);

// nextafter.c
double nextafter(double x, double y);
float nextafterf(float x, float y);
long double nextafterl(long double x, long double y);

// nexttoward.c
double nexttoward(double x, long double y);
float nexttowardf(float x, long double y);
long double nexttowardl(long double x, long double y);

// fdim.c
double fdim(double x, double y);
float fdimf(float x, float y);
long double fdiml(long double x, long double y);

// fmax.c
double fmax(double x, double y);
float fmaxf(float x, float y);
long double fmaxl(long double x, long double y);

// fmin.c
double fmin(double x, double y);
float fminf(float x, float y);
long double fminl(long double x, long double y);

// fma.c
double fma(double x, double y, double z);
float fmaf(float x, float y, float z);
long double fmal(long double x, long double y, long double z);


#if FLT_EVAL_METHOD == 0
typedef float float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 1
typedef double float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 2
typedef long double float_t;
typedef long double double_t;
#endif

#define HUGE_VAL  (__builtin_huge_val())
#define HUGE_VALF (__builtin_huge_valf())
#define HUGE_VALL (__builtin_huge_vall())
#define INFINITY  (__builtin_inff())
#define NAN       (__builtin_nanf(""))

#define FP_NAN       0
#define FP_INFINITE  1
#define FP_ZERO      2
#define FP_SUBNORMAL 3
#define FP_NORMAL    4

#ifdef __FP_FAST_FMA
# define FP_FAST_FMA 1
#endif
#ifdef __FP_FAST_FMAF
# define FP_FAST_FMAF 1
#endif
#ifdef __FP_FAST_FMAL
# define FP_FAST_FMAL 1
#endif

#define FP_ILOGB0   (-2147483647 - 1)
#define FP_ILOGBNAN (-2147483647 - 1)

#define MATH_ERRNO     1
#define MATH_ERREXCEPT 2

#define math_errhandling (MATH_ERRNO | MATH_ERREXCEPT)

#define fpclassify(x) __builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL, \
    FP_SUBNORMAL, FP_ZERO, x)
#define isfinite __builtin_isfinite
#define isinf    __builtin_isinf
#define isnan    __builtin_isnan
#define isnormal __builtin_isnormal
#define signbit  __builtin_signbit

#endif
