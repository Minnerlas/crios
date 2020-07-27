#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_general_protection_handler() {
	terminal_setcolor(VGA_COLOR_RED);
	terminal_writestring(	"\n========================\nGeneral Protection FAULT\n========================\n");
}
