#include <stdint.h>
#include <include/tty.h>
#include <include/idt.h>

extern void do_test();

void kernel_main() {

	/* Initialize terminal interface */
	terminal_initialize();
	loadIDT();
	
	//kprintf("TEST %p\n", "test");
	kprintf("_idt           %p\n", _idt);
	kprintf("idtDescriptor  %p\n", idtDescriptor);
	kprintf("&idtDescriptor %p\n", &idtDescriptor);
	kprintf("_loadIDT       %p\n", _loadIDT);

	terminal_putchar('\n');
	kprintf("irq        %p\n", &irq0);
	terminal_putchar('\n');
	//irq0_handler();
	//irq0();
	terminal_putchar('\n');
	
	kprintf("offset_1   0x%x\n", _idt[0].offset_1);
	kprintf("selector   0x%x\n", _idt[0].selector);
	kprintf("ist        0x%x\n", _idt[0].ist);
	kprintf("type_attr  0x%x\n", _idt[0].type_attr);
	kprintf("offset_2   0x%x\n", _idt[0].offset_2);
	kprintf("offset_3   0x%x\n", _idt[0].offset_3);
	kprintf("zero       0x%x\n", _idt[0].zero);

	asm("sti\n");
	asm("hlt\n");

	for(;;);

	for(int i = 0;; i++)
		kprintf("%d\n", i);
}
