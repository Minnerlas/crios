#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../../tty.h"
#include "../../kspin.h"
#include "../../../libc/string.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

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
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
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

void terminal_putchar(char c) {
	if(c == '\n') {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT) {
			terminal_scroll();
			terminal_row = VGA_HEIGHT - 1;
		}
		//terminal_row = (terminal_row + 1) % VGA_HEIGHT;
	} else {
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT)
				terminal_row = VGA_HEIGHT - 1;
			terminal_scroll();
		}
	}
}

void terminal_write(const char* data, size_t size) {
	lock_spin_mutex(&VGA_lock);
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
	unlock_spin_mutex(&VGA_lock);
}

// void terminal_writestring(const char* data) {
// 	terminal_write(data, strlen(data));
// }

void terminal_lock_vga() {
	lock_spin_mutex(&VGA_lock);
}

void terminal_unlock_vga() {
	unlock_spin_mutex(&VGA_lock);
}

void terminal_writestring_nolock(const char* data) {
	for(; *data; terminal_putchar(*data++));
}

void terminal_writestring(const char* data) {
	lock_spin_mutex(&VGA_lock);
	for(; *data; terminal_putchar(*data++));
	unlock_spin_mutex(&VGA_lock);
}
