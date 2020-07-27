#include <include/isr.h>
#include <include/tty.h>
#include <include/kernel.h>
#include <include/kbd_lookup.h>

void irq_kbd_handler() {
	int8_t a = inb(0x60);

	if(a >= 0 && a <= 0x39)
		terminal_putchar(kbd_lookup_sc1[(size_t)a]);

	//kprintf("\n%d\n", a);
	
	outb(PIC1, 0x20);
	outb(PIC2, 0x20);
}
