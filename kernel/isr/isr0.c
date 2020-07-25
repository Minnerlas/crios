#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq0_handler() {
	//inb(0x60);
	terminal_putchar('.');
	//outb(0x20, 0x20);
	//outb(0xa0, 0x20);
}
