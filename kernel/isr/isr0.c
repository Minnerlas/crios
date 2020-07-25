#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq0_handler() {
	char a = inb(0x60);
	//terminal_putchar('.');
	//terminal_putchar(a);
	kprintf("char 0x%x    ", a);
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}
