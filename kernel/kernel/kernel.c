#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>

void kernel_early()
{
    terminal_initialize();
}

void foo(const char* str)
{
	char buffer[16];
	memcpy(buffer, str, sizeof(buffer));
    printf("Still alive!\n");
}

void kernel_main()
{
    printf("Hello %s%c!\n", "worl", 'd');
    char buffer[12];
    foo(buffer);
}
