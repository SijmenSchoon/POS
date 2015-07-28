#ifndef KERNEL_VGA_H
#define KERNEL_VGA_H

#include <stddef.h>
#include <stdint.h>

enum vga_color
{
    COLOR_BLACK         = 0,
    COLOR_BLUE          = 1,
    COLOR_GREEN         = 2,
    COLOR_CYAN          = 3,
    COLOR_RED           = 4,
    COLOR_MAGENTA       = 5,
    COLOR_BROWN         = 6,
    COLOR_LIGHT_GREY    = 7,
    COLOR_DARK_GREY     = 8,
    COLOR_LIGHT_BLUE    = 9,
    COLOR_LIGHT_GREEN   = 10,
    COLOR_LIGHT_CYAN    = 11,
    COLOR_LIGHT_RED     = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN   = 14,
    COLOR_WHITE         = 15
};

inline uint8_t vga_make_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

inline uint16_t vga_make_entry(char c, uint8_t color)
{
    return (uint16_t)c | (uint16_t)color << 8;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

static uint16_t *const VGA_MEMORY = (uint16_t *)0xB8000;

#endif
