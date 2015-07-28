#include <stddef.h>
#include <stdint.h>

#include <kernel/vga.h>
#include <kernel/tty.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t *terminal_buffer;

void terminal_initialize()
{
    // Set variable defaults
    terminal_column = 0;
    terminal_row = 0;
    terminal_color = vga_make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    terminal_buffer = VGA_MEMORY;

    // Clear the screen
    for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (size_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = y*VGA_WIDTH + x;
            terminal_buffer[index] = vga_make_entry(' ', terminal_color);
        }
    }
}

void terminal_set_color(uint8_t color)
{
    terminal_color = color;
}

void terminal_put_entry_at(char c, uint8_t color, size_t x, size_t y)
{
    VGA_MEMORY[y*VGA_WIDTH + x] = vga_make_entry(c, color);
}

void terminal_put_char(char c)
{
    switch (c)
    {
    case '\n':
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT)
        {
            terminal_scroll(1);
            terminal_row--;
        }
        break;

    default:
        terminal_put_entry_at(c, terminal_color, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH)
        {
            terminal_column = 0;
            if (++terminal_row == VGA_HEIGHT)
            {
                terminal_scroll(1);
                terminal_row--;
            }
        }
    }
}

void terminal_write(const char *data, size_t length)
{
    for (size_t i = 0; i < length; i++)
        terminal_put_char(data[i]);
}

void terminal_write_string(const char *str)
{
    while (*str)
    {
        terminal_put_char(*str++);
    }
}

void terminal_scroll(int amount)
{
    while (amount--)
    {
        size_t i;
        for (i = 0; i < VGA_WIDTH*(VGA_HEIGHT - 1); i++)
        {
            VGA_MEMORY[i] = VGA_MEMORY[i + VGA_WIDTH];
        }
        for (; i < VGA_WIDTH*VGA_HEIGHT; i++)
        {
            VGA_MEMORY[i] = ' ';
        }
    }
}
