#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "tty.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void) {
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	//for(int i = 0; i<28; i++) {
	//	terminal_putchar(i/10+'0');
	//	terminal_putchar(i%10+'0');
	//	terminal_putchar('\n');
	//	terminal_writestring(" Hello, kernel World! test \ntest test\n");
	//}
	//
	for(int i = 0; i<28; i++) {
		kprintf("%d\n Hello, kernel World! test \ntest test%d\n", i, i);
	}

	terminal_writestring("Ovo je test\n");
	kprintf("TEST %d\n", 42);
	kprintf("TEST %p\n", "test");
	
}
