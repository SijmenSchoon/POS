#ifndef KERNEL_TTY_H
#define KERNEL_TTY_H

#include <stddef.h>

void terminal_initialize();
void terminal_put_char(char c);
void terminal_scroll(int amount);
void terminal_write(const char *data, size_t length);
void terminal_write_string(const char *str);

#endif
