#ifndef LIBC_ASSERT_H
#define LIBC_ASSERT_H

#ifdef NDEBUG
# define assert(expr) ((void)0)
#else
# define S(x) #x
# define S_(x) S(x)
# define assert(expr) { if (!expr) { \
    printf("assert(%s) failed in file %s, function %s, line %s\n", S_(expr), \
    __FILE__, __func__, S_(__LINE__)); abort(); } }
#endif

#endif
