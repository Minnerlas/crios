#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

void irq_double_fault_handler() {
	terminal_putchar_nolock('D');
	terminal_putchar_nolock('D');
	terminal_putchar_nolock('D');
	terminal_putchar_nolock('D');
	terminal_putchar_nolock('D');
	for(;;);
}
