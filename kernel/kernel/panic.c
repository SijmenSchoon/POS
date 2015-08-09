#include <panic.h>
#include <tty.h>

void panic(const char *message)
{
    terminal_fill(0, 9, VGA_WIDTH, 10, vga_make_color(COLOR_WHITE, COLOR_BLUE));
    terminal_set_pos(0, 10);
    printf("Something happened\n\n");
    printf("Kernel panic:\n  %s\n", message);
    printf("eax = 0xdeadbeef    ebx = 0xfeedcafe    ecx = 0xdeafbabe    edx = 0x13371337\n")
}
