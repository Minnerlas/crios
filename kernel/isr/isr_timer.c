#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>

static int a = 0;

void irq_timer_handler() {
	//terminal_putchar('.');
	if(!a) {
		terminal_putentryat(' ', (VGA_COLOR_BLUE | VGA_COLOR_BLACK << 4), VGA_WIDTH-1, 0);
		a = 1;
	} else { 
		terminal_putentryat(' ', (VGA_COLOR_BLACK | VGA_COLOR_BLUE << 4), VGA_WIDTH-1, 0);
		a = 0;
	}
	outb(PIC1_COMMAND, PIC_EOI);
}
