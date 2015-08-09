#ifndef KERNEL_TTY_H
#define KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>
#include <kernel/vga.h>

void terminal_initialize();
void terminal_put_char(char c);
void terminal_scroll(int amount);
void terminal_write(const char *data, size_t length);
void terminal_write_string(const char *str);
void terminal_set_color(uint8_t color);
void terminal_set_pos(size_t x, size_t y);
void terminal_fill(size_t x, size_t y, size_t w, size_t h, uint8_t color);

#endif
