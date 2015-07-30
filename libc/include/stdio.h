#ifndef LIBC_STDIO_H
#define LIBC_STDIO_H

#include <stddef.h>
#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C"
{
#endif

int printf(const char *restrict format, ...);
int putchar(int c);
int puts(const char *s);

typedef size_t FILE;
typedef size_t fpos_t;

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define EOF (-1)

#define BUFSIZ 8192

#define FOPEN_MAX    16
#define FILENAME_MAX 4096
#define TMP_MAX      238328
#define L_tmpnam     20

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#ifdef __cplusplus
}
#endif

#endif
