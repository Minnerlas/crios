#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <include/tty.h>
#include <include/kspin.h>
#include <include/io.h>

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#define VGA_BUFFER ((uint16_t*) 0xB8000)

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}

// static const size_t VGA_WIDTH = 80;
// static const size_t VGA_HEIGHT = 25;

spin_mutex VGA_lock;
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void) {
	VGA_lock = 0;
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_BUFFER;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_lock_vga() {
	lock_spin_mutex(&VGA_lock);
}

void terminal_unlock_vga() {
	unlock_spin_mutex(&VGA_lock);
}

void terminal_setcolor(uint8_t color) {
	terminal_lock_vga();
	terminal_color = color;
	terminal_unlock_vga();
}

void terminal_setcursor(uint8_t x, uint8_t y) {
	uint16_t pos = y * VGA_WIDTH + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void terminal_scroll() {
	size_t x, y;
	for(y = 0; y < VGA_HEIGHT - 1; y++)
		for(x = 0; x < VGA_WIDTH; x++) {
			size_t ind1 = y * VGA_WIDTH + x;
			size_t ind2 = (y + 1) * VGA_WIDTH + x;
			terminal_buffer[ind1] = terminal_buffer[ind2];
		}
	for(x = 0; x < VGA_WIDTH; x++) {
		size_t ind = y * VGA_WIDTH + x;
		terminal_buffer[ind] = vga_entry(' ', terminal_color);
	}
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar_nolock(char c) {
	if(c == 0)
		return;
	if(c == '\n') {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT) {
			terminal_scroll();
			terminal_row = VGA_HEIGHT - 1;
		}
	} else {
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT) {
				terminal_scroll();
				terminal_row = VGA_HEIGHT - 1;
			}
		}
	}
	terminal_setcursor(terminal_column, terminal_row);
}

void terminal_putchar(char c) {
	terminal_lock_vga();
	terminal_putchar_nolock(c);
	terminal_unlock_vga();
}

void terminal_write(const char* data, size_t size) {
	terminal_lock_vga();
	for (size_t i = 0; i < size; i++)
		terminal_putchar_nolock(data[i]);
	terminal_unlock_vga();
}

// void terminal_writestring(const char* data) {
// 	terminal_write(data, strlen(data));
// }

void terminal_writestring_nolock(const char* data) {
	for(; *data; terminal_putchar_nolock(*data++));
}

void terminal_writestring(const char* data) {
	terminal_lock_vga();
	for(; *data; terminal_putchar_nolock(*data++));
	terminal_unlock_vga();
}

void terminal_clear_nolock() {
	terminal_row = 0;
	terminal_column = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
	terminal_setcursor(terminal_column, terminal_row);
};

void terminal_clear() {
	terminal_lock_vga();
	terminal_clear_nolock();
	terminal_unlock_vga();
};
