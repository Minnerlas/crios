#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_timer_handler() {
	//kprintf("char 0x%x    ", a);
	terminal_putchar('.');
	outb(PIC1_COMMAND, PIC_EOI);
}
