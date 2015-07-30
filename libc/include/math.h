#ifndef LIBC_MATH_H
#define LIBC_MATH_H



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

// Trigonometric functions
#define acos  __builtin_acos
#define acosf __builtin_acosf
#define acosl __builtin_acosl

#define asin  __builtin_asin
#define asinf __builtin_asinf
#define asinl __builtin_asinl

#define atan  __builtin_atan
#define atanf __builtin_atanf
#define atanl __builtin_atonl

#define cos  __builtin_cos
#define cosf __builtin_cosf
#define cosl __builtin_cosl

#define sin  __builtin_sin
#define sinf __builtin_sinf
#define sinl __builtin_sinl

#define tan  __builtin_tan
#define tanf __builtin_tanf
#define tanl __builtin_tanl

// Hyperbolic functions
#define acosh  __builtin_acosh
#define acoshf __builtin_acoshf
#define acoshl __builtin_acoshl

#define asinh  __builtin_asinh
#define asinhf __builtin_asinhf
#define asinhl __builtin_asinhl

#define atanh  __builtin_atanh
#define atanhf __builtin_atanhf
#define atanhl __builtin_atanhl

#define cosh  __builtin_cosh
#define coshf __builtin_coshf
#define coshl __builtin_coshl

#define sinh  __builtin_sinh
#define sinhf __builtin_sinhf
#define sinhl __builtin_sinhl

#define tanh  __builtin_tanh
#define tanhf __builtin_tanhf
#define tanhl __builtin_tanhl

// Exponential and logarithmic functions
#define exp  __builtin_exp
#define expf __builtin_expf
#define expl __builtin_expl

#define exp2  __builtin_exp2
#define exp2f __builtin_exp2f
#define exp2l __builtin_exp2l

#define expm1  __builtin_expm1
#define expm1f __builtin_expm1f
#define expm1l __builtin_expm1l

#define frexp  __builtin_frexp
#define frexpf __builtin_frexpf
#define frexpl __builtin_frexpl

#define ilogb  __builtin_ilogb
#define ilogbf __builtin_ilogbf
#define ilogbl __builtin_ilogbl

#define ldexp  __builtin_ldexp
#define ldexpf __builtin_ldexpf
#define ldexpl __builtin_ldexpl

#define log  __builtin_log
#define logf __builtin_logf
#define logl __builtin_logl

#define log10  __builtin_log10
#define log10f __builtin_log10f
#define log10l __builtin_log10l

#define log1p  __builtin_log1p
#define log1pf __builtin_log1pf
#define log1pl __builtin_log1pl

#define logb  __builtin_logb
#define logbf __builtin_logbf
#define logbl __builtin_logbl

#define modf  __builtin_modf
#define modff __builtin_modff
#define modfl __builtin_modfl

#define scalbn  __builtin_scalbn
#define scalbnf __builtin_scalbnf
#define scalbnl __builtin_scalbnl
#define scalbln  __builtin_scalbln
#define scalblnf __builtin_scalblnf
#define scalblnl __builtin_scalblnl

// Power and absolute-value functions
#define cbrt  __builtin_cbrt
#define cbrtf __builtin_cbrtf
#define cbrtl __builtin_cbrtl

#define fabs  __builtin_fabs
#define fabsf __builtin_fabsf
#define fabsl __builtin_fabsl




#endif
