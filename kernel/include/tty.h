// #include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <include/kspin.h>

/* Check if the compiler thinks you are targeting the wrong operating system. */
// #if defined(__linux__)
// #error "You are not using a cross-compiler, you will most certainly run into trouble"
// #endif

/* Hardware text mode color constants. */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t strlen(const char* str);
void terminal_initialize(void);
void terminal_enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void terminal_disable_cursor();
void terminal_setcolor_nolock(uint8_t color);
void terminal_setcolor(uint8_t color);
void terminal_setcursor(uint8_t x, uint8_t y);
void terminal_scroll();
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_putchar_nolock(char c);
void terminal_write(const char* data, size_t size);
void terminal_lock_vga();
void terminal_unlock_vga();
void terminal_clear_nolock();
void terminal_clear();
void terminal_writestring_nolock(const char* data);
void terminal_writestring(const char* data);
void kprintf(char* format, ...);
