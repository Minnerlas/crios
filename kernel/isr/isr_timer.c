#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_timer_handler() {
	//terminal_putchar('.');
	outb(PIC1_COMMAND, PIC_EOI);
}
