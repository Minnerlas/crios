#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_general_protection_handler() {
	terminal_setcolor_nolock(VGA_COLOR_RED);
	terminal_writestring_nolock(	"\n========================\nGeneral Protection FAULT\n========================\n");
	terminal_disable_cursor();
	disable_interrupts();
	for(;;)
		asm volatile ("hlt\n");
}
