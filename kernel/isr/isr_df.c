#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_double_fault_handler() {
	terminal_setcolor(VGA_COLOR_RED);
	terminal_writestring("\n============\nDouble FAULT\n============\n");
	for(;;)
		asm volatile("hlt\n");
}
