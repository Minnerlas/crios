#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_double_fault_handler() {
	terminal_setcolor(VGA_COLOR_RED);
	terminal_writestring_nolock("\n============\nDouble FAULT\n============\n");
	terminal_disable_cursor();
	disable_interrupts();
	for(;;)
		asm volatile("hlt\n");
}
